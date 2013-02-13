#include <iostream>
#include <sstream>

#include "Player.h"
#include "PacketHandling.h"
#include "main.h"

using namespace std;

Player::Player(float x, float y, float z, float yaw, int id, ENetPeer *peer){
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
	this->yaw = yaw;
	this->peer = peer;
}

Player::Player(){
	this->id = -1;
}

void Player::movePlayer(float x, float y, float z, float yaw){
	this->x = x;
	this->y = y;
	this->z = z;
	this->yaw = yaw;
	stringstream ss;

	ss << "move " << this->id << " " << x << 
		" " << y << " " << z << " " << yaw;

	broadcast(ss.str(),this->peer);
}