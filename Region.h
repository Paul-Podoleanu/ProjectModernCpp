#pragma once
#include <string>
#include<vector>
class Region
{
private:
	std::string m_name;
	int m_points;
	bool m_isBase;
	bool m_isFormerBase;
	// Bool pentru inceputul meciului cand fiecare jucator isi alege o regiune de pe harta
	bool isOwned;
	//Aici se trec vecinii unei regiuni
	//std::vector<Region> neighbours;

public:
	Region();
	Region(std::string name, int points, bool isBase, bool isFormerBase, bool isOwned);
	
	//Set-eri
	void setName(std::string name);
	void setPoints(int point);
	void setIsBase(bool status);
	void setIsFormerBase(bool status);
	void setisOwned(bool status);
	//void setOwner(Player p);
	//Get-eri
	std::string getName();
	int getPoints();
	bool getIsBase();
	bool getIsFormerBase();
	bool getisOwned();
	//Overload Operatori
	bool operator==(const Region& region) const;
	Region& operator=(const Region& region);
	//Functii pentru joc
};

