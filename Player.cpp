#include <iostream>

#include "Player.h"
#include "main.h"

Player::Player(float x, float y, float z, int id, ENetPeer peer){
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
}

Player::Player(){
	this->id = -1;
}

void Player::movePlayer(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;

	for(int i=0;i<MAXPLAYERS;i++){
		//if(players[i].
	}
}