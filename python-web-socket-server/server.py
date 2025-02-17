import asyncio
import websockets

# Set of connected clients
connected_clients = set()

async def process_message(message):
    """Process the received message and return a response."""
    print(f"Received: {message}")
    
    # Example: Convert message to uppercase
    response = message.upper()
    
    return response

# Function to handle each client connection
async def handle_client(websocket, path=None):
    # Add the new client to the set of connected clients
    connected_clients.add(websocket)
    try:
        # Listen for messages from the client
        async for message in websocket:

            # Broadcast the message to all other connected clients
            # for client in connected_clients:
            #     if client != websocket:
            #         await client.send(message)
            response = await process_message(message)
            await websocket.send(response)

    except websockets.exceptions.ConnectionClosed:
        pass
    finally:
        # Remove the client from the set of connected clients
        connected_clients.remove(websocket)

# Main function to start the WebSocket server
async def main():
    server = await websockets.serve(handle_client, 'localhost', 8000)
    await server.wait_closed()

# Run the server
if __name__ == "__main__":
    asyncio.run(main())