#include <iostream>

#include "Player.h"

Player::Player(float x, float y, float z, int id){
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
}

Player::Player(){
this->id = -1;
}