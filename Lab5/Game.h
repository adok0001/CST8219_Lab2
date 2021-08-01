/******************************************
FILE: Game.h
PURPOSE: Header file for Game Class
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>

#include "Player.h"

using namespace std;
const double NO_TIMEOUT(-1);

const int MAX_ATTEMPTS = 10; // (max turns to be attempted per game)
const int MAX_POINTS = 10; // (max points that each player can get per turn)
const double DEFAULT_TIMEOUT = 1000; // (limit timeout in microseconds).

namespace CST8219 {
#pragma once
	/************************************************************
		* Class name : GameT
		* Purpose : This class creates an instance of a game object with
		* attributes including players
		* Properties :
		* name = Name of the game
		* numPlayers = Number of players for a game instance
		* timeout = Duration of the game
		* playersList = List to store the players of a game
		* *************************************************************/
	template <class T> class GameT {
		//overloaded output stream
		friend ostream& operator<<(ostream& out, const GameT& g)
		{
			out << "\nName: " << g.name << " - Numplayers: " << g.numPlayers << " - Timeout: " << g.timeout;
			return out;
		}

		//overloaded input stream
		friend istream& operator>>(istream& in, GameT& g)
		{
			do {
				cout << "Enter the name of the game: ";
				in >> g.name;
				if (g.name.empty()) {
					cout << "\nName cannot be empty";
					in.clear();
				}
			} while (g.name.empty());

			do {
				cout << "Enter the number of players: ";
				in >> g.numPlayers;
				if (g.numPlayers < 1 || g.numPlayers > 10) {
					in.clear();
					cout << "\nNumber of players must be between 1-10 ";
				}

			} while (g.numPlayers < 1 || g.numPlayers > 10);

			// after setting number of PLayers createPLayers based on that number
			g.createPlayer();

			do {
				cout << "Enter the game duration: ";
				in >> g.timeout;
				if (g.timeout <= 0) {
					in.clear();
					cout << "Timeout cannot be a negative number\n";
				}

			} while (g.timeout <= 0);

			return in;
		}

		
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
		vector<PlayerT<T>> playersList; //List containing players in game

	public:
		//constructor declarations + destructor
		GameT(string name = "[No Name]", int nPlayers = 1, double duration = -1);
		GameT(GameT*);
		~GameT() {}
		//Virtual functions
		float virtual getLifeExpectancy() = 0; 
		virtual float getWinProbability() = 0;
		//Getters 
		inline string getName();
		inline int getNumPlayers();
		inline double getTimeout();
		inline int getCurrentPlayer();
		inline int getCurrentAttempt();
		inline int getCurrentTimeout();
		inline vector<PlayerT<T>> getPlayersList();
		void getGame(string, int, double);
		//Setters
		inline void setName(string);
		inline void setNumPlayers(int);
		inline void setTimeout(double);
		void setPlayersList(PlayerT<T> p);
		//void setGameType(GameType);
		void setGame(string, int, double);
		inline void setCurrentAttempt(int);
		void setCurrentPlayer(int);
		inline void setCurrentTimeout(double);
		//Overloaded operators
		inline PlayerT<T> getPlayer(int pos);
		inline GameT setPlayer(PlayerT<T> p, int pos);

	};

	//Classes
	template <class T>
	class ElectronicGameT : public GameT<T> {
	public:
		ElectronicGameT(string name = "Electronic", double timeout = DEFAULT_TIMEOUT);
		queue <T> pointsPerTurn;
		virtual float getLifeExpectancy();
		virtual float getWinProbability();
		void play();
		void showResults();
	};


	template <class T> class CompetitiveGameT : public GameT<T> {
	public:
		CompetitiveGameT(string gameName = "Competitive", int nPlayers = 4); //default constructor
		list <T> pointsPerPlayer; 
		virtual float getLifeExpectancy();
		virtual float getWinProbability();
		void play();
		void showResults();
	};

	template <class T> class MixedGameT : public ElectronicGameT<T>, CompetitiveGameT<T> {
	public:
		MixedGameT(string gameName = "Mixed", int nPlayers = 4, double timeout = DEFAULT_TIMEOUT);
		multimap <string, T> playerPointsMap;
		virtual float getLifeExpectancy();
		virtual float getWinProbability();
		void play();
		void showResults();
	};


}



