#include "GameConosoleVersion.h"

GameConosoleVersion::GameConosoleVersion()
{
}

GameConosoleVersion::~GameConosoleVersion()
{
}

GameConosoleVersion::GameConosoleVersion(std::vector<Player> players, Board table, Question questions) :players(players), table(table), questions(questions)
{
}


void GameConosoleVersion::chooseBaseStartOfGame2Player(Player& one, Player& two)
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
			table.getRegions()[i].first.setPoints(1000);
			table.getRegions()[i].second = one;
			one.setBase(table.getRegions()[i].first);
			one.changeScore(1000);
			break;
		}
	}


	std::cout << two.getName() << " alege o baza: ";
	std::cin >> inputNume2;
	//Check ca nu se alege aceeasi baza la amadoi playeri
	while (inputNume1 == inputNume2)
	{
		std::cout << " Baza deja aleasa, introduceti alt nume: ";
		std::cin >> inputNume2;
	}


	inputBase = table.getSpecificRegion(inputNume2);
	two.setBase(inputBase);
	//Adaugat info pentru regiunea aleasa in variable table, pentru al doilea player
	for (int i = 0; i < table.getRegions().size(); i++) {
		if (table.getRegions()[i].first.getName() == inputNume2) {
			table.getRegions()[i].first.setIsBase(true);
			table.getRegions()[i].first.setisOwned(true);
			table.getRegions()[i].first.setPoints(1000);
			table.getRegions()[i].second = two;
			two.setBase(table.getRegions()[i].first);
			two.changeScore(1000);
			break;
		}
	}
	std::cout << std::endl << std::endl;

}

std::pair<int, int> GameConosoleVersion::preGameQuestions2Player(Player& one, Player& two)
{
	//Declarari
	std::pair<int, int> answers;
	answers.first = 0;
	answers.second = 0;
	int num1, num2;
	std::string st1, st2;

	//Luam intrebarile care o sa fie folosite
	QuestionABCD firstQuestion = questions.getRandomQuestionWithVariants(), thirdQuestion = questions.getRandomQuestionWithVariants();
	QuestionNumeric secondQuestion = questions.getRandomQuestionWithNumericAnswer();

	std::cout << "Urmatoarele intrebari determina cate regiuni o sa fie alese de fiecare jucator: \n";
	std::cin.ignore();
	//Prima intrebare
	//Sper ca merge operatorul << nu am testat inca :P
	std::cout << firstQuestion;
	std::cout << "Raspuns de la " << one.getName() << ':';
	std::getline(std::cin, st1);
	std::cout << "Raspuns de la " << two.getName() << ':';
	std::getline(std::cin, st2);

	//Se pun puncte pentru raspunsuri corecte
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
	std::cout << std::endl << secondQuestion << std::endl;
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
	std::cout << std::endl << thirdQuestion << std::endl;
	std::cout << "Raspuns de la " << one.getName() << ':';
	std::cin.ignore();
	std::getline(std::cin, st1);
	std::cout << "Raspuns de la " << two.getName() << ':';
	std::cin.ignore();
	std::getline(std::cin, st2);

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

	std::cout << std::endl << std::endl;
	return answers;

}

void GameConosoleVersion::pickRegion(Player& one, int nrRegions)
{

	std::string nume;
	while (nrRegions != 0)
	{

		std::cout << one.getName() << " alege o regiune de cucerit: ";
		std::cin >> nume;
		for (int i = 0; i < table.getRegions().size(); i++) {
			if (nume == table.getRegions()[i].first.getName()) {
				if (table.getRegions()[i].first.getisOwned() == false) {
					std::cout << nume << " a fost cucerita! \n";
					//Atribuiri
					one.addRegion(table.getRegions()[i].first);
					table.getRegions()[i].first.setisOwned(true);
					table.getRegions()[i].second = one;
					one.changeScore(table.getRegions()[i].first.getPoints());
					nrRegions--;
					//Check daca mai sunt de adaugat
					if (nrRegions == 0)
						break;
				}
			}
		}
		std::cout << "Mai alege o regiune de cucerit: ";
		std::cin >> nume;
	}
}

void GameConosoleVersion::pickRegionByName(Player& one, std::string region)
{
	bool ok = true;
	std::string nume = region;
	std::cout << "A fost aleasa regiunea: " << nume << std::endl;
	while (ok)
	{
		for (int i = 0; i < table.getRegions().size(); i++) {
			if (nume == table.getRegions()[i].first.getName()) {
				if (table.getRegions()[i].first.getisOwned() == false) {
					std::cout << nume << " a fost cucerita! \n";
					//Atribuiri
					one.addRegion(table.getRegions()[i].first);
					table.getRegions()[i].first.setisOwned(true);
					table.getRegions()[i].second = one;
					one.changeScore(table.getRegions()[i].first.getPoints());
					ok = false;
					return;
				}
				else {
					std::cout << "Este deja ocupata, alege o alta regiune de cucerit: ";
					std::cin >> nume;
				}
			}

		}
	}
}

void GameConosoleVersion::attackPlayer(Player& one, Player& two, Region region)
{
	//Eventual o sa trb sa le facem dinamic
	Player aux;
	DuelManager duel;

	std::cout << one.getName() << " a atacat " << two.getName() << "\n";

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
				//Aici .getRegions() creaza un alt obiect
				//trebuie accesat direct
				table.getRegions()[i].second = one;
				one.changeScore(table.getRegions()[i].first.getPoints());
				two.changeScore(-table.getRegions()[i].first.getPoints());
				break;
			}
		}
	}
	else {
		std::cout << "Regiunea ramane in mainile lui " << two.getName();
	}

}

Player GameConosoleVersion::AttackPlayerBase(Player& one, Player& two, Region base)
{
	std::cout << one.getName() << " a atacat " << two.getName() << "\n";

	Player aux;
	DuelManager duel;
	return duel.BaseDuel(questions, one, two, base.getPoints());
}

Region GameConosoleVersion::getRegionByName(std::string nume)
{
	bool ok = true;
	while (ok)
	{
		for (int i = 0; i < table.getRegions().size(); i++) {
			if (nume == table.getRegions()[i].first.getName()) {
				return table.getRegions()[i].first;
			}
		}
		std::string numeNou;
		std::cout << "Nu a fost gasita, reintroduce numele: ";
		std::cin >> numeNou;
		nume = numeNou;
	}


}

void GameConosoleVersion::showStats(Player one, Player two)
{
	std::cout << "Regiuni: " << std::endl;
	for (int i = 0; i < table.getRegions().size(); i++) {
		std::cout << table.getRegions()[i].first.getName() << ": " << table.getRegions()[i].second.getName() << std::endl;
	}
	std::cout << std::endl << "Scoruri: " << std::endl;
	std::cout << one.getName() << ": " << one.getScore() << std::endl;
	std::cout << two.getName() << ": " << two.getScore() << std::endl << std::endl;


}

void GameConosoleVersion::addPlayer(Player one)
{
	players.push_back(one);
}

void GameConosoleVersion::addRegion(Region reg)
{
	this->table.addRegion(reg, Player());

}

Question GameConosoleVersion::getQuestions()
{
	return this->questions;
}

void GameConosoleVersion::ReadQuestion()
{
	questions.addQuestion();
}

void GameConosoleVersion::useAdvantage1(Advantages p)
{
	int contor = 0;
	if(contor==0)
	{p.addAdvantage1(questions,answer);
	contor++;
	}
	else
		std::cout << "Ai folosit deja acest avantaj";

}

void GameConosoleVersion::useAdvantage2(Advantages p)
{
	int contor = 0;
	if (contor = 0)
	{
		p.addAdvantage2(questions);
		contor++;
	}

	else
	{
		std::cout << "Ai folosit deja acest avantaj";
}
}

void GameConosoleVersion::useAdvantage3(Advantages p)
{
	int contor = 0;
	if (contor=0)
		
	{p.addAdvantage3(questions);
	contor++;
	}
	else
	{
		std::cout << "Ai folosit deja acest avantaj";
	}
}

void GameConosoleVersion::StartGame(Player one, Player two, int numberRounds)
{
	//Alegere baze
	chooseBaseStartOfGame2Player(one, two);
	//Intrebri pentru a alege cate regiuni se aleg la inceput de joc
	std::pair<int, int> answersFor3Questions;
	answersFor3Questions = preGameQuestions2Player(one, two);
	pickRegion(one, answersFor3Questions.first);
	pickRegion(two, answersFor3Questions.second);

	//Joc in sine
	DuelManager duel;
	Region reg;
	std::string numeRegiune;

	while (numberRounds != 0)
	{
		//Show stats
		system("cls");
		showStats(one, two);

		//Primul player are o actiune
		std::cout << one.getName() << " alege o regiune pentru actiune: ";
		std::cin >> numeRegiune;
		reg = table.getSpecificRegion(numeRegiune);
		if (reg.getIsBase() == true) {
			for (int i = 0; i < table.getRegions().size(); i++) {
				if (reg.getName() == table.getRegions()[i].first.getName()) {
					if (table.getRegions()[i].second.getName() != one.getName()) {
						std::cout << one.getName() << " a atacat baza lui " << two.getName();
						if (one == AttackPlayerBase(one, two, reg)) {
							std::cout << one.getName() << " A CASTIGAT JOCUL !!!";
							return;
						}
					}
				}
			}

		}
		if (reg.getisOwned()) {
			for (int i = 0; i < table.getRegions().size(); i++) {
				if (reg.getName() == table.getRegions()[i].first.getName()) {
					if (table.getRegions()[i].second == two) {
						attackPlayer(one, two, reg);
					}
					else {
						std::cout << "Este regiunea ta, ai pierdut o tura >:[ \n";
					}
				}
			}
		}
		else {
			//Trebuie modificata sa bag numele regiunii, nu numarul neaparat
			//POate ar trb sa mai fac o alta functie diferita pentru asta
			pickRegionByName(one, numeRegiune);
		}

		system("cls");
		showStats(one, two);

		//Al doilea player are o actiune
		std::cout << two.getName() << " alege o regiune pentru actiune: ";
		std::cin >> numeRegiune;
		reg = table.getSpecificRegion(numeRegiune);
		reg = table.getSpecificRegion(numeRegiune);
		if (reg.getIsBase() == true) {
			for (int i = 0; i < table.getRegions().size(); i++) {
				if (reg.getName() == table.getRegions()[i].first.getName()) {
					if (table.getRegions()[i].second.getName() != two.getName()) {
						std::cout << one.getName() << " a atacat baza lui " << two.getName();
						if (one == AttackPlayerBase(one, two, reg)) {
							std::cout << one.getName() << " A CASTIGAT JOCUL !!!";
							return;
						}
					}
				}
			}
		}
		if (reg.getisOwned()) {
			for (int i = 0; i < table.getRegions().size(); i++) {
				if (reg.getName() == table.getRegions()[i].first.getName()) {
					if (table.getRegions()[i].second == one) {
						attackPlayer(two, one, reg);
					}
					else {
						std::cout << "Este regiunea ta, ai pierdut o tura >:[ \n";
					}
				}
			}
		}
		else {
			//Trebuie modificata sa bag numele regiunii, nu numarul neaparat
			//POate ar trb sa mai fac o alta functie diferita pentru asta
			pickRegionByName(two, numeRegiune);
		}
		//Se scade numarul de ture ramase
		numberRounds--;
	}

	system("cls");
	showStats(one, two);

	if (one.getScore() > two.getScore()) {
		std::cout << one.getName() << "A CASTIGAT JOCUL !!!";
		return;
	}
	if (one.getScore() < two.getScore()) {
		std::cout << two.getName() << "A CASTIGAT JOCUL !!!";
		return;
	}

	std::cout << "SCORUL ESTE EGAL";
}
