# This file implements a simplr CMS server for an ocpp protocol
# This is the backend that receives the messages from charge point client

import asyncio
import logging
import websockets
from websockets.server import serve
from ocpp.routing import on
from ocpp.v16 import call_result
from ocpp.v16 import ChargePoint as cp
from ocpp.v16 import call

logging.basicConfig(level=logging.INFO)

class ChargePoint(cp):
    async def on_connect(self):
        logging.info(f"Charge Point {self.id} connected.")

    @on("BootNotification")
    async def on_boot_notification(self, charge_point_model, charge_point_vendor, **kwargs):
        logging.info(f"Received BootNotification from {self.id}: Model={charge_point_model}, Vendor={charge_point_vendor}")
        return call_result.BootNotification(
            current_time="2025-02-17T12:00:00Z",
            interval=10,
            status="Accepted"
        )

    @on("Heartbeat")
    async def on_heartbeat(self):
        logging.info(f"Heartbeat received from {self.id}")
        return call_result.HeartbeatPayload(
            current_time="2025-02-17T12:00:00Z"
        )

    @on("Authorize")
    async def on_authorize(self, id_tag):
        logging.info(f"Authorization request for ID tag {id_tag}")
        return call_result.AuthorizePayload(id_tag_info={"status": "Accepted"})

async def on_new_connection(websocket, path):
    charge_point_id = path.strip("/")
    charge_point = ChargePoint(charge_point_id, websocket)

    await charge_point.start()

async def main():
    server = await serve(on_new_connection, "127.0.0.1", 9000)
    logging.info("OCPP 1.6 Central System started on ws://127.0.0.1:9000")
    await server.wait_closed()

if __name__ == "__main__":
    asyncio.run(main())