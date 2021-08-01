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
	//template <class T> class PlayerT;
	//template <class T> ostream& operator<< (ostream&, const PlayerT<T>&);
	//template <class T> istream& operator>> (istream&, PlayerT<T>&);

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
			cout << "Enter player name: ";
			in >> p.name;
			//p.setCurrentPlayer(true);
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
		string getName();
		void setPlayer(string, T, bool);
		void setName(string);
		void setPoints(T);
		T getPoints();
		void setCurrentPlayer(bool);
		bool getCurrentPlayer(); // returns true or false for is Current
	};
}