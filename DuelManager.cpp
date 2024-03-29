#include "DuelManager.h"


void DuelManager::NormalRegionDuel(bool isBase)
{
}

Player DuelManager::BaseDuel(Question q, Player& one, Player& two, bool isBase)
{
	std::cin.ignore();
	int life = 3;
	while (life != 0)
	{
		QuestionABCD question = q.getRandomQuestionWithVariants();
		std::cout << question;
		std::string answerPlayerOne, answerPlayerTwo;
		std::cout << "Input for " << one.getName() << ':';
		
		std::getline(std::cin, answerPlayerOne);;

		std::cout << "Input for " << two.getName() << ':';
		//	std::cin.ignore();
		std::getline(std::cin, answerPlayerTwo);
		if (answerPlayerOne != answerPlayerTwo) {
			if (answerPlayerOne != question.getCorrectAnswer()) {
				return two;
			}
			if (answerPlayerOne == question.getCorrectAnswer()) {
				life--;
				std::cout << "Mai ramane " << life << " hp pentru baza \n";
			}
			if (answerPlayerTwo == question.getCorrectAnswer()) {
				return two;
			}
		}
		else
			if (answerPlayerOne == answerPlayerTwo)
				if (answerPlayerTwo == question.getCorrectAnswer())
				{
					std::cout << "Same answer, we go to numeric questions \n";
					QuestionNumeric question = q.getRandomQuestionWithNumericAnswer();
					std::cout << std::endl << question;
					std::cout << "Input for " << one.getName() << ':';
					std::cin >> answerPlayerOne;

					std::cout << "Input for " << two.getName() << ':';
					std::cin >> answerPlayerTwo;
					if (std::stoi(answerPlayerOne) != std::stoi(answerPlayerTwo))
					{
						answerPlayerOne = question.getCorrectAnswer() - std::stoi(answerPlayerOne);
						answerPlayerTwo = question.getCorrectAnswer() - std::stoi(answerPlayerTwo);
						if (std::stoi(answerPlayerOne) < 0) {
							answerPlayerOne = std::stoi(answerPlayerOne) * (-1);
						}
						if (std::stoi(answerPlayerTwo) < 0) {
							answerPlayerTwo = std::stoi(answerPlayerTwo) * (-1);
						}
						if (std::stoi(answerPlayerOne) > std::stoi(answerPlayerTwo))
						{
							life--;
						}
						else {
							return two;
						}

					}
				}
				else {
					return two;
				}
		
	}

	//Se face decizia dintre care player a castigat baza
	if (life == 0) {
		return one;
	}
	return two;
}


void DuelManager::DuelTime()
{
}

Player DuelManager::TwoPlayerDuelABCD(Question q, Player& one, Player& two, int score)
{
	//Nu am implementat un timer pentru intrebari
	//Acesta este un schelet, o sa trb refacute total cand introducem GUI,timer,etc.
	//Sper sa putem copia direct peste codul asta ce o sa mai facem
	QuestionABCD question = q.getRandomQuestionWithVariants();
	Player neutru;
	std::string answerPlayerOne, answerPlayerTwo;
	std::cout << question;
	std::cout << "Input for " << one.getName() << ':';
	std::cin.ignore();
	std::getline(std::cin, answerPlayerOne);

	std::cout << "Input for " << two.getName() << ':';
	std::cin.ignore();
	std::getline(std::cin, answerPlayerTwo);

	if (answerPlayerOne != answerPlayerTwo) {
		if (answerPlayerOne == question.getCorrectAnswer()) {
			one.changeScore(score);
			return one;
		}
		if (answerPlayerTwo == question.getCorrectAnswer()) {
			two.changeScore(score);
			return two;
		}
		else {
			return neutru;
		}
	}
	else {
		std::cout << "No winner \n";
		return TwoPlayerDuelNumeric(q, one, two, score);
	}

}

Player DuelManager::TwoPlayerDuelNumeric(Question q, Player& one, Player& two, int score)
{
	//Nu am implementat un timer pentru intrebari
	//Acesta este un schelet, o sa trb refacute total cand introducem GUI,timer,etc.
	//Sper sa putem copia direct peste codul asta ce o sa mai facem
	QuestionNumeric question = q.getRandomQuestionWithNumericAnswer();
	int answerPlayerOne, answerPlayerTwo;
	Player neutru;
	std::cout << question;
	std::cout << "Input for " << one.getName() << ':';
	std::cin >> answerPlayerOne;

	std::cout << "Input for " << two.getName() << ':';
	std::cin >> answerPlayerTwo;

	//Se calculeaza diferenta de scor dintre ce s-a ales si raspunsul corect
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
			return one;
		}
		else {
			two.changeScore(score);
			return two;
		}
	}
	else {
		std::cout << "Same answer, no winner \n";
		//Daca este acelasi raspuns, se mai alege o intrebare
		return TwoPlayerDuelABCD(q, one, two, score);
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

void DuelManager::FourPlayerDuelABCD(Board b, Question q, Player one, Player two, Player three, Player four, int score)
{
	QuestionABCD question = q.getRandomQuestionWithVariants();
	std::string answerPlayerOne, answerPlayerTwo, answerPlayerThree,answerPlayerFour, region;

	std::cout << "Input for " << one.getName() << ':';
	std::cin >> answerPlayerOne;

	std::cout << "Input for " << two.getName() << ':';
	std::cin >> answerPlayerTwo;

	std::cout << "Input for " << three.getName() << ':';
	std::cin >> answerPlayerThree;
	std::cout << "Input for " << four.getName() << ':';
	std::cin >> answerPlayerFour;
	

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
	if(answerPlayerFour == question.getCorrectAnswer()) {
		four.changeScore(score);
		std::cout << "Choose a region to take: ";
		std::cin >> region;
		if (b.getSpecificRegion(region).getisOwned() == true) {
			std::cout << "Could not be taken \n";
		}
		else {
			//three.addRegion(region, b);
		}
	
}
