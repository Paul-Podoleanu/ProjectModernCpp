#pragma once
#include <iostream>
#include "Question.h"
#include"Region.h"
class Advantages
{
private:
	std::string ans;
	const int advantageCost = 100;
	Region region;
public:

	Advantages();
	~Advantages();
	bool checkRegionScore(Region targetRegion);
	void addAdvantage1(Question& question, QuestionABCD ans);
	void addAdvantage2(Question& question);
	void addAdvantage3(Question& question);
	/*Asta ar trebui mutata in clasa Region, nu are rost sa fie aici si poate sa cauzeze
	conflict cand includem header-ul in alta clasa deoarece include clasa Region.h - Paul*/
	void changeRegionScore(Region thisRegion);

};

