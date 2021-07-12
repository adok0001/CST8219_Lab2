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

Game::Game(string name, int nPlayers, double duration){
	setName(name);
	setNumPlayers(nPlayers);
	setTimeout(duration);
	currentAttempt = 0;
	currentTimeout = 0;
	currentPlayer = 0;
}
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

int CST8219::Game::getCurrentPlayer()
{
	int i; //iterator
	for (i = 0; i < playersList.size(); i++) {
		if (playersList.at(i).getCurrentPlayer()) return i;
	}
	return 0;
}

int CST8219::Game::getCurrentAttempt()
{
	return currentAttempt;
}

int CST8219::Game::getCurrentTimeout()
{
	return currentTimeout;
}

vector<Player> CST8219::Game::getPlayersList()
{
	return playersList;
}

void Game::getGame(string n, int p, double t)
{
	n = name;
	p = numPlayers;
	t = timeout;
}

void Game::setGame(string n, int p, double t) {
	setName(n);
	setNumPlayers(p);
	setTimeout(t);
}

void CST8219::Game::setCurrentAttempt(int c)
{
	currentAttempt = c;
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

void Game::setCurrentPlayer(int a) {
	playersList.at(getCurrentPlayer()).setCurrentPlayer(false);
	playersList.at(a).setCurrentPlayer(true);
}

void CST8219::Game::setCurrentTimeout(int c)
{
	currentTimeout = c;
}

void CST8219::Game::setPlayersList(Player p)
{
	playersList.push_back(p);
}

void CST8219::Game::setGameType(GameType g)
{
	gameType = g;
}

//overloaded equality operator
bool CST8219::Game::operator==(const Game& g)
{
	return (name == g.name && numPlayers == g.numPlayers && timeout == g.timeout);
}

//overloaded inequality operator
bool CST8219::Game::operator!=(const Game& g){
	return !(name == g.name && numPlayers == g.numPlayers && timeout == g.timeout);
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
		cout << "Enter the name of the game: ";
		in >> g.name;
		if (g.name.empty()) {
			cout << "Name cannot be empty" << endl;
			in.clear();
		}
	} while (g.name.empty());

	do {
		cout << "Enter the number of players: ";
		in >> g.numPlayers;
		if (g.numPlayers < 1 || g.numPlayers > 10) {
			in.clear();
			cout << "Number of players must be between 1-10 " << endl;
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
void Game::printGame() {
	cout << "********************Game Information**********************" << endl;
	cout << "Type: " << gameType << " Name: " << name << " - Number of players: " << numPlayers << " - Timeout: " << timeout << endl;
	listPlayers();
}

/************************************************************
* Function name: createPlayer
* Purpose: creates player(s) for a game instance
* Return value: void
**************************************************************/
void Game::createPlayer()
{
	int i; //iterator
	int randCurr=0;
	string playerName; //variable to store player name

	for (i = 0; i < getNumPlayers(); i++) {
		std::cout << "Enter player name: ";
		std::cin >> playerName;
		Player p(playerName); //creates a new player with only name attribute set
		setPlayersList(p); //adds Player to vector playerList
	}

	switch (gameType) {

	case MIXED:
		randCurr = rand() % playersList.size();
		setCurrentPlayer(randCurr);
		break;

	default:
		playersList.at(0).setCurrentPlayer(true);
		currentPlayer = 0;
		break;
	}
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
/***************************************************
* Function name: start
* Purpose: Initializes game with players and runs sim
* Return value: void
***************************************************/
void Game::start() {
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
void Game::play() {
	srand(time(NULL));
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
		while (attempt <= MAX_ATTEMPTS && Game::getCurrentTimeout() <= Game::getTimeout()) {
			printf("\n*******Turn %d - Player %d*******", attempt, Game::getCurrentPlayer() + 1);

			Game::setCurrentAttempt(attempt++);
			int time = Game::getCurrentTimeout();


			auto start = system_clock::now();
			newPoints = rand() % MAX_POINTS;
			totalPoints = newPoints + playersList.at(getCurrentPlayer()).getPoints();
			auto end = system_clock::now();

			duration <double> diff = end - start;
			time += diff.count() * 1000000;
			Game::setCurrentTimeout(time);
			playersList.at(getCurrentPlayer()).setPoints(totalPoints);
			int nextPlayer = rand() % Game::getNumPlayers();
			Game::setCurrentPlayer(nextPlayer);

			cout << "\nPoints = " << newPoints << " Life expectancy = " << getLifeExpectancy() << " Win probability = " << getWinProbability() << endl;
			if (getLifeExpectancy() <= 0) cout << "You died!" << endl;
		}
		break;
	
	}

}



CST8219::ElectronicGame::ElectronicGame(string gameName, double timeout):Game(gameName, 1, timeout) {
	gameType = ELECTRONIC;
}

float CST8219::ElectronicGame::getLifeExpectancy() {
	return 100.0 * (1.0 - (currentTimeout / getTimeout()));
}

float CST8219::ElectronicGame::getWinProbability() {
	return 100.0;
}

CST8219::CompetitiveGame::CompetitiveGame(string gameName, int nPlayers):Game(gameName, nPlayers, DEFAULT_TIMEOUT) {
	gameType = COMPETITIVE;
}

float CST8219::CompetitiveGame::getLifeExpectancy()
{	
	return 100.0 * (1.0 - (getCurrentAttempt()/MAX_ATTEMPTS));
}

float CompetitiveGame::getWinProbability() {
	return (100.0 * (1.0 / getNumPlayers()));
}

MixedGame::MixedGame(string gameName, int n, double t) : ElectronicGame(gameName, t){//, CompetitiveGame(gameName, n) {
	Game::setGameType(MIXED);
	Game::setName(gameName);
	Game::setNumPlayers(n);
	Game::setTimeout(t);
}

float MixedGame::getLifeExpectancy() {
	return 100 * (1 - (Game::getCurrentTimeout() / Game::getTimeout())) * (1.0 - Game::getCurrentAttempt() / MAX_ATTEMPTS);
}

float MixedGame::getWinProbability() {
	return (100.0 * (1.0 / Game::getNumPlayers()));
}


