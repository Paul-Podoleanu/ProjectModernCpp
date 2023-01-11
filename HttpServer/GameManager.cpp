#include "GameManager.h"
crow::response StartGameHandler::operator() (const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto player1 = urlArgs["player1"];
	auto player2 = urlArgs["player2"];
	auto player3 = urlArgs["player3"];
	auto player4 = urlArgs["player4"];
	GamePlayer p1(player1, 0);
	GamePlayer p2(player2, 0);
	gameManager.addPlayer(p1);
	gameManager.addPlayer(p2);
	if (player3 != "Empty")
	{
		GamePlayer p3(player3, 0);
		gameManager.addPlayer(p3);

	}
	if (player4 != "Empty")
	{
		GamePlayer p4(player4, 0);
		gameManager.addPlayer(p4);

	}
	gameManager.setPlayerCount(gameManager.getNumberOfPlayers());
	auto nr = gameManager.getNumberOfPlayers();
	if (nr == 2)
	{
		gameManager.setBoardDimension(9);
		gameManager.setLini(3);
		gameManager.setColoane(3);
		gameManager.setQuestionABCDdimension(30);
		gameManager.setQuestionNumericdimension(30);
		return crow::response(200);
	}
	else if (nr == 3)
	{

		gameManager.setBoardDimension(15);
		gameManager.setLini(5);
		gameManager.setColoane(3);
		gameManager.setQuestionABCDdimension(30);
		gameManager.setQuestionNumericdimension(30);
		return crow::response(201);
	}
	else if (nr == 4)
	{
		this->gameManager.setBoardDimension(24);
		gameManager.setLini(6);
		gameManager.setColoane(4);
		gameManager.setQuestionABCDdimension(30);
		gameManager.setQuestionNumericdimension(30);
		return crow::response(202);
	}
	else
	{
		return crow::response(400);
	}
}
GameManager::GameManager(int size)
{
	this->coloane = 0;
	this->lini = 0;
	this->playerCount = 0;
	this->regions.resize(size);
	this->players.resize(size);
	this->answerd.resize(size);
	this->rounds.resize(size);
	this->roundType = 0;
}
crow::response StartedHandler::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	if (gameManager.getNumberOfPlayers() >= 2)
	{
		return crow::response(200);
	}
	else
	{
		return crow::response(400);
	}
}

crow::json::wvalue GetQuestionABCDHandler::operator()(const crow::request& req) const
{
	crow::json::wvalue x;
	auto questions = gameManager.getQuestionABCD();
	x["question"] = questions[gameManager.getQuestionABCDCount()].getQuestion();
	x["answerA"] = questions[gameManager.getQuestionABCDCount()].getAnswerA();
	x["answerB"] = questions[gameManager.getQuestionABCDCount()].getAnswerB();
	x["answerC"] = questions[gameManager.getQuestionABCDCount()].getAnswerC();
	x["answerD"] = questions[gameManager.getQuestionABCDCount()].getAnswerD();
	gameManager.setQuestionABCDCount(gameManager.getQuestionABCDCount() + 1);
	return x;
}

crow::json::wvalue GetQuestionNumericHandler::operator()(const crow::request& req) const
{
	crow::json::wvalue x;
	auto questions = gameManager.getQuestionNumeric();
	x["question"] = questions[gameManager.getQuestionNumericCount()].getQuestion();
	gameManager.setQuestionNumericCount(gameManager.getQuestionNumericCount() + 1);
	return x;
}
