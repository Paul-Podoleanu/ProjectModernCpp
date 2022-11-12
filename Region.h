#pragma once
#include <string>
class Region
{
private:
	std::string m_name;
	int m_points;
	bool m_isBase;

public:
	Region();

	//Set-eri
	void setName(std::string name);
	void setPoints(int point);
	void setIsBase(bool status);

	//Get-eri
	std::string getName();
	int getPoints();
	bool getIsBase();

};

