/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;
using namespace CST8219;

int lab1() {

	/*CST8219::Game myGame();
	Game game2(4, 2000);*/
	cout << "I made a game" << endl;

	return EXIT_SUCCESS;
}

int lab2() {
	Game game0;
	Game game1("Game1");
	Game game2("Game2", 4);
	Game game3("Game3", 4, 2000);
	cout << "Game0 takes " << sizeof(game0) << endl;
	cout << "Game1 takes " << sizeof(game1) << endl;
	cout << "Game2 takes " << sizeof(game2) << endl;
	cout << "Game3 takes " << sizeof(game3) << endl;
	game0.printGame();
	game1.printGame();
	game2.printGame();
	game3.printGame();
	return EXIT_SUCCESS;
}

void changeGame(Game& g, string n = "[Noname]", int p = 1, double t = -1) {
	g.setGame(n, p, t);
}

void testReferences() {
	Game game1 = Game("Game1", 1, 1);
	game1.printGame();
	Game game2(game1);
	game2.printGame();
	Game game3(&game2);
	game3.printGame();
	changeGame(game3);
	game3.printGame();

}

void printAddress(Game g) {
	cout << "\nGame: " << g.getName() << " - Address: " << &g << endl;
}

int main(int argc, char** argv)
{
	/*lab1();
	lab2();*/
	testReferences();
	vector<Game> glist;
	Game game;  game.createOneGame(game);
	printAddress(game);
	game.createMultipleGames(glist);

	return EXIT_SUCCESS;
}