#pragma once
#include <string>
#include <vector>
#include"Region.h"

//Clasa este pentru un player in-game, nu pentru un cont
class Player
{
private:
	//Screen name
	std::string m_name;
	int m_score;
	std::string m_color;
	//Tine cont daca este sau nu scos din joc/daca a pierdut
	bool m_active;

	/*O sa trebuiasca sa fie asociat unui cont
	 Pentru asta o sa trebuiasca sa facem mai intai Account Manager */

	 /*O sa fie necesar sa ii fie atribuite si anumite regiuni precum si o baza
	 Pentru asta o sa trb sa facem mai intai clasa Region*/
	std::vector<Region>m_region;
	Region m_base;


public:
	//Constructori
	Player();
	//Destructor
	~Player();
	//Set-eri
	void setName(std::string m_name);
	void setScore(int m_score);
	void setColor(std::string m_color);
	void setBase(Region m_baza);
	//Get-eri
	int getScore();
	std::string getName();
	bool getActive();
	std::string getColor();
	//Deactivare player pentru cand pierde sau se deconecteaza de la joc
	void deactivate_player();
	Region getBase();

	//Ajustare cod, numarul poate fi pozitiv sau negativ
	void changeScore(int dif);

};

