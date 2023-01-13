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
		gameManager.setRoundType(Round::NumericQuestion);
		return crow::response(200);
	}
	else if (nr == 3)
	{

		gameManager.setBoardDimension(15);
		gameManager.setLini(5);
		gameManager.setColoane(3);
		gameManager.setQuestionABCDdimension(30);
		gameManager.setQuestionNumericdimension(30);
		gameManager.setRoundType(Round::NumericQuestion);
		return crow::response(201);

	}
	else if (nr == 4)
	{
		this->gameManager.setBoardDimension(24);
		gameManager.setLini(6);
		gameManager.setColoane(4);
		gameManager.setQuestionABCDdimension(30);
		gameManager.setQuestionNumericdimension(30);
		gameManager.setRoundType(Round::NumericQuestion);
		return crow::response(202);
	}
	else
	{
		return crow::response(400);
	}
}
GameManager::GameManager(int size) :roundType(Round::NumericQuestion)
{
	this->coloane = 0;
	this->lini = 0;
	this->playerCount = 0;
	this->regions.resize(size);
	this->players.resize(size);
	this->answerd.resize(size);
	this->rounds.resize(size);
	this->alreadyRequested.resize(size);
	this->regionsOwned = 0;
}
int GameManager::searchPlayer(std::string name)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getName() == name) return i;
	}
}
void GameManager::duelRoundsIncrement()
{
	this->duelRounds++;
}
void GameManager::setDuelRounds()
{
	std::vector<GamePlayer>players = getPlayers();
	int nrRunde;
	int nr = players.size();
	if (nr == 2) nrRunde = 5;
	else if (nr == 3) nrRunde = 4;
	else if (nr == 4) nrRunde = 5;
	while (nrRunde > 0) {
		std::random_device device;
		std::mt19937 g(device());
		std::shuffle(players.begin(), players.end(), g); \
			for (int i = 0; i < players.size(); i++)
			{
				this->duelRanking.push_back(players[i].getName());
			}
		nrRunde--;
	}
}
void GameManager::addPlayerScore(int position, int score)
{
	players[position].setScore(players[position].getScore() + score);
}
bool GameManager::findAlreadyRequested(std::string name)
{
	for (auto s : alreadyRequested)
	{
		if (s == name) return true;
	}
	return false;
}
bool GameManager::isBaseStage()
{
	int nr = 0;
	for (auto c : regions)
	{
		if (c.getIsBase() == true) nr++;
	}
	if (nr == players.size()) return false;
	return true;
}
bool GameManager::isRegionStage()
{
	for (auto c : regions)
	{
		if (c.getIsOwned() == false) return true;
	}
	return false;
}
void GameManager::changeRegionOwner(std::string name, int region)
{
	regions[region].setOwner(name);
	regions[region].setIsBase(false);
	if (roundType == Round::SelectBase)
	{
		regions[region].setPoints(300);
	}
	else regions[region].setPoints(100);
}

void GameManager::createRankingForTeritory(std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare>& a)
{
	while (!answersNumeric.empty())
	{
		int contor = 0;
		while (contor < answersNumeric.size() - 1)
		{
			a.push(answersNumeric.top());
			contor++;
		}
		answersNumeric.pop();
	}
}

void GameManager::addItemsInPq(std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> a)
{
	while (a.empty() == false)
	{
		answersNumeric.push(a.top());
		a.pop();
	}
}

void GameManager::setBase(int region)
{
	regions[region].setIsBase(true);
}

std::string GameManager::getDuelWinner()
{
	if (answersABCD[0].second == true)
	{
		if (answersABCD[1].second == true)
		{
			return "Draw";
		}
		else return answersABCD[0].first;
	}
	if (answersABCD[1].second == true)
	{
		return answersABCD[1].first;
	}
	return "Lost";
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
	return x;
}

crow::response GetRoundType::operator()(const crow::request& req) const
{
	auto url = parseUrlArgs(req.body);
	auto name = url["username"];
	Round a = gameManager.getRoundType();
	if (a == Round::Waiting)
	{
		return crow::response(200, "Waiting");
	}
	else if (a == Round::ABCDQuestion)
	{
		return crow::response(200, "ABCDQuestion");
		if (gameManager.findAlreadyRequested(name))
		{
			return crow::response(400, "AlreadyRequested");
		}
		else
		{
			gameManager.addAlreadyRequested(name);
			return crow::response(200, "ABCDQuestion");
		}
	}
	else if (a == Round::NumericQuestion)
	{
		if (gameManager.findAlreadyRequested(name))
		{
			return crow::response(400, "AlreadyRequested");
		}
		else
		{
			gameManager.addAlreadyRequested(name);
			return crow::response(200, "NumericQuestion");
		}
	}
	else if (a == Round::SelectBase)
	{
		return crow::response(200, "SelectBase");
	}
	else if (a == Round::Duel)
	{
		return crow::response(200, "Duel");
	}
	else if (a == Round::SelectRegions)
	{
		return crow::response(200, "SelectRegions");
	}
	else
	{
		return crow::response(400);
	}
}

crow::response ChangeRoundType::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	if (gameManager.findAlreadyRequested(username))
	{
		return crow::response(400);
	}
	else
	{
		gameManager.addAlreadyRequested(username);
		return crow::response(200);
	}
}

crow::response getNumericAnswers::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto answer = urlArgs["answer"];
	auto x = gameManager.getQuestionNumeric();
	int correctAnswer = x[gameManager.getQuestionNumericCount()].getCorrectAnswer();
	int answer1 = std::abs(correctAnswer - std::stoi(answer));
	auto questions = gameManager.getAnswersNumeric();
	questions.push(std::make_pair(username, answer1));
	gameManager.addAnswersNumeric(std::make_pair(username, answer1));
	if (gameManager.getRegionSelected() != -1)
	{
		auto regions = gameManager.getRegions();
		if (gameManager.getOpponents()[0] == username && gameManager.getOpponents()[1] == username)
		{
			gameManager.addAnswersNumeric(std::make_pair(username, answer1));
			if (gameManager.getAnswersNumeric().size() == gameManager.getOpponents().size())
			{
				gameManager.setQuestionABCDCount(gameManager.getQuestionABCDCount() + 1);
				if (gameManager.getDuelWinner() == gameManager.getOpponents()[0])
				{
					if (regions[gameManager.getRegionSelected()].getPoints() > 100)
					{
						regions[gameManager.getRegionSelected()].setPoints(regions[gameManager.getRegionSelected()].getPoints() - 100);
						gameManager.setRegions(regions);
						gameManager.setRoundType(Round::Duel);
						gameManager.duelRoundsIncrement();
						return crow::response(200);
					}
					else
					{
						regions[gameManager.getRegionSelected()].setOwner(gameManager.getOpponents()[0]);
						gameManager.setRegions(regions);
						gameManager.setRoundType(Round::Duel);
						gameManager.duelRoundsIncrement();
						return crow::response(200, "You won the region");
					}
				}

			}
		}
		else
		{
			return crow::response(200, "You won");
			gameManager.setRoundType(Round::Duel);
		}

	}
	if (gameManager.getAnswersNumeric().size() == gameManager.getNumberOfPlayers())
	{
		gameManager.setQuestionNumericCount(gameManager.getQuestionNumericCount() + 1);
		if (gameManager.isBaseStage())
		{
			gameManager.setRoundType(Round::SelectBase);
		}
		else
		{
			std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> a;
			gameManager.createRankingForTeritory(a);
			gameManager.addItemsInPq(a);
			gameManager.setRoundType(Round::SelectRegions);
		}
		return crow::response(200, "All players answered");
	}
	else
	{
		return crow::response(400);
	}
}
crow::response isYourTurn::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto ordine = gameManager.getAnswersNumeric();
	auto duelRanking = gameManager.getDuelRanking();
	if (gameManager.getRoundType() == Round::Duel)
	{
		if (duelRanking.size() == 0)
		{
			gameManager.setDuelRounds();
			duelRanking = gameManager.getDuelRanking();
		}
		if (duelRanking[gameManager.duelRoundsGet()] == username)
		{
			return crow::response(200);

		}
		else return crow::response(400);
	}
	if (ordine.top().first == username)
	{
		return crow::response(200);
	}
	else
	{
		return crow::response(400);
	}
}

crow::response takeBase::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto index = urlArgs["index"];
	auto regions = gameManager.getRegions();
	auto ordine = gameManager.getAnswersNumeric();
	if (regions[std::stoi(index)].getIsBase() == true)
	{
		return crow::response(200, "Base already owned");
	}
	else
	{
		gameManager.changeRegionOwner(username, std::stoi(index));
		gameManager.setBase(std::stoi(index));
		gameManager.deleteAnswersNumeric();
		gameManager.addRegionsOwned();
		int i = gameManager.searchPlayer(username);
		gameManager.addPlayerScore(i, 300);
		if (gameManager.isBaseStage() == false)
		{
			Sleep(2500);
			gameManager.setRoundType(Round::NumericQuestion);
			gameManager.alreadyRequestedClear();
		}
		return crow::response(200, "Base taken");
	}
}

crow::response takeRegion::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto index = urlArgs["index"];
	auto regions = gameManager.getRegions();
	auto ordine = gameManager.getAnswersNumeric();
	if (regions[std::stoi(index)].getOwner() == username)
	{
		return crow::response(200, "Region already owned");
	}
	else
	{
		gameManager.changeRegionOwner(username, std::stoi(index));
		gameManager.deleteAnswersNumeric();
		gameManager.addRegionsOwned();
		int i = gameManager.searchPlayer(username);
		gameManager.addPlayerScore(i, 100);
		int a = gameManager.getRegionsOwned();
		if (gameManager.getAnswersNumeric().size() == 0 && gameManager.getRegionsOwned() != gameManager.getRegions().size()) {
			gameManager.setRoundType(Round::NumericQuestion);
			gameManager.alreadyRequestedClear();
		}
		if (gameManager.getRegionsOwned() == gameManager.getRegions().size())
		{
			gameManager.setRoundType(Round::Duel);
		}
		return crow::response(200, "Region taken");
	}
}
crow::response clickedForDuel::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto attacker = urlArgs["username"];
	auto index = urlArgs["index"];
	auto defender = urlArgs["username2"];
	if (gameManager.getDuelRanking().size() == 0)
	{
		gameManager.setDuelRounds();
	}
	std::vector<std::string> opponents;
	opponents.push_back(attacker);
	opponents.push_back(defender);
	gameManager.setOpponents(opponents);
	gameManager.setRoundType(Round::ABCDQuestion);
	return crow::response(200);
}

crow::response getMultipleAnswers::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto answer = urlArgs["answer"];
	auto index = gameManager.getRegionSelected();
	auto regions = gameManager.getRegions();
	auto x = gameManager.getQuestionABCD();
	auto correctAnswer = x[gameManager.getQuestionABCDCount()].getCorrectAnswer();
	bool ok = 0;
	if (answer == correctAnswer)
	{
		ok = 1;
	}
	for (auto c : gameManager.getOpponents())
	{
		if (username == c)
		{
			gameManager.addAnswersABCD(std::make_pair(username, ok));
		}
	}
	if (gameManager.getOpponents().size() == gameManager.getAnswersABCD().size())
	{
		gameManager.setQuestionABCDCount(gameManager.getQuestionABCDCount() + 1);
		if (gameManager.getDuelWinner() == username)
		{
			if (regions[(index)].getPoints() > 100)
			{
				regions[(index)].setPoints(regions[(index)].getPoints() - 100);
			}
			else
			{
				regions[(index)].setOwner(username);
			}
			gameManager.setRoundType(Round::Duel);
			gameManager.duelRoundsIncrement();
			gameManager.setRegions(regions);
			return crow::response(200, "You won");
		}
		else if (gameManager.getDuelWinner() == "Draw")
		{
			gameManager.setRoundType(Round::NumericQuestion);
			return crow::response(200, "Draw");
		}
		else if (gameManager.getDuelWinner() == "Lost")
		{
			gameManager.setRoundType(Round::Duel);
			return crow::response(200, "You lost");
		}
	}
	else
	{
		return crow::response(400);
	}
}
