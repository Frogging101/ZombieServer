#include "Player.h"
#include <iostream>

Player login(Player *players){
	for(int i=0;i<64;i++){
		if(&players[i] == NULL)
			players[i] = Player(0,0,0,i);
	}
	return *players;
}