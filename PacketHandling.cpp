#include "Player.h"
#include "main.h"
#include <iostream>

using namespace std;

void login(ENetPeer peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(players[i].id == -1){
			players[i] = Player(0,0,0,i,peer);
		}
	}
}

void broadcast(string data, ENetPeer *exclude){

	ENetPacket *packet = enet_packet_create(data.c_str(),strlen(data.c_str())+1,0);
	
	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(players[i].peer != exclude){
			enet_peer_send(players[i].peer,0,packet);
		}
	}
}