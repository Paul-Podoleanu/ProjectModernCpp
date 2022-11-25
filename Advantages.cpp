#include "Advantages.h"

Advantages::Advantages()
{
}

Advantages::~Advantages()
{
}

void Advantages::addAdvantage1(Question& question,QuestionABCD answers)
{
	question.getRandomQuestionWithVariants();
	this->ans=answers.getCorrectAnswer();
	if (ans == answers.getAnswerA())
	{
		srand(time(NULL));

		int randNum = (rand() % 3) + 1;
		if (randNum == 1)

		{
			std::cout << "The correct answer is between answer A and answer B";
		}
		else if (randNum == 2)
		{
			std::cout << "The correct answer is between answer A and answer C";
		}
		else if (randNum == 3)
		{
			std::cout << "The correct answer is between answer A and answer D";
		}

	}
		
}

void Advantages::addAdvantage2(Question& question)
{
}

void Advantages::addAdvantage3(Question& question)
{
}

void Advantages::changeRegionScore(Region thisRegion)
{
	thisRegion.setPoints(thisRegion.getPoints()-advantageCost);
}
