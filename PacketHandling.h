#ifndef PACKETHANDLING_H
#define PACKETHANDLING_H

#include <iostream>

#include "Player.h"

void broadcast(std::string data, ENetPeer *exclude);
void login(ENetPeer *peer);
void logout();
void move();

#endif
