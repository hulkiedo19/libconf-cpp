#include <iostream>
#include <fstream>
#include <string>

#include "config_io.h"

namespace libconf {

	ConfigIO::ConfigIO(std::string filename) {
		this->buffer = "";
		this->filename = filename;

		std::ifstream input_file(this->filename);

		if (input_file.is_open()) {
			std::string line;
			while (std::getline(input_file, line)) {
				buffer += (line + "\n");
			}
		}

		input_file.close();
	}

	ConfigIO::~ConfigIO() {
		std::ofstream output_file(this->filename);

		if (output_file.is_open()) {
			output_file << this->buffer;
			output_file.flush();
		}

		output_file.close();

		this->buffer.clear();
		this->filename.clear();
	}

	std::string ConfigIO::GetBuffer() {
		return this->buffer;
	}

	void ConfigIO::ShowBuffer() {
		std::cout << "buffer:" << std::endl << this->buffer << std::endl;
	}

	bool ConfigIO::AppendLine(std::string line) {
		if (buffer.length() == 0) {
			this->buffer = line + "\n";
		}
		else {
			this->buffer += line + "\n";
		}
		return true;
	}

	bool ConfigIO::DeleteLine(std::string line) {
		if (this->buffer.length() == 0)
			return false;

		size_t position;
		if ((position = this->buffer.find(line)) == std::string::npos) {
			return false;
		}

		this->buffer.erase(position, line.length());
	}

	bool ConfigIO::DeleteLine(int line_number) {
		//std::string delimeter = "\n";
		//std::string sub_buffer = this->buffer;

		return false;
	}

}
//std::string config_io::ReadLine() {
//	bool is_clear_flag = false;
//	static int current_line = 0;
//
//	input_file.open(filename);
//
//	if (input_file.is_open()) {
//		int cur_line = 0;
//
//		do {
//			if (!std::getline(input_file, line)) {
//				std::cout << std::endl << "counter is cleared to 0" << std::endl;
//				current_line = 0;
//				is_clear_flag = true;
//				break;
//			}
//		} while (cur_line++ < current_line);
//	}
//
//	input_file.close();
//
//	if (!is_clear_flag) current_line++;
//
//	return line;
//}