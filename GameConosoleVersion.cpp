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
	while (inputNume1==inputNume2)
	{
		std::cout << "Baza deja aleasa, introduceti alt nume: ";
		std::cin >> inputNume2;
	}


	inputBase = table.getSpecificRegion(inputNume2);
	one.setBase(inputBase);
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
