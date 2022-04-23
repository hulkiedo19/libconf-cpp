#include <iostream>
#include <fstream>
#include "config_io.h"

int main() {
	std::string filename = "D:\\text.txt";

	config_io config(filename);

	/*
	config.ReadFile();
	config.AppendLine("hello_world-1");

	std::cout << std::endl;
	config.ReadFile();

	std::cout << config.ReadLine() << std::endl;
	*/

	std::string fileData = config.ReadFileToString();
	std::cout << "file data:" << std::endl << fileData << std::endl;

	return 0;
}