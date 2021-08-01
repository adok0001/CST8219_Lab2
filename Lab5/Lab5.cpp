/******************************************
FILE: Lab4.cpp
PURPOSE: Driver file for Game Application
AUTHOR(S): Adokeme Tamara - 040973188
PROFESSOR: Frank Emanuel
COURSE: [CST8219 – 302]
******************************************/

#include <iostream>
#include <vector>
#include "Player.cpp"
#include "Game.cpp"
#include "Game.h"

using namespace std;
using namespace CST8219;


void testPlayerTemplate() {
	PlayerT<int> player1 = PlayerT<int>("Pele", 10, true);
	cin >> player1;
	cout << player1;
	PlayerT<float> player2 = PlayerT<float>("",10.35, false);
	cin >> player2;
	cout << player2;
	PlayerT<long> player3 = PlayerT<long>("", 12L, true);
	cin >> player3;
	cout << player3;
}
/*************************************************************
*
*
*
*
*
****************************************************************/
void lab5() {
	testPlayerTemplate();
}



int main(int argc, char** argv)
{
	//lab5();
	srand(time(NULL));
	int answer=0;
	do {
		cout << "Select the game type: (1) Electronic, (2) Competitive, (3) Mixed, (0) Quit: " << endl;
		cin >> answer;
		switch (answer) {
			case 0:
				cout << "\nGoodbye";
				break;
			case 1: {
				ElectronicGameT<int> eg = ElectronicGameT<int>("Electronic Game Demo", DEFAULT_TIMEOUT);
				eg.play();
				eg.showResults();
				break;
			}
			case 2: {
				CompetitiveGameT<int> cg = CompetitiveGameT<int>("Competitive Game Demo", 4);
				cg.play();
				cg.showResults();
				break;
			}
			case 3: {
				MixedGameT<int> mg = MixedGameT<int>("Mixed Game Demo", 3, DEFAULT_TIMEOUT);
				mg.play();
				mg.showResults();
				break;
			}
		}
		
	} while (answer != 0);
	return EXIT_SUCCESS;
}