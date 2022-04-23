#include <iostream>
#include <fstream>
#include <string>

#include "config_io.h"

config_io::config_io(std::string filename) {
	this->filename = filename;
}

void config_io::AppendLine(std::string data) {
	output_file.open(filename, std::ios::app);

	if (output_file.is_open()) {
		output_file << data << std::endl;
	}

	output_file.close();
}

std::string config_io::ReadLine() {
	bool is_clear_flag = false;
	static int current_line = 0;

	input_file.open(filename);

	if (input_file.is_open()) {
		int cur_line = 0;

		do {
			if (!std::getline(input_file, line)) {
				std::cout << std::endl << "counter is cleared to 0" << std::endl;
				current_line = 0;
				is_clear_flag = true;
				break;
			}
		} while (cur_line++ < current_line);
	}

	input_file.close();

	if (!is_clear_flag) current_line++;

	return line;
}

void config_io::ReadFile() {
	input_file.open(filename);

	if (input_file.is_open()) {
		std::cout << "file: " << filename << std::endl;
		while (std::getline(input_file, line)) {
			std::cout << line << std::endl;
		}
	}

	input_file.close();
}

std::string config_io::ReadFileToString() {
	std::string buffer = "";

	input_file.open(filename);

	if (input_file.is_open()) {
		std::cout << "file: " << filename << std::endl;
		while (std::getline(input_file, line)) {
			buffer += (line + "\n");
		}
	}

	input_file.close();

	return buffer;
}