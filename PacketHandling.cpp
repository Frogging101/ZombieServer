#include "Player.h"
#include "main.h"
#include "PacketHandling.h"
#include <iostream>
#include <sstream>

using namespace std;

void login(ENetPeer *peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(players[i].id == -1){
			cout << "Connecting client with id " << i << endl;
			players[i] = Player(0,0,0,i,peer); 
			//packetData << "spawn " << i << 
			stringstream ss;
			ss << "spawn " << players[i].id << " 0 0 0 0";
			broadcast(ss.str(),players[i].peer);


			for(int j=0;j<MAXPLAYERS;j++){
				std::stringstream packetData;
				if(players[i].id != players[j].id && players[j].id != -1){
					cout << "send player spawn to new client" << endl;
					packetData << "spawn " << players[j].id << " " << players[j].x << " "
						<< players[j].y << " "<< players[j].z << " " << players[j].yaw;

					ENetPacket *spawnPacket = enet_packet_create(packetData.str().c_str(),
							packetData.str().length()+1,ENET_PACKET_FLAG_RELIABLE);

					enet_peer_send(players[i].peer,0,spawnPacket);
				}
			}
			enet_host_flush(server);
			break;
		}
	}
}

void broadcast(string data, ENetPeer *exclude){

	ENetPacket *packet = enet_packet_create(data.c_str(),data.length()+1,ENET_PACKET_FLAG_RELIABLE);
	
	for(int i=0;i<MAXPLAYERS;i++)
	{
		if(players[i].peer != exclude && players[i].id != -1){
			enet_peer_send(players[i].peer,0,packet);
		}
	}
}
