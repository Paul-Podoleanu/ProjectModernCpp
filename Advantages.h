#pragma once
#include <iostream>
#include "Question.h"
#include"Region.h"
class Advantages
{
private:
	std::string ans;
	const int advantageCost = 100;
public:
	Advantages();
	~Advantages();
	void addAdvantage1(Question& question, QuestionABCD ans);
	void addAdvantage2(Question& question);
	void addAdvantage3(Question& question);
	void changeRegionScore(Region thisRegion);

};

