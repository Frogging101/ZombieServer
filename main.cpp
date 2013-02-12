#include <enet/enet.h>
#include <iostream>
#include <sstream>

#include "Player.h"
#include "PacketHandling.h"
#include "main.h"

using namespace std;

void handlePacket(string packetData, ENetPeer *peer);
int peerToId(ENetPeer *peer);
Player *players = new Player[MAXPLAYERS];
ENetHost *server;

enum{
	pLogin,
	pLogout,
	pMove
};

int main(int argc, char **argv){
	ENetAddress address;

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
				handlePacket("login",event.peer);
				break;
			case ENET_EVENT_TYPE_RECEIVE:
				handlePacket((char*)event.packet->data,event.peer);
				break;
	   
			case ENET_EVENT_TYPE_DISCONNECT:
				cout << event.peer->data << " disconnected" << endl;
				handlePacket("logout",event.peer);
			}
		}
	}
	delete[] players;
}

int enumPacketType(string text){ //text is the packet type text{
	if(text == "login") return pLogin;
	if(text == "logout") return pLogout;
	if(text == "move") return pMove;
}

void handlePacket(string packetData, ENetPeer *peer){
	stringstream ss;
	string packetTypeStr;
	int packetType;	

	ss << packetData; //Store the whole packetData in ss
	ss >> packetTypeStr;
	
	packetType = enumPacketType(packetTypeStr);

	switch(packetType){
		case pLogin:
			cout << "Login packet received" << endl;
			login(*peer);
			break;

		case pLogout:
			//logout
			break;

		case pMove:
			float x;
			float y;
			float z;
			float yaw;

			ss >> x >> y >> z >> yaw;
			players[peerToId(peer)].movePlayer(x,y,z);

			break;
	}
}

int peerToId(ENetPeer *peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(peer == players[i].peer)
			return players[i].id;
	}
	return -1;
}
