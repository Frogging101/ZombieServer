#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	float x;
	float y;
	float z;
	float yaw;
	int id;

public:
	Player::Player(float x, float y, float z, int id);
};

#endif