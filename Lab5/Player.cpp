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

template<class T>
CST8219::PlayerT<T>::PlayerT(string name, T points, bool isCurrentPlayer)
{
	setPlayer(name, points, isCurrentPlayer);
}

template<class T>
void PlayerT<T>::setPlayer(string n, T p, bool isCurrent)
{
	setName(n);
	setPoints(p);
	setCurrentPlayer(isCurrent);
}

template<class T>
bool PlayerT<T>::getCurrentPlayer() {
	return isCurrentPlayer;
}

template<class T>
void PlayerT<T>::setName(string n) {
	name = n;
}

template<class T>
void PlayerT<T>::setPoints(T p) {
	points = p;
}

template<class T>
T PlayerT<T>::getPoints() {
	return points;
}

template<class T>
void CST8219::PlayerT<T>::setCurrentPlayer(bool isCurrent)
{
	isCurrentPlayer = isCurrent;
}

template<class T>
PlayerT<T>::PlayerT(const PlayerT& copy) {
	setPlayer(copy.name, copy.points, copy.isCurrentPlayer);
}

template<class T>
PlayerT<T>::PlayerT(PlayerT* copy) {
	setPlayer(copy->name, copy->points, copy->isCurrentPlayer);
}
