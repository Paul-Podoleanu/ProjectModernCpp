#pragma once
#include <iostream>
#include <string>

#ifdef LOGGING_EXPORTS
#define LOGGING_API __declspec(dllexport)
#else
#define LOGGING_API __declspec(dllimport)
#endif //LOGGING_EXPORTS

class LOGGING_API Logger
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

	template<class T>
	void log(T message, Level level)
	{
		if (static_cast<int>(level) < static_cast<int>(minimumLevel))
			return;

		std::string aux;
		switch (level)
		{
		case Level::Info:
		{
			aux = "Info";
			break;
		}
		case Level::Warning:
		{
			aux = "Warning";
			break;
		}
		case Level::Error:
		{
			aux = "Error";
			break;
		}
		default:
			aux = "";
			break;
		}

		os << "[" << aux << "] " << message << std::endl;
	}
	
	void setMinimumLogLevel(Level level);

private:
	std::ostream& os;
	Level minimumLevel;
};