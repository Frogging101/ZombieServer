#include "Player.h"
#include <iostream>

void login(Player players[], ENetPeer peer){
	for(int i=0;i<64;i++){
		if(players[i].id == -1){
			players[i] = Player(0,0,0,i,peer);
		}
	}
}