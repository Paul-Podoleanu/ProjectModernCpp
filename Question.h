#pragma once
#include <vector>
#include <string>
#include "QuestionABCD.h"
#include "QuestionNumeric.h"
#include <iostream>
#include <fstream>
class Question
{

private:
	std::vector<QuestionABCD>m_QuestionsWithVariants;
	std::vector<QuestionNumeric>m_QuestionWithNumericAnswer;
public:
	void addQuestion();
	void writeQuestion();

};

