#define WIN32

#include <enet/enet.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	ENetAddress address;
	ENetHost *server;

	if (enet_initialize () != 0)
	{
		cout << "Error initializing enet";
		return EXIT_FAILURE;
	}
	atexit (enet_deinitialize);

	address.host = ENET_HOST_ANY;
	address.port = 340;

	server = enet_host_create(&address,10,2,0,0);

	if(server == NULL)
	{
		cout << "The server's broken";
		exit(EXIT_FAILURE);
	}

	ENetEvent event;

	while(true){

		/* Wait up to 1000 milliseconds for an event. */
		while (enet_host_service (server, &event, 1000) > 0)
		{
			switch (event.type)
			{
			case ENET_EVENT_TYPE_CONNECT:
				printf ("A new client connected from %x:%u.\n", 
						event.peer -> address.host,
						event.peer -> address.port);
				/* Store any relevant client information here. */
				event.peer -> data = "Client information";
				break;
			case ENET_EVENT_TYPE_RECEIVE:
				printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
						event.packet -> dataLength,
						event.packet -> data,
						event.peer -> data,
						event.channelID);

				/* Clean up the packet now that we're done using it. */
				enet_packet_destroy (event.packet);
				break;
	   
			case ENET_EVENT_TYPE_DISCONNECT:
				printf ("%s disconected.\n", event.peer -> data);
				/* Reset the peer's client information. */
				event.peer -> data = NULL;
			}
		}
	}
}