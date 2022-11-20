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
}
