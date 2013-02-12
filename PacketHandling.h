#ifndef PACKETHANDLING_H
#define PACKETHANDLING_H

#include "Player.h"

void login(Player players[],ENetPeer peer);
void logout(Player players);
void move();

#endif