#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>

#include <cpr/cpr.h>
#include <crow.h>

int  main()
{
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:8080" });

    std::cout << "Welcome!" << std::endl;
    std::cout << "Please enter your username and password: ";
    std::string input;
    std::cin >> input;
    return 0;
}
