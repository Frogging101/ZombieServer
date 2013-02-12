#define WIN32

#include <enet/enet.h>
#include <iostream>
#include <sstream>

#include "Player.h";
#include "PacketHandling.h"

using namespace std;

Player *players[64];
void handlePacket(string packetData);

enum{
	pLogin,
	pLogout,
	pMove
};

int main(int argc, char **argv){
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
		while (enet_host_service (server, &event, 1000) > 0)
		{
			switch (event.type)
			{
			case ENET_EVENT_TYPE_CONNECT:
				handlePacket("login");
				break;
			case ENET_EVENT_TYPE_RECEIVE:
				handlePacket((char*)event.packet->data);
				break;
	   
			case ENET_EVENT_TYPE_DISCONNECT:
				printf ("%s disconected.\n", event.peer -> data);
				/* Reset the peer's client information. */
				event.peer -> data = NULL;
			}
		}
	}
}

int enumPacketType(string text){ //text is the packet type text{
	if(text == "login") return pLogin;
	if(text == "logout") return pLogout;
	if(text == "move") return pMove;
}

void handlePacket(string packetData){
	stringstream ss;
	string packetTypeStr;
	int packetType;	

	ss << packetData; //Store the whole packetData in ss
	ss >> packetTypeStr;
	
	packetType = enumPacketType(packetTypeStr);

	switch(packetType){
		case pLogin:
			cout << "Login packet received" << endl;
			login(*players);
			break;

		case pLogout:
			//logout
			break;

		case pMove:
			//move
			break;
	}
}