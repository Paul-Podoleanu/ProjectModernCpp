#include "Advantages.h"
QuestionNumeric q;
Region r;
int nrAdv1 = 0;
int nrAdv2 = 0;
int nrAdv3 = 0;

Advantages::Advantages()
{
}

Advantages::~Advantages()
{
}

bool Advantages::checkRegionScore(Region targetRegion)
{
	if (this->region.getPoints() > 100)
		return true;
	else
		return false;
}

void Advantages::addAdvantage1(Question& question, QuestionABCD answers)
{
	if (checkRegionScore(region))
	{
		if (nrAdv1 == 0)
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
			nrAdv1++;
		}
		else
			std::cout << "You can't use this advantage anymore";
	}
	else
		std::cout << "The region score is too low to use this advantage";

}

void Advantages::addAdvantage2(Question& question)
{
	if (checkRegionScore(region))
	{
		if (nrAdv2 == 0)
		{
			q.getCorrectAnswer();
			std::cout << "First possible answers is :" << q << " + >>10-25<<" << std::endl;
			std::cout << "First possible answers is :" << q << " + >>25-40<<" << std::endl;
			std::cout << "First possible answers is :" << q << " + >>40-55<<" << std::endl;
			std::cout << "First possible answers is :" << q << " + >>55-60<<" << std::endl;
			changeRegionScore(r);
			nrAdv2++;
		}
		else
			std::cout << "You can't use this advantage anymore";
	}
	else
		std::cout << "The region score is too low to use this advantage";
}

void Advantages::addAdvantage3(Question& question)
{
	if (checkRegionScore(region))
	{
		if (nrAdv3 == 0)
		{
			q.getCorrectAnswer();
			std::cout << "The answer is between " << q << "+5" << " and " << q << "-5";
			changeRegionScore(r);
			nrAdv3++;
		}
		else
			std::cout << "You can't use this advantage anymore";
	}
	else
		std::cout << "The region score is too low to use this advantage";
}

void Advantages::changeRegionScore(Region thisRegion)
{
	thisRegion.setPoints(thisRegion.getPoints() - advantageCost);
}
