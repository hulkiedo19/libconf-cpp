#include <iostream>
#include <fstream>
#include "config_io.h"

int main() {
	std::string filename = "D:\\text.txt";

	libconf::ConfigIO config(filename);

	config.ShowBuffer();

	/*
	std::string line = "hello_world2\n";
	if (!config.DeleteLine(line)) {
		std::cout << "this line does not exists" << std::endl;
	}

	config.ShowBuffer();
	*/

	return 0;
}