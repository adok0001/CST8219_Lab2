/******************************************
FILE: Game.cpp
PURPOSE: Defines game class functions and constructors
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include<iostream>
#include <vector>
#include <chrono>
#include "Game.h"


using namespace std;
using namespace CST8219;

template <class T>
GameT<T>::GameT(string name, int nPlayers, double duration){
	setName(name);
	setNumPlayers(nPlayers);
	setTimeout(duration);
	currentAttempt = 0;
	currentTimeout = 0;
	currentPlayer = 0;
}

template <class T>
GameT<T>::GameT(GameT* g) {
	name = g->getName();
	numPlayers = g->getNumPlayers();
	timeout = g->getTimeout();
}

template <class T>
string GameT<T>::getName() {
	return name;
}

template <class T>
int GameT<T>::getNumPlayers() {
	return numPlayers;
}
template <class T>
double GameT<T>::getTimeout() {
	return timeout;
}
template <class T>
int CST8219::GameT<T>::getCurrentPlayer()
{
	int i; //iterator
	for (i = 0; i < playersList.size(); i++) {
		if (playersList.at(i).getCurrentPlayer()) return i;
	}
	return 0;
}
template <class T>
int CST8219::GameT<T>::getCurrentAttempt()
{
	return currentAttempt;
}
template <class T>
int CST8219::GameT<T>::getCurrentTimeout()
{
	return currentTimeout;
}
template <class T>
vector<PlayerT> CST8219::GameT<T>::getPlayersList()
{
	return playersList;
}
template <class T>
void GameT<T>::getGame(string n, int p, double t)
{
	n = name;
	p = numPlayers;
	t = timeout;
}
template <class T>
void GameT<T>::setGame(string n, int p, double t) {
	setName(n);
	setNumPlayers(p);
	setTimeout(t);
}
template <class T>
void CST8219::GameT<T>::setCurrentAttempt(int c)
{
	currentAttempt = c;
}
template <class T>
void GameT<T>::setName(string n) {
	name = n;
}
template <class T>
void GameT<T>::setNumPlayers(int num) {
	numPlayers = num;
}
template <class T>
void GameT<T>::setTimeout(double t) {
	timeout = t;
}
template <class T>
void GameT<T>::setCurrentPlayer(int a) {
	playersList.at(getCurrentPlayer()).setCurrentPlayer(false);
	playersList.at(a).setCurrentPlayer(true);
}
template <class T>
void CST8219::GameT::setCurrentTimeout(int c)
{
	currentTimeout = c;
}
/**
void CST8219::Game::setPlayersList(PlayerT p)
{
	playersList.push_back(p);
}
*/
template <class T>
void CST8219::GameT<T>::setGameType(GameType g)
{
	gameType = g;
}

//overloaded output stream
ostream& CST8219::operator<<(ostream& out, const GameT& g)
{
	out << "\nName: " << g.name << " - Numplayers: " << g.numPlayers << " - Timeout: " << g.timeout;
	return out;
}

//overloaded input stream
istream& CST8219::operator>>(istream& in, GameT& g)
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
			cout << "\nNumber of players must be between 1-10 " ;
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


/************************************************************
* Function name: printGame
* Purpose: prints the attributes of a game including players
* Return value: void
**************************************************************/
void GameT<T>::printGame() {
	cout << "********************Game Information**********************" << endl;
	cout << "Type: " << gameType << " Name: " << name << " - Number of players: " << numPlayers << " - Timeout: " << timeout << endl;
	listPlayers();
}

/************************************************************
* Function name: createPlayer
* Purpose: creates player(s) for a game instance
* Return value: void
**************************************************************/
void GameT<T>::createPlayer()
{
	PlayerT<int> p;
	cin >> p;
}

/************************************************************
* Function name: listPlayers
* Purpose: List the players of a game
* Return value: void
**************************************************************
void Game::listPlayers() {
	for (PlayerT<T> p : playersList)
		p.printPlayer();
}
/***************************************************
* Function name: start
* Purpose: Initializes game with players and runs sim
* Return value: void
***************************************************/
void GameT<T>::start() {
	cout << "************Game " << name << "*****************" << endl;
	createPlayer();
	play();
	printGame();
}

/************************************************************
* Function name: Play
* Purpose: Run a game simulation based on the game type
* Return value: void 
* */

void GameT<T>::play() {
	srand(time(0));
	using namespace std::chrono;
	int newPoints, totalPoints, nextPlayer;
	int attempt = getCurrentAttempt();	
	int tempCurrent = getCurrentPlayer();

	switch (gameType) {

	case ELECTRONIC:
		while (currentAttempt < MAX_ATTEMPTS && currentTimeout <= timeout) {
			currentAttempt++;
			auto start = chrono::system_clock::now();
			newPoints = rand() % MAX_POINTS;
			totalPoints = newPoints + playersList.at(0).getPoints();
			auto end = chrono::system_clock::now();
			printf("*******Turn %d*******", currentAttempt);
			cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;

			chrono::duration <double> diff = end - start;
			currentTimeout += diff.count() * 10000000;
			playersList.at(0).setPoints(totalPoints);
			if (getLifeExpectancy() <= 0) {
				cout << "You are dead!" << endl;
			}
		}
		break;

	case COMPETITIVE:

		do {
			while (currentAttempt < MAX_ATTEMPTS) {
				currentAttempt++;
				printf("\n*******Turn %d - Player %d*******", currentAttempt, tempCurrent + 1);
				newPoints = rand() % MAX_POINTS;
				totalPoints = newPoints + playersList.at(getCurrentPlayer()).getPoints();
				playersList.at(getCurrentPlayer()).setPoints(totalPoints);
				cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;
			}
			setCurrentPlayer(tempCurrent++);
			currentAttempt = 0;

		} while (tempCurrent < getNumPlayers());
		break;

	case MIXED:
		while (attempt <= MAX_ATTEMPTS && GameT::getCurrentTimeout() <= GameT::getTimeout()) {
			printf("\n*******Turn %d - Player %d*******", attempt, GameT::getCurrentPlayer() + 1);

			GameT::setCurrentAttempt(attempt++);
			int time = GameT::getCurrentTimeout();


			auto start = system_clock::now();
			newPoints = rand() % MAX_POINTS;
			totalPoints = newPoints + playersList.at(getCurrentPlayer()).getPoints();
			auto end = system_clock::now();

			duration <double> diff = end - start;
			time += diff.count() * 1000000;
			GameT::setCurrentTimeout(time);
			playersList.at(getCurrentPlayer()).setPoints(totalPoints);
			int nextPlayer = rand() % GameT::getNumPlayers();
			GameT::setCurrentPlayer(nextPlayer);

			cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;
			if (getLifeExpectancy() <= 0) cout << "You died!" << endl;
		}
		break;
	
	}

}



CST8219::ElectronicGameT<T>::ElectronicGameT(string gameName, double timeout):GameT(gameName, 1, timeout) {
	gameType = ELECTRONIC;
}

float CST8219::ElectronicGameT<T>::getLifeExpectancy() {
	return 100.0 * (1.0 - (currentTimeout / getTimeout()));
}

float CST8219::ElectronicGameT<T>::getWinProbability() {
	return 100.0;
}

CST8219::CompetitiveGameT<T>::CompetitiveGameT(string gameName, int nPlayers):GameT(gameName, nPlayers, DEFAULT_TIMEOUT) {
	gameType = COMPETITIVE;
}

float CST8219::CompetitiveGameT<T>::getLifeExpectancy()
{	
	return 100.0 * (1.0 - (getCurrentAttempt()/MAX_ATTEMPTS));
}

float CompetitiveGameT<T>::getWinProbability() {
	return (100.0 * (1.0 / getNumPlayers()));
}

MixedGameT<T>::MixedGameT(string gameName, int n, double t) : ElectronicGameT(gameName, t){//, CompetitiveGame(gameName, n) {
	GameT::setGameType(MIXED);
	GameT::setName(gameName);
	GameT::setNumPlayers(n);
	GameT::setTimeout(t);
}

float MixedGameT<T>::getLifeExpectancy() {
	return 100 * (1 - (GameT::getCurrentTimeout() / GameT::getTimeout())) * (1.0 - GameT::getCurrentAttempt() / MAX_ATTEMPTS);
}

float MixedGameT<T>::getWinProbability() {
	return (100.0 * (1.0 / GameT::getNumPlayers()));
}


