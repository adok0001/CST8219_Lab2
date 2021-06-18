/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include<iostream>
#include <vector>
#include "Player.h"

using namespace std;
using namespace CST8219;

Player::Player(string name, int points, bool isCurrentPlayer){
	setPlayer(name, points, isCurrentPlayer);
}

void Player::printPlayer() {
	cout << "Player Name: " << name << "\nPlayer Points: " << points << endl;
	//printf("Player Name: %s\nPlayer Point: %d\n",name,points);
}

Player Player::setPlayer(string n, int p, bool isCurrent)
{
	name = n;
	points = p;
	isCurrentPlayer = isCurrent;
	return Player();
}

Player::Player(const Player& copy) {
	setPlayer(copy.name, copy.points, copy.isCurrentPlayer);
}

Player::Player(Player* copy) {
	/*this->name = copy->name;
	this->points = copy->points;
	this->isCurrentPlayer = copy->isCurrentPlayer;*/
	setPlayer(copy->name, copy->points, copy->isCurrentPlayer);
}

bool CST8219::Player::operator==(const Player&)
{

	return false;
}

bool CST8219::Player::operator!=(const Player&)
{
	return false;
}

Player CST8219::Player::operator++()
{
	return Player();
}

Player CST8219::Player::operator++(int)
{
	return Player();
}
