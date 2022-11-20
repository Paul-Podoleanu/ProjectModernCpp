#pragma once
#include <iostream>
#include <string>

class Logger
{
public:
	enum class Level
	{
		Info,
		Warning,
		Error
	};

public:
	Logger(std::ostream& os, Level minimumLevel = Level::Info);

	void log(const char* message, Level level);
	void log(const std::string& message, Level level);

	// to do: template for log method
	// template <typename... T>
	// void log(Level level, T... message){};
	
	void setMinimumLogLevel(Level level);

private:
	std::ostream& os;
	Level minimumLevel;
};