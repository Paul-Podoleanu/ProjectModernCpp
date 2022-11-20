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
