#include "Debug.hpp"

void logThis(std::string s){
	std::ofstream file;
	file.open("log.txt");
	file << s << std::endl;
	file.close();
}

void printThis(std::string s){
	std::cout << s << std::endl;
}
