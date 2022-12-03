#include "Advantages.h"
QuestionNumeric q;
Region r;

Advantages::Advantages()
{
}

Advantages::~Advantages()
{
}

void Advantages::addAdvantage1(Question& question, QuestionABCD answers)
{
	question.getRandomQuestionWithVariants();
	this->ans = answers.getCorrectAnswer();
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
		else if (ans == answers.getAnswerB())
		{
			srand(time(NULL));

			int randNum = (rand() % 3) + 1;
			if (randNum == 1)

			{
				std::cout << "The correct answer is between answer A and answer B";
			}
			else if (randNum == 2)
			{
				std::cout << "The correct answer is between answer B and answer C";
			}
			else if (randNum == 3)
			{
				std::cout << "The correct answer is between answer B and answer D";
			}

		}
		else if (ans == answers.getAnswerC())
		{
			srand(time(NULL));

			int randNum = (rand() % 3) + 1;
			if (randNum == 1)

			{
				std::cout << "The correct answer is between answer A and answer C";
			}
			else if (randNum == 2)
			{
				std::cout << "The correct answer is between answer B and answer C";
			}
			else if (randNum == 3)
			{
				std::cout << "The correct answer is between answer C and answer D";
			}
		}
		else if (ans == answers.getAnswerD())
		{
			srand(time(NULL));

			int randNum = (rand() % 3) + 1;
			if (randNum == 1)

			{
				std::cout << "The correct answer is between answer A and answer D";
			}
			else if (randNum == 2)
			{
				std::cout << "The correct answer is between answer B and answer D";
			}
			else if (randNum == 3)
			{
				std::cout << "The correct answer is between answer C and answer D";
			}
		}

	}
	changeRegionScore(r);

}

void Advantages::addAdvantage2(Question& question)
{
	q.getCorrectAnswer();
	std::cout << "First possible answers is :" << q << " + >>10-25<<" << std::endl;
	std::cout << "First possible answers is :" << q << " + >>25-40<<" << std::endl;
	std::cout << "First possible answers is :" << q << " + >>40-55<<" << std::endl;
	std::cout << "First possible answers is :" << q << " + >>55-60<<" << std::endl;
	changeRegionScore(r);
}

void Advantages::addAdvantage3(Question& question)
{
	q.getCorrectAnswer();
	std::cout << "The answer is between " << q << "+5" << " and " << q << "-5";
	changeRegionScore(r);
}

void Advantages::changeRegionScore(Region thisRegion)
{
	thisRegion.setPoints(thisRegion.getPoints() - advantageCost);
}
