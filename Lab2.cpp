/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
#include "Game.h"

using namespace std;
using namespace CST8219;

int lab1() {
	//Game game1("Tam", 12);
	//Game myGame();
	cout << "I made a game\n\n" << endl;
	return EXIT_SUCCESS;
}

int lab2() {
	Game game0;
	Game game1("Game1");
	Game game2("Game2", 4);
	Game game3("Game3", 4, 2000);

	cout << "\nGame0 takes " << sizeof(game0) << endl;
	cout << "Game1 takes " << sizeof(game1) << endl;
	cout << "Game2 takes " << sizeof(game2) << endl;
	cout << "Game3 takes " << sizeof(game3) << endl;

	game0.printGame();
	game1.printGame();
	game2.printGame();
	game3.printGame();

	game0.createOneGame();

	return EXIT_SUCCESS;
}


void Game::printGame() {
	cout << "Name: " << name << " - Numplayers: " << numPlayers << " - Timeout: " << timeout << endl;
}

void Game::createOneGame() {
	
	while (true) {
		cout << "Enter the name: " << endl;
		cin >> name;
		if (name.empty()) {
			cout << "Name cannot be empty" << endl;
			cin.clear();
		}
		else break;
	}

	while (true) {
		cout << "Enter the number of players" << endl;
		cin >> numPlayers;
		if (numPlayers < 1 || numPlayers > 10) {
			cin.clear();
			cout << "Number of players must be between 1-10 " << endl;
		}
		else
			break;
	}
	while (true) {
		cout << "Enter the game duration" << endl;
		cin >> timeout;
		if (timeout <= 0) {
			cin.clear();
			cout << "Timeout cannot be a negative number\n";
		}
		else 
			break;

	}

	Game aGame = Game(name, numPlayers, timeout);
	aGame.printGame();
}


int main(int argc, char** argv)
{
	lab1();
	lab2();
	

	return EXIT_SUCCESS;
}