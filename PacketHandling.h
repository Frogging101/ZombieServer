#ifndef PACKETHANDLING_H
#define PACKETHANDLING_H

#include <iostream>

#include "Player.h"

void login(ENetPeer *peer);
void logout();
void move();
void broadcast(std::string data, ENetPeer *exclude);

#endif