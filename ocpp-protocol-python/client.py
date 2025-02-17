from ocpp.v16 import ChargePoint as cp
from ocpp.v16 import call
import logging
import asyncio
import websockets

logging.basicConfig(level=logging.INFO)

class ChargePointClient(cp):
    async def on_connect(self):
        logging.info(f"Connected to central system as {self.id}")
        await self.send_boot_notification()

    async def send_boot_notification(self):
        request = call.BootNotification(
            charge_point_model="EV-Charger-123",
            charge_point_vendor="Chaji"
        )

        response = await self.call(request)

        if response.status == "Accepted":
            logging.info("BootNotification accepted.")
        else:
            logging.warning("BootNotification rejected.")

async def connect_to_central_system():
    uri = "ws://localhost:9000/CP_123"  # Replace with your OCPP server address
    async with websockets.connect(uri) as ws:
        charge_point = ChargePointClient("CP_123", ws)
        await charge_point.on_connect()
        await charge_point.start()

if __name__ == "__main__":
    asyncio.run(connect_to_central_system())