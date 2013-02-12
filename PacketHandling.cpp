#include "Player.h"
#include "main.h"
#include <iostream>
#include <sstream>

void login(ENetPeer peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(players[i].id == -1){
			players[i] = Player(0,0,0,i,peer);
			//TODO send spawn packet to everyone else
			for(int j=0;j<MAXPLAYERS;j++){
				if(players[i].id != players[j].id){
					std::stringstream packetData;
					packetData << players[j].id << players[j].x << players[j].y
						<< players[j].z << players[j].yaw;
					ENetPacket *spawnPacket = enet_packet_create(packetData.str().c_str(),
							packetData.str().length()+1,ENET_PACKET_FLAG_RELIABLE);

					enet_peer_send(players[j].peer,0,spawnPacket); 
				}
			}
		}
	}
}
