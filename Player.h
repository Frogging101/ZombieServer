#ifndef PLAYER_H
#define PLAYER_H

#include <enet/enet.h>

class Player
{
public:
	float x;
	float y;
	float z;
	float yaw;
	int id;
	ENetPeer *peer;

	Player(float x, float y, float z, float yaw, int id, ENetPeer *peer);
	Player();
	void movePlayer(float x, float y, float z, float yaw);
};

#endif
