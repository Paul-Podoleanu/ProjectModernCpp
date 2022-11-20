#include <iostream>
#include <string>
#include <chrono>
void timer()
{

	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	using Duration = std::chrono::duration<double>;
	TimePoint start = Clock::now();
	std::cout << "Enter a string: ";
	std::string s;
	std::cin >> s;
	TimePoint end = Clock::now();
	Duration elapsed = end - start;
	std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}
