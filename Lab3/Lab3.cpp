/******************************************
FILE: Lab3.cpp
PURPOSE: Driver file for Game Application
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

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

/************************************************************
* Function name: changeGame
* Purpose: Modifies a game based on the given parameters
* Parameters:
* g = Game to be modified
* n = New name or default "[Noname]"
* p = New points or default 1
* t = New timeout or default -1
* Return value: void
**************************************************************/
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

void testOperators() {
	Game original("Fela",5,2000);
	Game copy(original); // copy constructor by reference
	cout << "Original is: " << original << " copy is: " << copy << endl;
	cout << "Increment original: " << original++ << endl;
	cout << "Increment copy:" << ++copy << endl;
	cout << "Decrement original:" << --original << endl;
	cout << "Decrement copy:" << copy-- << endl;
	// should be true:
	cout << "Compare equality 1: " << (original == copy) << endl;
	//should be false:
	cout << "Compare equality 2: " << (--original == ++copy) << endl;
	//should be true:
	cout << "Compare inequality: " << (original != copy) << endl;
	// This should make original = copy, and then return a Vehicle for output:
	cout << "Assignment operator: " << (original = copy) << endl;
}

/************************************************************
* Function name: printAddress
* Purpose: prints the address in memory of a game object
* Parameters:
* g = Game object whose address is to be printed
* Return value: void
**************************************************************/
void printAddress(Game g) {
	cout << "\nGame: " << g.getName() << " - Address: " << &g << endl;
}

int main(int argc, char** argv)
{
	
	lab1();
	lab2();
	testReferences();
	testOperators();
	vector<Game> glist;
	Game game;  game.createOneGame(game);
	printAddress(game);
	game.createMultipleGames(glist);

	return EXIT_SUCCESS;
}