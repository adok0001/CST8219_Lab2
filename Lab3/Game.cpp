/******************************************
FILE: Game.cpp
PURPOSE: Defines game class functions and constructors
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include<iostream>
#include <vector>
#include "Game.h"

using namespace std;
using namespace CST8219;

Game::Game(string name, int nPlayers, double duration) {
	setName(name);
	setNumPlayers(nPlayers);
	setTimeout(duration);
}
Game::Game(string name, int nPlayers): Game(name, nPlayers, -1) {}
Game::Game(string name) :Game(name, 1) {}
Game::Game():Game("[NoName]"){}
Game::Game(Game* g) {
	name = g->getName();
	numPlayers = g->getNumPlayers();
	timeout = g->getTimeout();
}

string Game::getName() {
	return name;
}

int Game::getNumPlayers() {
	return numPlayers;
}

double Game::getTimeout() {
	return timeout;
}

vector<Player> CST8219::Game::getPLayersList()
{
	return playersList;
}

void Game::getGame(string n, int p, double t)
{
	n = name;
	p = numPlayers;
	t = timeout;

}

Game Game::setGame(string n, int p, double t) {
	return Game(n,p,t);
}

void Game::setName(string n) {
	name = n;
}

void Game::setNumPlayers(int num) {
	numPlayers = num;
}

void Game::setTimeout(double t) {
	timeout = t;
}

void CST8219::Game::setPlayersList(Player p)
{
	playersList.push_back(p);
}

//overloaded assignment operator
Game CST8219::Game::operator=(const Game& g)
{
	name = g.name;
	numPlayers = g.numPlayers;
	timeout = g.timeout;

	return Game(name, numPlayers, timeout);
}

//overloaded equality operator
bool CST8219::Game::operator==(const Game& g)
{
	if (name == g.name && numPlayers == g.numPlayers && timeout == g.timeout)
		return true;
	return false;
}

//overloaded inequality operator
bool CST8219::Game::operator!=(const Game& g)
{
	if (name == g.name && numPlayers == g.numPlayers && timeout == g.timeout)
		return false;
	return true;
}

//overloaded prefix increment operator
Game CST8219::Game::operator++()
{
	++numPlayers;
	return Game(this);
}

//overloaded postfix increment operator
Game CST8219::Game::operator++(int)
{
	Game temp(this);
	numPlayers++;
	return temp;
}

//overloaded prefix decrement operator
Game CST8219::Game::operator--()
{
	--numPlayers;
	return Game(this);
}

//overloaded postfix decrement operator
Game CST8219::Game::operator--(int)
{
	Game temp(this);
	numPlayers--;
	return temp;
}

//overloaded output stream
ostream& CST8219::operator<<(ostream& out, const Game& g)
{
	out << "Name: " << g.name << " - Numplayers: " << g.numPlayers << " - Timeout: " << g.timeout << endl;
	return out;
}

//overloaded input stream
istream& CST8219::operator>>(istream& in, Game& g)
{

	do {
		cout << "Enter the name: ";
		cin >> g.name;
		if (g.name.empty()) {
			cout << "Name cannot be empty" << endl;
			cin.clear();
		}
	} while (g.name.empty());

	do {
		cout << "Enter the number of players: ";
		cin >> g.numPlayers;
		if (g.numPlayers < 1 || g.numPlayers > 10) {
			cin.clear();
			cout << "Number of players must be between 1-10 " << endl;
		}

	} while (g.numPlayers < 1 || g.numPlayers > 10);
	g.createPlayer();

	do {
		cout << "Enter the game duration: ";
		cin >> g.timeout;
		if (g.timeout <= 0) {
			cin.clear();
			cout << "Timeout cannot be a negative number\n";
		}

	} while (g.timeout <= 0);

	return in;
}

/************************************************************
* Function name: printGame
* Purpose: prints the attributes of a game
* Return value: void
**************************************************************/
void Game::printGame() {
	cout << "Name: " << name << " - Numplayers: " << numPlayers << " - Timeout: " << timeout << endl;
}

/************************************************************
* Function name: createOneGame
* Purpose: Creates a game based on user input
* Parameters:
* g = Game object to be initialized
* Return value: A game object
**************************************************************/
Game Game::createOneGame(Game g) {

	/*
	do {
		cout << "Enter the name: " << endl;
		cin >> name;
		if (name.empty()) {
			cout << "Name cannot be empty" << endl;
			cin.clear();
		}
	} while (name.empty());

	do {
		cout << "Enter the number of players" << endl;
		cin >> numPlayers;
		if (numPlayers < 1 || numPlayers > 10) {
			cin.clear();
			cout << "Number of players must be between 1-10 " << endl;
		}
		
	} while (numPlayers < 1 || numPlayers > 10);

	do {
		cout << "Enter the game duration" << endl;
		cin >> timeout;
		if (timeout <= 0) {
			cin.clear();
			cout << "Timeout cannot be a negative number\n";
		}

	} while (timeout <= 0);
	*/

	//g = Game(name, numPlayers, timeout);
	cin >> g;
	g.listPlayers();
	cout << g << endl;
	return g;

}

/************************************************************
* Function name: createMultipleGames
* Purpose: creates Games based on the user specified number
* Parameters:
* gameList = Vector of game type for game objects to be stored
* Return value: void
**************************************************************/
void Game::createMultipleGames(vector<Game> gameList) {

	int i, n;

	cout << "Enter number of games to be created: " << endl;
	cin >> n;

	for (i = 0; i < n; i++) {
		Game newGame = Game();
		gameList.push_back(newGame.createOneGame(newGame));
	}

	for (i = 0; i < n; i++) {
		gameList.at(i).printGame();
	}

}

/************************************************************
* Function name: createPlayer
* Purpose: creates player(s) for a game instance
* Return value: void
**************************************************************/
void Game::createPlayer()
{
	int i; string name;
	for (i = 0; i < numPlayers; i++) {
		std::cout << "Enter player name: ";
		std::cin >> name;
		Player p(name);
		setPlayersList(p);
	}

	for (i = 0; i < numPlayers; i++)
		getPLayersList().at(i).printPlayer();

}

/************************************************************
* Function name: listPlayers
* Purpose: List the players of a game
* Return value: void
**************************************************************/
void Game::listPlayers() {
	for (Player p : playersList)
		p.printPlayer();
}
