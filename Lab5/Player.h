/******************************************
FILE: Player.h
PURPOSE: Header file for Player class
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
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
	template <class T>
	class PlayerT {
		friend ostream& operator<< (ostream& out, const PlayerT& p) {
			out << "Player Name: " << p.name << " - Points: " << p.points << " - Current Player " << p.isCurrentPlayer;
			out << "\n";
			return out;
		}
		 
		friend istream& operator>> (istream& in, PlayerT& p) {
			T points=0;
			bool isCurrent;
			cout << "Player name: ";
			in >> p.name;
			do {
				cout << "Points: ";
				in >> points;
				if (points < 0)
					cout << "Points cannot be negative\n";
			} while (points < 0);
			p.setPoints(points);
			return in;
		}

	private:
		string name; // Player name
		T points; // Current points
		bool isCurrentPlayer; // Indicates if this is the current player

	public:
		//Constructors
		PlayerT(string name = "[Noname]", T points = 0, bool isCurrentPlayer = false);
		PlayerT(const PlayerT& copy);
		PlayerT(PlayerT* copy);
		//Setters & Getters
		inline string getName();
		inline void setPlayer(string, T, bool);
		inline void setName(string);
		inline void setPoints(T);
		inline T getPoints();
		inline void setCurrentPlayer(bool);
		inline bool getCurrentPlayer(); // returns true or false for is Current
	};
}