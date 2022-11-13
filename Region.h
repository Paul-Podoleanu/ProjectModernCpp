#pragma once
#include <string>
class Region
{
private:
	std::string m_name;
	int m_points;
	bool m_isBase;
	bool m_isFormerBase;
	// Bool pentru inceputul meciului cand fiecare jucator isi alege o regiune de pe harta
	bool m_chooseBase;

public:
	Region();
	
	//Set-eri
	void setName(std::string name);
	void setPoints(int point);
	void setIsBase(bool status);
	void setIsFormerBase(bool status);
	void setChooseBase(bool status);

	//Get-eri
	std::string getName();
	int getPoints();
	bool getIsBase();
	bool getIsFormerBase();
	bool getChooseBase();

};
