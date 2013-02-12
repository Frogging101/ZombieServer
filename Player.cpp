#include <iostream>
#include <sstream>

#include "Player.h"
#include "PacketHandling.h"
#include "main.h"

using namespace std;

Player::Player(float x, float y, float z, int id, ENetPeer *peer){
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
	this->peer = peer;
}

Player::Player(){
	this->id = -1;
}

void Player::movePlayer(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
	stringstream ss;

	ss << "move " << this->id << " " << x << 
		" " << y << " " << z << " " << yaw;

	broadcast(ss.str(),this->peer);
}