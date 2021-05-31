/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
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
	game0.printGame();
	game1.printGame();
	game2.printGame();
	game3.printGame();
	return EXIT_SUCCESS;
}


int main(int argc, char** argv)
{
	lab1();
	lab2();
	return EXIT_SUCCESS;
}