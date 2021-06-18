/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
#include <vector>

using namespace std;

namespace CST8219 {
	#pragma once
	class Player {
	private:
		string name; // Game player name
		int points; // Current points
		bool isCurrentPlayer; // Indicates if he/she is the current player
		vector<Player> playersList;

	public:
		//Player();
		Player(string name = "[Noname]", int points = 0, bool isCurrentPlayer = false);
		void printPlayer();
		Player setPlayer(string, int, bool);
		Player(const Player& copy);
		Player(Player* copy);
		//
		bool operator==(const Player&);
		bool operator!=(const Player&);
		Player operator++();
		Player operator++(int);
	};
}