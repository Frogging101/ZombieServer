#include "Player.h"
#include "main.h"
#include <iostream>
#include <sstream>

using namespace std;

void login(ENetPeer *peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(players[i].id == -1){
			players[i] = Player(0,0,0,i,peer);
			//packetData << "spawn " << i << 


			for(int j=0;j<MAXPLAYERS;j++){
				std::stringstream packetData;
				if(players[i].id != players[i].id){
					packetData << players[i].id << players[i].x << players[i].y
						<< players[i].z << players[i].yaw;

					ENetPacket *spawnPacket = enet_packet_create(packetData.str().c_str(),
							packetData.str().length()+1,ENET_PACKET_FLAG_RELIABLE);

					enet_peer_send(players[i].peer,0,spawnPacket);
					enet_host_flush(server);
				}
			}
			break;
		}
	}
}

void broadcast(string data, ENetPeer *exclude){

	ENetPacket *packet = enet_packet_create(data.c_str(),strlen(data.c_str())+1,0);
	
	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(players[i].peer != exclude && players[i].id != -1){
			enet_peer_send(players[i].peer,0,packet);
		}
	}
}
