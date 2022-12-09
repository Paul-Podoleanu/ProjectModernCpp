#include "GameConosoleVersion.h"

void GameConosoleVersion::chooseBaseStartOfGame2Player(Player one, Player two)
{
	//Declarari ce o sa fie necesar
	//2 stringuri, ca sa nu mai caute prin regiuni pentru a da check
	std::string inputNume1, inputNume2;
	Region inputBase;

	std::cout << one.getName() << " alege o baza: ";
	std::cin >> inputNume1;
	inputBase = table.getSpecificRegion(inputNume1);
	one.setBase(inputBase);
	//Adaugat info pentru regiunea aleasa in variable table, pentru primul player
	for (int i = 0; i < table.getRegions().size(); i++) {
		if (table.getRegions()[i].first.getName() == inputNume1) {
			table.getRegions()[i].first.setIsBase(true);
			table.getRegions()[i].first.setisOwned(true);
			table.getRegions()[i].second = one;
			one.setBase(table.getRegions()[i].first);
			break;
		}
	}


	std::cout << two.getName() << " alege o baza: ";
	std::cin >> inputNume2;
	//Check ca nu se alege aceeasi baza la amadoi playeri
	while (inputNume1==inputNume2)
	{
		std::cout << "Baza deja aleasa, introduceti alt nume: ";
		std::cin >> inputNume2;
	}


	inputBase = table.getSpecificRegion(inputNume2);
	two.setBase(inputBase);
	//Adaugat info pentru regiunea aleasa in variable table, pentru al doilea player
	for (int i = 0; i < table.getRegions().size(); i++) {
		if (table.getRegions()[i].first.getName() == inputNume2) {
			table.getRegions()[i].first.setIsBase(true);
			table.getRegions()[i].first.setisOwned(true);
			table.getRegions()[i].second = two;
			two.setBase(table.getRegions()[i].first);
			break;
		}
	}


}

std::pair<int, int> GameConosoleVersion::preGameQuestions2Player(Player one, Player two)
{
	//Declarari
	std::pair<int, int> answers;
	answers.first = 0;
	answers.second = 0;
	int num1, num2;
	std::string st1, st2;

	//Luam intrebarile care o sa fie folosite
	QuestionABCD firstQuestion=questions.getRandomQuestionWithVariants(), thirdQuestion= questions.getRandomQuestionWithVariants();
	QuestionNumeric secondQuestion ;

	//Prima intrebare
	//Sper ca merge operatorul << nu am testat inca :P
	std::cout << firstQuestion;
	std::cout << "Raspuns de la " << one.getName()<<':';
	std::cin >> st1;
	std::cout << "Raspuns de la " << two.getName() << ':';
	std::cin >> st2;

	if (st1 == firstQuestion.getCorrectAnswer()) {
		answers.first++;
		std::cout << one.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << one.getName() << " nu a raspuns corect \n";
	}

	if (st2 == firstQuestion.getCorrectAnswer()) {
		answers.second++;
		std::cout << two.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << two.getName() << " nu a raspuns corect \n";
	}


	//A doua intrebare
	std::cout << secondQuestion;
	std::cout << "Raspuns de la " << one.getName() << ':';
	std::cin >> num1;
	std::cout << "Raspuns de la " << two.getName() << ':';
	std::cin >> num2;

	if (num1 == secondQuestion.getCorrectAnswer()) {
		answers.first++;
		std::cout << one.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << one.getName() << " nu a raspuns corect \n";
	}

	if (num2 == secondQuestion.getCorrectAnswer()) {
		answers.second++;
		std::cout << two.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << two.getName() << " nu a raspuns corect \n";
	}


	//A treia intrebare
	std::cout << thirdQuestion;
	std::cout << "Raspuns de la " << one.getName() << ':';
	std::cin >> st1;
	std::cout << "Raspuns de la " << two.getName() << ':';
	std::cin >> st2;

	if (st1 == thirdQuestion.getCorrectAnswer()) {
		answers.first++;
		std::cout << one.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << one.getName() << " nu a raspuns corect \n";
	}

	if (st2 == thirdQuestion.getCorrectAnswer()) {
		answers.second++;
		std::cout << two.getName() << " a raspuns corect \n";
	}
	else {
		std::cout << two.getName() << " nu a raspuns corect \n";
	}


	return answers;

}

void GameConosoleVersion::pickRegion(Player one, int nrRegions)
{
	std::string nume;
	std::cout << "Alege o regiune de cucerit: ";
	std::cin >> nume;

	while (nrRegions!=0)
	{
		for (int i = 0; i < table.getRegions().size(); i++) {
			if (nume == table.getRegions()[i].first.getName()) {
				if (table.getRegions()[i].first.getisOwned() == false) {
					std::cout << nume << " a fost cucerita! \n";
					//Atribuiri
					one.addRegion(table.getRegions()[i].first);
					table.getRegions()[i].first.setisOwned(true);
					table.getRegions()[i].second = one;
					nrRegions--;
					//Check daca mai sunt de adaugat
					if (nrRegions == 0)
						break;
				}
			}
		}
		std::cout << "Alege o regiune de cucerit: ";
		std::cin >> nume;
	}
}

void GameConosoleVersion::attackPlayer(Player one, Player two, Region region)
{
	//Eventual o sa trb sa le facem dinamic
	Player aux;
	DuelManager duel;

	//Option alege la intamplare ce tip de intrebare va fi pusa, si ca atare tipul de duel
	int option = rand() % 2;
	if (option == 0) {
		aux = duel.TwoPlayerDuelABCD(questions, one, two, region.getPoints());
	}
	if (option == 1) {
		aux = duel.TwoPlayerDuelNumeric(questions, one, two, region.getPoints());
	}
	if (one == aux) {
		std::cout << "Regiunea a fost furata de catre " << one.getName();
		one.addRegion(region);
		two.loseRegion(region);
		//Se schimba owner-ul regiunii din table
		for (int i = 0; i < table.getRegions().size(); i++) {
			if (region.getName() == table.getRegions()[i].first.getName()) {
				table.getRegions()[i].second = one;
				break;
			}
		}
	}
	else {
		std::cout << "Regiunea ramane in mainile lui " << two.getName();
	}

}

void GameConosoleVersion::AttackPlayerBase(Player one, Player two, Region base)
{
	Player aux;
	DuelManager duel;
	int life = 3;
	while (life != 0)
	{
		
	}
}

void GameConosoleVersion::addPlayer(Player one)
{
	players.push_back(one);
}
