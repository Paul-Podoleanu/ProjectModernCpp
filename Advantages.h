#pragma once
#include "Question.h"
#include"Region.h"
class Advantages
{
private:
	const int advantageCost = 100;
public:
	void addAdvantage1(Question& question);
	void addAdvantage2(Question& question);
	void addAdvantage3(Question& question);
	void changeRegionScore(Region thisRegion);

};

