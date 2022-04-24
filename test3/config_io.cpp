#include <iostream>
#include <fstream>
#include <string>

#include "config_io.h"

namespace libconf {

	config_io::config_io() {
		this->buffer.clear();
		this->filename.clear();
	}

	config_io::config_io(std::string filename) {
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

	config_io::~config_io() {
		if (this->filename.empty() || this->buffer.empty()) {
			return;
		}

		std::ofstream output_file(this->filename);

		if (output_file.is_open()) {
			output_file << this->buffer;
			output_file.flush();
		}

		output_file.close();

		this->buffer.clear();
		this->filename.clear();
	}

	//--------------------------------------------------------------//

	std::string config_io::get_buffer() {
		if (this->buffer.empty()) {
			return std::string();
		}

		return this->buffer;
	}

	void config_io::show_buffer() {
		if (this->buffer.empty()) {
			return;
		}

		std::cout << "buffer:" << std::endl << this->buffer << std::endl;
	}

	bool config_io::dump_buffer() {
		if (this->filename.empty() || this->buffer.empty()) {
			return false;
		}

		std::ofstream output_file(this->filename);

		if (output_file.is_open()) {
			output_file << this->buffer;
			output_file.flush();
		}

		output_file.close();

		this->buffer.clear();
		this->filename.clear();
	}

	bool config_io::dump_buffer(std::string filename) {
		if (this->buffer.empty())
			return false;

		std::ofstream output_file(filename);

		if (output_file.is_open()) {
			output_file << this->buffer;
			output_file.flush();
		}

		output_file.close();

		this->buffer.clear();
		this->filename.clear();
		return true;
	}

	bool config_io::fill_buffer(std::string filename) {
		if (!this->buffer.empty())
			return false;

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
		return true;
	}

	//--------------------------------------------------------------//

	bool config_io::append_value(std::string name, std::string value) {
		std::string variable = name + "=" + value + "\n";
		if (this->buffer.empty()) {
			this->buffer = variable;
		} else {
			this->buffer += variable;
		}

		return true;
	}

	bool config_io::delete_value(std::string name) {
		return false;
	}

	//--------------------------------------------------------------//

	bool config_io::append_line(std::string line) {
		if (this->buffer.empty()) {
			this->buffer = line + "\n";
		} else {
			this->buffer += line + "\n";
		}

		return true;
	}

	bool config_io::delete_line(std::string line) {
		if (this->buffer.empty())
			return false;

		size_t position;
		if ((position = this->buffer.find(line)) == std::string::npos) {
			return false;
		}

		this->buffer.erase(position, line.length());
	}

	bool config_io::delete_line(int line_number) {
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