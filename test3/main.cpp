#include <iostream>
#include <fstream>
#include <vector>
#include "config_io.h"

int main() {
	std::string filename = "D:\\text.txt";
	//std::string filename2 = "D:\\text2.txt";

	libconf::config_io config(filename);

	std::cout << config.get_value("hello1") << std::endl;
	std::cout << config.get_value("hello2") << std::endl;

	return 0;
}