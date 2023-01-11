#pragma once
#include "DuelManager.h"
#include "Game.h"
#include "Question.h"
#include <vector>
#include "GamePlayer.h"
class GameManager
{
	std::vector<GamePlayer> players;
	std::vector<Region> regions;
	std::vector<std::string > answerd;
	std::vector<std::string > rounds;
	std::vector<QuestionABCD>multipleAnswerQuestion;
	std::vector<QuestionNumeric>numericAnswerQuestion;
	int roundType;
	//DuelManager DuelManager;
	int playerCount;
	int questionABCDcount = 0;
	int questionNumericCount = 0;
	int lini, coloane;
public:
	GameManager(int size = 0);
	void setPlayerCount(int playerCount) { this->playerCount = playerCount; }
	int getPlayerCount() const { return this->playerCount; }
	int getNumberOfPlayers() { return players.size(); }
	void setBoardDimension(int playerCount) { regions.resize(playerCount); }
	void setLini(int lini) { this->lini = lini; }
	void setColoane(int coloane) { this->coloane = coloane; }
	void setPlayers(std::vector<GamePlayer> players) { this->players = players; }
	void addPlayer(GamePlayer player) { players.push_back(player); }
	void setQuestionABCD(std::vector<QuestionABCD> multipleAnswerQuestion) { this->multipleAnswerQuestion = multipleAnswerQuestion; }
	void setQuestionNumeric(std::vector<QuestionNumeric> numericAnswerQuestion) { this->numericAnswerQuestion = numericAnswerQuestion; }
	int getQuestionABCDCount() { return this->questionABCDcount; }
	int getQuestionNumericCount() { return this->questionNumericCount; }
	void setQuestionABCDCount(int questionABCDcount) { this->questionABCDcount = questionABCDcount; }
	void setQuestionNumericCount(int questionNumericCount) { this->questionNumericCount = questionNumericCount; }
	std::vector<QuestionABCD> getQuestionABCD() { return this->multipleAnswerQuestion; }
	std::vector<QuestionNumeric> getQuestionNumeric() { return this->numericAnswerQuestion; }
	void setQuestionABCDdimension(int nr) { this->multipleAnswerQuestion.resize(nr); }
	void setQuestionNumericdimension(int nr) { this->numericAnswerQuestion.resize(nr); }
};

//HANDLERS

class StartGameHandler
{
	GameManager& gameManager;
public:
	StartGameHandler(GameManager& gameManager) : gameManager(gameManager) {}
	crow::response operator()(const crow::request& req) const;
};
class StartedHandler
{
	GameManager& gameManager;
public:
	StartedHandler(GameManager& gameManager) : gameManager(gameManager) {}
	crow::response operator()(const crow::request& req) const;
};
class GetQuestionABCDHandler
{
	GameManager& gameManager;
public:
	GetQuestionABCDHandler(GameManager& gameManager) : gameManager(gameManager) {}
	crow::json::wvalue operator()(const crow::request& req) const;
};
class GetQuestionNumericHandler
{
	GameManager& gameManager;
public:
	GetQuestionNumericHandler(GameManager& gameManager) : gameManager(gameManager) {}
	crow::json::wvalue operator()(const crow::request& req) const;
};