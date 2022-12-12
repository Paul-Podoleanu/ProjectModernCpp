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

	//Citit intrebari din fisier
	//Game.getQuestions().addQuestion();
	Game.ReadQuestion();

	//Game.getQuestions().writeQuestionWithNumeric();
	std::cout << Game.getQuestions().getNumberQVar() << std::endl;;

	/*std::string p1, p2;
	std::cout << "p1: ";
	std::getline(std::cin, p1);
	std::cout << "p1: " << p1;*/


	//Joc in sine
	Game.StartGame(one,two,5);

}

