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

const int MAX_ATTEMPTS = 10; // (max turns to be attempted per game)
const int MAX_POINTS = 100; // (max points that each player can get per turn)
const int DEFAULT_TIMEOUT = 1000; // (limit timeout in microseconds).

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
		string name; //Name of the game
		int numPlayers; //Number of players in game
		double timeout; //Time limit for game
	
	protected:
		enum GameType { ELECTRONIC, COMPETITIVE, MIXED };
		int gameType; // (that maps the kinds of Game)
		int currentPlayer; // (that indicates the current player in Game);
		int currentAttempt; // (that indicates the current attempt / turn);
		int currentTimeout; // (that indicates the current time since the beginning of the game);
		vector<Player> playersList; //List containing players in game

	public:
		//constructor declarations + destructor
		Game(string name = "[No Name]", int nPlayers = 1, double duration = -1);
		Game(Game*);
		~Game() {}
		//Virtual functions
		virtual float getLifeExpectancy() = 0; 
		virtual float getWinProbability() = 0;
		virtual void start();
		//Utility functions
		void play();
		void printGame();
		inline void createPlayer();
		inline void listPlayers();
		//Getters 
		string getName();
		int getNumPlayers();
		double getTimeout();
		int getCurrentPlayer();
		int getCurrentAttempt();
		int getCurrentTimeout();
		int getGameType();
		vector<Player> getPlayersList();
		void getGame(string, int, double);
		//Setters
		void setName(string);
		void setNumPlayers(int);
		void setTimeout(double);
		void setPlayersList(Player p);
		void setGameType(GameType);
		void setGame(string, int, double);
		void setCurrentAttempt(int);
		void setCurrentPlayer(int);
		void setCurrentTimeout(int);

		
		//Overloaded operators
		Game operator=(const Game&);
		bool operator==(const Game&);
		bool operator!=(const Game&);
		
	};
	//Classes
	class ElectronicGame : public Game {
	public:
		ElectronicGame(string name = "Electronic", double timeout = DEFAULT_TIMEOUT);
		virtual float getLifeExpectancy();
		virtual float getWinProbability();
		//
		
		//

	};

	class CompetitiveGame : public Game {
	public:
		CompetitiveGame(string gameName = "Competitive", int nPlayers = 4);// , int currentAttempt = 1); //default constructor
		virtual float getLifeExpectancy();
		virtual float getWinProbability();

	};

	class MixedGame : public ElectronicGame, CompetitiveGame {
	public:
		MixedGame(string gameName = "Mixed", int nPlayers = 4, double timeout = DEFAULT_TIMEOUT);
		virtual float getLifeExpectancy();
		virtual float getWinProbability();
		
	};


}



