#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	float x;
	float y;
	float z;
	float yaw;
	int id;

	Player::Player(float x, float y, float z, int id);
	Player::Player();
};

#endif