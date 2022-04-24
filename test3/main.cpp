#include <iostream>
#include <fstream>
#include "config_io.h"

int main() {
	std::string filename = "D:\\text.txt";
	std::string filename2 = "D:\\text2.txt";

	libconf::config_io config;

	config.fill_buffer(filename2);

	config.show_buffer();

	config.dump_buffer(filename2);

	return 0;
}