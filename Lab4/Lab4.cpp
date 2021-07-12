/******************************************
FILE: Lab4.cpp
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

/*************************************************************
*
*
*
*
*
****************************************************************/
void lab4() {
	ElectronicGame eg("Pool", 60);
	CompetitiveGame cg("Darts", 3);
	MixedGame mg("Golf", 3, 200);
	eg.start();
	cg.start();
	mg.Game::start();
}

int main(int argc, char** argv)
{
	lab4();
	return EXIT_SUCCESS;
}