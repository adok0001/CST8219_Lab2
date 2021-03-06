/******************************************
FILE: Player.cpp
PURPOSE: Header file for Player class
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 ? 302]
******************************************/

#include <iostream>
#include <vector>

using namespace std;

namespace CST8219 {
	#pragma once
	/************************************************************
	* Class name : Players
	* Purpose : This class creates an instance of a player that
	* is playing a game
	* Properties :
	* name = Name of the Player
	* points = Current points
	* isCurrentPlayer = Indicates if he/she is the current player
	* *************************************************************/
	class Player {
	private:
		string name; // Game player name
		int points; // Current points
		bool isCurrentPlayer; // Indicates if he/she is the current player

	public:
		Player(string name = "[Noname]", int points = 0, bool isCurrentPlayer = false);
		void printPlayer();
		void setPlayer(string, int, bool);
		Player(const Player& copy);
		Player(Player* copy);
		//Overloaded Operators
		bool operator==(const Player&);
		bool operator!=(const Player&);
		Player operator++();
		Player operator++(int);
	};
}