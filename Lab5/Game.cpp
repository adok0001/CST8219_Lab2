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

template<class T>
vector<PlayerT<T>> CST8219::GameT<T>::getPlayersList()
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
template<class T>
void CST8219::GameT<T>::setPlayersList(PlayerT<T> p)
{
	playersList.push_back(p);
}
template <class T>
void GameT<T>::setCurrentPlayer(int a) {
	if (a >= numPlayers) a = 0;
	playersList.at(getCurrentPlayer()).setCurrentPlayer(false);
	playersList.at(a).setCurrentPlayer(true);
	currentPlayer = a;
}

template <class T>
void CST8219::GameT<T>::setCurrentTimeout(double c)
{
	currentTimeout = c;
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


/************************************************************
* Function name: Play
* Purpose: Run a game simulation based on the game type
* Return value: void 
* *

void GameT<T>::play() {
	srand(time(0));
	using namespace std::chrono;
	int newPoints, totalPoints, nextPlayer;
	int attempt = getCurrentAttempt();	
	int tempCurrent = getCurrentPlayer();
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

*/
template <class T>
CST8219::ElectronicGameT<T>::ElectronicGameT(string gameName, double timeout):GameT<T>(gameName, 1, timeout) {
	gameType = ELECTRONIC;
}
template <class T>
float CST8219::ElectronicGameT<T>::getLifeExpectancy() {
	return 100.0 * (1.0 - (currentTimeout / getTimeout()));
}
template <class T>
float CST8219::ElectronicGameT<T>::getWinProbability() {
	return 100.0;
}
template <class T>
void CST8219::ElectronicGameT<T>::play() {
	T currentPoints, totalPoints = 0;
	PlayerT<T> p;
	cin >> p;
	p.setCurrentPlayer(true);
	while (currentAttempt < MAX_ATTEMPTS && currentTimeout <= getTimeout()) {	
		currentAttempt++;
		auto start = chrono::system_clock::now();
		currentPoints = rand() % MAX_POINTS + 1;
		totalPoints += currentPoints;
		pointsPerTurn.push(currentPoints);
		auto end = chrono::system_clock::now();
		p.setPoints(totalPoints);
		printf("*******Turn %d*******", currentAttempt);
		cout << "\nPoints = " << currentPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;

		chrono::duration <double> diff = end - start;
		currentTimeout += diff.count() * 10000000;

		if (getLifeExpectancy() <= 0) {
			cout << "You are dead!" << endl;
		}

	}
	setPlayersList(p);
}

template<class T>
void CST8219::ElectronicGameT<T>::showResults()
{

	T points, result = 0;

	cout << getPlayersList().at(0);
	while (!pointsPerTurn.empty()) {
		points = (T)pointsPerTurn.front();
		result += points;
		cout << " " << points;
		pointsPerTurn.pop();
	}
	
	cout << " - Total: " << result << endl;
}

template <class T>
CST8219::CompetitiveGameT<T>::CompetitiveGameT(string gameName, int nPlayers):GameT<T>(gameName, nPlayers, DEFAULT_TIMEOUT) {
	gameType = COMPETITIVE;
}

template <class T>
float CST8219::CompetitiveGameT<T>::getLifeExpectancy()
{	
	return 100.0 * (1.0 - (getCurrentAttempt()/MAX_ATTEMPTS));
}
template <class T>
float CompetitiveGameT<T>::getWinProbability() {
	return (100.0 * (1.0 / getNumPlayers()));
}
template <class T>
void CompetitiveGameT<T>::play() {
	int playerNum = getNumPlayers();
	T newPoints, totalPoints;
	for (int i = 0; i < playerNum; i++) {
		PlayerT<T> p;
		cin >> p;
		setPlayersList(p);
	}

	currentPlayer = rand() % playerNum-1;
	setCurrentPlayer(currentPlayer);
	for (int i = 0; i < playerNum; i++) {
		currentAttempt = 0;
		while (currentAttempt < MAX_ATTEMPTS) {
			printf("\n*******Turn %d - Player %d*******", currentAttempt++, currentPlayer);
			
			newPoints = rand() % MAX_POINTS;
			totalPoints = newPoints + playersList.at(getCurrentPlayer()).getPoints();
			playersList.at(currentPlayer).setPoints(totalPoints);
			pointsPerPlayer.push_back(newPoints);
			cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;
		}
		currentPlayer++;
		setCurrentPlayer(currentPlayer);
	}

}
template <class T>
void CompetitiveGameT<T>::showResults() {
	int playerNum = getNumPlayers()-1;
	int current = currentPlayer - 1;
	if (currentPlayer == 0) current = playerNum;
	list<T>::iterator it = pointsPerPlayer.begin();
	advance(it, (playerNum) * 10);

	for (int i = 0; i <= playerNum; i++) {
		PlayerT<T> tempCurrent = getPlayersList().at(current);
		cout << "Player name: " << tempCurrent.getName();
		cout << " - Points: ";
		for (int j = 0; j < 10; j++) {
			cout << " " << *it;
			it++;
		}
		
		cout << " - Total: " << tempCurrent.getPoints() << endl;
		current++;
		setCurrentPlayer(current);
		current = currentPlayer;
		it = pointsPerPlayer.begin();
		advance(it, i * 10);
	}
}
template <class T>
MixedGameT<T>::MixedGameT(string gameName, int n, double t) : ElectronicGameT(gameName, t){//, CompetitiveGame(gameName, n) {
	GameT<T>::setName(gameName);
	GameT<T>::setNumPlayers(n);
	GameT<T>::setTimeout(t);
} 
template <class T>
float MixedGameT<T>::getLifeExpectancy() {
	return 100 * (1 - (GameT<T>::getCurrentTimeout() / GameT<T>::getTimeout())) * (1.0 - GameT<T>::getCurrentAttempt() / MAX_ATTEMPTS);
}
template <class T>
float MixedGameT<T>::getWinProbability() {
	return (100.0 * (1.0 / GameT<T>::getNumPlayers()));
}

template <class T>
void MixedGameT<T>::play() {
	using namespace std::chrono;
	int attempt = GameT<T>::getCurrentAttempt();
	int time = GameT<T>::getCurrentTimeout();
	T newPoints, totalPoints;

	for (int i = 0; i < GameT<T>::getNumPlayers(); i++) {
		PlayerT<T> p;
		cin >> p;
		GameT<T>::setPlayersList(p);
	}

	while (attempt <= MAX_ATTEMPTS && time <= GameT<T>::getTimeout()) {
		printf("\n*******Turn %d - Player %d*******", attempt++, GameT<T>::getCurrentPlayer() + 1);
		PlayerT<T> tempCurrent = GameT<T>::playersList.at(GameT<T>::getCurrentPlayer());
		GameT<T>::setCurrentAttempt(attempt);
		auto start = system_clock::now();
		newPoints = rand() % MAX_POINTS;
		totalPoints = newPoints + tempCurrent.getPoints();
		auto end = system_clock::now();
		playerPointsMap.insert(make_pair(tempCurrent.getName(), newPoints));
		duration <double> diff = end - start;
		time += diff.count() * 1000000;
		GameT<T>::playersList.at(GameT<T>::getCurrentPlayer()).setPoints(totalPoints);
		int nextPlayer = rand() % GameT<T>::getNumPlayers();
		GameT<T>::setCurrentPlayer(nextPlayer);
		GameT<T>::setCurrentTimeout(time);
		cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;
		if (getLifeExpectancy() <= 0) cout << "You died!" << endl;
	}
}

template <class T>
void MixedGameT<T>::showResults() {
	
	for (int i = 0; i < GameT<T>::getNumPlayers(); i++) {
		PlayerT<T> tempCurrent = GameT<T>::playersList.at(i);
		auto range = playerPointsMap.equal_range(tempCurrent.getName());
		cout << "Player: " << tempCurrent.getName() << " points: ";
		for (auto it = range.first; it != range.second; ++it) {
			cout << it->second << ", ";
		}
		 cout << " - Total Points: " << tempCurrent.getPoints() << endl;
	}
}