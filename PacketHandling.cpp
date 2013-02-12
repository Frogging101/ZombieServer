#include "Player.h"
#include "main.h"
#include <iostream>

void login(ENetPeer peer){
	for(int i=0;i<MAXPLAYERS;i++){
		if(players[i].id == -1){
			players[i] = Player(0,0,0,i,peer);
		}
	}
}