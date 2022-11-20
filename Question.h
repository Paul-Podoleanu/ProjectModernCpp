#pragma once
#include <vector>
#include <string>
#include "QuestionABCD.h"
#include "QuestionNumeric.h"
#include <iostream>
#include <random>
#include <fstream>
class Question
{

private:
	std::vector<QuestionABCD>m_QuestionsWithVariants;
	std::vector<QuestionNumeric>m_QuestionWithNumericAnswer;
public:
	void addQuestion();
	void writeQuestionWithVar();
	void writeQuestionWithNumeric();
	QuestionABCD getRandomQuestionWithVariants();
	QuestionNumeric getRandomQuestionWithNumericAnswer();
};