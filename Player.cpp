#include <iostream>

#include "Player.h"

Player::Player(float x, float y, float z, int id, ENetPeer peer){
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
}

Player::Player(){
this->id = -1;
}