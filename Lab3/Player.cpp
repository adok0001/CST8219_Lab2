/******************************************
FILE: PLayer.h
PURPOSE: Defines Player class functions and constructors
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include<iostream>
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
	cout << "Player Name: " << name << "\nPlayer Points: " << points << endl;
	//printf("Player Name: %s\nPlayer Point: %d\n",name,points);
}

void Player::setPlayer(string n, int p, bool isCurrent)
{
	name = n;
	points = p;
	isCurrentPlayer = isCurrent;
	//return Player(n, p ,isCurrent);
}

Player::Player(const Player& copy) {
	//name = copy.name;
	//points = copy.points;
	//isCurrentPlayer = copy.isCurrentPlayer;
	////
	setPlayer(copy.name, copy.points, copy.isCurrentPlayer);
}

Player::Player(Player* copy) {
	/*this->name = copy->name;
	this->points = copy->points;
	this->isCurrentPlayer = copy->isCurrentPlayer;*/
	setPlayer(copy->name, copy->points, copy->isCurrentPlayer);
}

//overloaded equality operator
bool CST8219::Player::operator==(const Player& p)
{
	if (name == p.name && points == p.points)
		return true;
	return false;
}
//overloaded inequality operator
bool CST8219::Player::operator!=(const Player& p)
{
	if (name == p.name && points == p.points)
		return false;
	return true;
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
