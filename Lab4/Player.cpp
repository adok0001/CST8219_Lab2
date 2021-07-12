/******************************************
FILE: Player.cpp
PURPOSE: Defines Player class functions and constructors
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;
using namespace CST8219;

Player::Player(string name, int points, bool isCurrentPlayer){
	setPlayer(name, points, isCurrentPlayer);
}

/************************************************************
* Function name: printPlayer
* Purpose: prints the attributes of a player
* Return value: void
**************************************************************/
void Player::printPlayer() {
	cout << "Player Name: " << name << " - Points: " << points;
	if (isCurrentPlayer) cout << " - Current Player **  ";
	cout << endl;
}

void Player::setPlayer(string n, int p, bool isCurrent)
{
	setName(n);
	setPoints(p);
	setCurrentPlayer(isCurrent);
}

bool Player::getCurrentPlayer() {
	return isCurrentPlayer;
}

void Player::setName(string n) {
	name = n;
}

void Player::setPoints(int p) {
	points = p;
}

int Player::getPoints() {
	return points;
}

void CST8219::Player::setCurrentPlayer(bool isCurrent)
{
	isCurrentPlayer = isCurrent;
}

Player::Player(const Player& copy) {
	setPlayer(copy.name, copy.points, copy.isCurrentPlayer);
}

Player::Player(Player* copy) {
	setPlayer(copy->name, copy->points, copy->isCurrentPlayer);
}

//overloaded equality operator
bool CST8219::Player::operator==(const Player& p)
{
	return (name == p.name && points == p.points && isCurrentPlayer == p.isCurrentPlayer);
}
//overloaded inequality operator
bool CST8219::Player::operator!=(const Player& p)
{
	return !(name == p.name && points == p.points && isCurrentPlayer == p.isCurrentPlayer);

}
//overloaded prefix increment operator
Player CST8219::Player::operator++()
{
	++points;
	return Player(this);
}
//overloaded postfix increment operator
Player CST8219::Player::operator++(int)
{
	Player temp(this);
	points++;
	return temp;
}
