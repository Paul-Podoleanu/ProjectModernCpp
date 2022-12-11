// ProiectMCNP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"
#include "GameConosoleVersion.h"

#include "Logging/Logging.h"
//#include "../ProjectModernCpp/Logging/Logging.h"
int main()
{
	std::ofstream of("syslog.log", std::ios::app);
	Logger logger(of);
	logger.log("Started application...", Logger::Level::Info);
	logger.log(123, Logger::Level::Info);


	//Setup joc consola, adica initializari
	GameConosoleVersion Game;
	Player one, two;
	Region reg;
	one.setName("Paul");
	one.setScore(0);
	two.setName("Ioan");
	two.setScore(0);
	Game.addPlayer(one);
	Game.addPlayer(two);

	//Adaugat regiuni manual
	reg = Region("Prahova", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Brasov", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Constanta", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Cluj", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Ilfov", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Vaslui", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Iasi", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Timisoara", 100, false, false, false);
	Game.addRegion(reg);
	reg = Region("Sibiu", 100, false, false, false);
	Game.addRegion(reg);
	//Joc in sine
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
