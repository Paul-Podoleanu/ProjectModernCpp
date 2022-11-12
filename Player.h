#pragma once
#include <string>
#include <vector>

//Clasa este pentru un player in-game, nu pentru un cont
class Player
{
private:
	//Screen name
	std::string m_name;
	int m_score;
	//Tine cont daca este sau nu scos din joc/daca a pierdut
	bool m_active;

	/*O sa trebuiasca sa fie asociat unui cont 
	 Pentru asta o sa trebuiasca sa facem mai intai Account Manager */

	/*O sa fie necesar sa ii fie atribuite si anumite regiuni precum si o baza
	Pentru asta o sa trb sa facem mai intai clasa Region*/



public:
	//Constructori
	Player();
	
	//Set-eri
	void setName();
	void setScore();

	//Get-eri
	int getScore();
	std::string getName();
	bool getActive();
};

