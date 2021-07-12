/******************************************
FILE: Game.h
PURPOSE: Header file for Game Class
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;
const double NO_TIMEOUT(-1);

namespace CST8219 {
#pragma once
	/************************************************************
		* Class name : Game
		* Purpose : This class creates an instance of a game object with
		* attributes including players
		* Properties :
		* name = Name of the game
		* numPlayers = Number of players for a game instance
		* timeout = Duration of the game
		* playersList = List to store the players of a game
		* *************************************************************/
	class Game {
		friend ostream& operator << (ostream&, const Game&);
		friend istream& operator >> (istream&, Game&);
	private:
		//class properties
		string name;
		int numPlayers;
		double timeout;
		vector<Player> playersList;


	public:
		//constructor declarations + destructor
		Game(string name ="[NoName]", int nPlayers = 1, double duration = -1);
		Game(string, int);
		Game(string);
		Game();
		Game(Game*);
		~Game() {}
		//Utility functions
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
		vector<Player> getPLayersList();
		//Setters
		Game setGame(string, int, double);
		void setName(string);
		void setNumPlayers(int);
		void setTimeout(double);
		void setPlayersList(Player p);
		//Overloaded operators
		Game operator=(const Game&);
		bool operator==(const Game&);
		bool operator!=(const Game&);
		Game operator++();
		Game operator++(int);
		Game operator--();
		Game operator--(int);
		
	};

}



