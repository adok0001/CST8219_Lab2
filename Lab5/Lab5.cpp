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

using namespace std;
using namespace CST8219;


void testPlayerTemplate() {
	PlayerT<int> player1;// = PlayerT<int>();
	cin >> player1;
	cout << player1;
	PlayerT<float> player2;// = PlayerT<float>();
	cin >> player2;
	cout << player2;
	PlayerT<long> player3;// = PlayerT<long>();
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
	lab5();
	return EXIT_SUCCESS;
}