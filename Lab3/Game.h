/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;
const double NO_TIMEOUT(-1);

namespace CST8219 {
#pragma once
	class Game {
		friend ostream& operator << (ostream&, const Game&);
		friend istream& operator >> (istream&, Game& g);
	private:
		//class properties
		string name;
		int numPlayers;
		double timeout;
		vector<Player> playersList;

	public:
		//constructor declarations + destructor
		Game(string, int, double);
		Game(string, int);
		Game(string);
		Game();
		Game(Game*);
		~Game() {}
		//function declarations
		void printGame();
		Game createOneGame(Game); 
		void createMultipleGames(vector<Game>);
		void createPlayer();
		void listPlayers();
		//Getters 
		void getGame(string, int, double);
		string getName();
		int getNumPlayers();
		double getTimeout();
		//Setters
		Game setGame(string, int, double);
		void setName(string);
		void setNumPlayers(int);
		void setTimeout(double);
		//
		Game operator=(const Game&);
		bool operator==(const Game&);
		bool operator!=(const Game&);

		
	};


}



