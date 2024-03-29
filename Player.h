#pragma once
#include <string>
#include <vector>
#include <iostream>
#include"Region.h"
#include"Advantages.h"

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
	std::vector<Region> m_regions;
	Region m_base;


public:
	//Constructori
	Player();
	Player(std::string name, std::string color, int score, bool active, std::vector<Region>regions, Region m_base);
	//Destructor
	~Player();

	//Set
	void setName(std::string m_name);
	void setColor(std::string m_color);
	void setBase(Region m_base);
	void setScore(int scor);

	//Get
	int getScore();
	std::string getName();
	bool getActive();
	std::string getColor();
	Region getBase()	;

	//Deactivare player pentru cand pierde sau se deconecteaza de la joc
	void deactivate_player();
	void reactivatePlayer();
	

	//Functii pentru gameplay
	//Ajustare scor, numarul poate fi pozitiv sau negativ
	void changeScore(int dif);
	void addRegion(Region newRegion);
	void loseRegion(Region lostRegion);
	void getPlayerHistory();

	//Overload operator
	Player& operator=(const Player& player);
	bool operator== (const Player& player) const;
	// overload operator <<
	friend std::ostream& operator<<(std::ostream& out, const Player& player);
	friend std::istream& operator>>(std::istream& in, const Player& player);
};

