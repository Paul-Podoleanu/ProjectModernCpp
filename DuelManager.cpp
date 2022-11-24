#include "DuelManager.h"

DuelManager::DuelManager()
{
}

void DuelManager::NormalRegionDuel(bool isBase)
{
}

void DuelManager::BaseDuel(bool isBase)
{
}

void DuelManager::DuelTime()
{
}

void DuelManager::TwoPlayerDuelABCD(Question q,Player one, Player two, int score)
{
	//Nu am implementat un timer pentru intrebari
	//Acesta este un schelet, o sa trb refacute total cand introducem GUI,timer,etc.
	//Sper sa putem copia direct peste codul asta ce o sa mai facem
	QuestionABCD question = q.getRandomQuestionWithVariants();
	std::string answerPlayerOne, answerPlayerTwo;
	std::cout << "Input for " << one.getName() << ':';
	std::cin >> answerPlayerOne;

	std::cout << "Input for " << two.getName() << ':';
	std::cin >> answerPlayerTwo;

	if (answerPlayerOne != answerPlayerTwo) {
		if (answerPlayerOne == question.getCorrectAnswer()) {
			one.changeScore(score);
		}
		if (answerPlayerTwo == question.getCorrectAnswer()) {
			two.changeScore(score);
		}
	}
	else {
		std::cout << "Same answer, no winner \n";
		TwoPlayerDuelABCD(q, one, two, score);
	}

}

void DuelManager::TwoPlayerDuelNumeric(Question q, Player one, Player two, int score)
{
	//Nu am implementat un timer pentru intrebari
	//Acesta este un schelet, o sa trb refacute total cand introducem GUI,timer,etc.
	//Sper sa putem copia direct peste codul asta ce o sa mai facem
	QuestionNumeric question = q.getRandomQuestionWithNumericAnswer();
	int answerPlayerOne, answerPlayerTwo;
	std::cout << "Input for " << one.getName() << ':';
	std::cin >> answerPlayerOne;

	std::cout << "Input for " << two.getName() << ':';
	std::cin >> answerPlayerTwo;

	if (answerPlayerOne != answerPlayerTwo) {
		answerPlayerOne = question.getCorrectAnswer() - answerPlayerOne;
		answerPlayerTwo = question.getCorrectAnswer() - answerPlayerTwo;
		if (answerPlayerOne < 0) {
			answerPlayerOne = answerPlayerOne * (-1);
		}
		if (answerPlayerTwo < 0) {
			answerPlayerTwo = answerPlayerTwo * (-1);
		}
		if (answerPlayerOne < answerPlayerTwo) {
			one.changeScore(score);
		}
		else {
			two.changeScore(score);
		}
	}
	else {
		std::cout << "Same answer, no winner \n";
		//Daca este acelasi raspuns, se mai alege o intrebare
		TwoPlayerDuelNumeric(q,one,two,score);
	}
}

void DuelManager::ThreePlayerDuelABCD(Board b, Question q, Player one, Player two, Player three, int score)
{
	//Nu am implementat un timer pentru intrebari
	//Acesta este un schelet, o sa trb refacute total cand introducem GUI,timer,etc.
	//Sper sa putem copia direct peste codul asta ce o sa mai facem
	QuestionABCD question = q.getRandomQuestionWithVariants();
	std::string answerPlayerOne, answerPlayerTwo, answerPlayerThree, region;

	std::cout << "Input for " << one.getName() << ':';
	std::cin >> answerPlayerOne;

	std::cout << "Input for " << two.getName() << ':';
	std::cin >> answerPlayerTwo;

	std::cout << "Input for " << three.getName() << ':';
	std::cin >> answerPlayerThree;

	//Aceasta functie o sa necesite un timer, scorurile trebuie sa fie diferie
	//Momentan se da acelasi scor daca toti jucatorii au acelasi raspuns
	if (answerPlayerOne == question.getCorrectAnswer()) {
		one.changeScore(score);
		//Se alege regiuni aici, valabil pentru fiecare jucator
		//O sa trebuiasca conectate la board, prin click-uri
		std::cout << "Choose a region to take: ";
		std::cin >> region;
		if (b.getSpecificRegion(region).getisOwned() == true) {
			std::cout << "Could not be taken \n";
		}
		else {
			//one.addRegion(region, b);
		}
	}
	if (answerPlayerTwo == question.getCorrectAnswer()) {
		two.changeScore(score);
		std::cout << "Choose a region to take: ";
		std::cin >> region;
		if (b.getSpecificRegion(region).getisOwned() == true) {
			std::cout << "Could not be taken \n";
		}
		else {
			//two.addRegion(region, b);
		}
	}
	if (answerPlayerThree == question.getCorrectAnswer()) {
		three.changeScore(score);
		std::cout << "Choose a region to take: ";
		std::cin >> region;
		if (b.getSpecificRegion(region).getisOwned() == true) {
			std::cout << "Could not be taken \n";
		}
		else {
			//three.addRegion(region, b);
		}
	}


}
