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
}