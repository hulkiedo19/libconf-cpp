#include <iostream>
#include <fstream>
#include <vector>
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
		if (this->filename.empty()) {
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

	//---------

	std::string config_io::get_buffer() {
		if (this->buffer.empty()) {
			return std::string();
		}

		return this->buffer;
	}

	void config_io::show_buffer() {
		if (this->buffer.empty()) {
			std::cout << "buffer is empty" << std::endl;
			return;
		}

		std::cout << "buffer:" << std::endl << this->buffer << std::endl;
	}

	bool config_io::dump_buffer() {
		if (this->filename.empty())
			return false;

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

	//---------

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
		if (this->buffer.empty())
			return false;

		const char delimeter = '\n';

		std::size_t line_count = 1;
		std::size_t start_position = 0;
		std::size_t end_position;
		std::string token;

		while ((end_position = this->buffer.find(delimeter, start_position)) != std::string::npos) {
			token = this->buffer.substr(start_position, end_position - start_position);

			if (token.find(name) != std::string::npos) {
				if (this->buffer.length() == (end_position - start_position + 1)) {
					this->buffer.clear();
				} else {
					this->buffer.erase(start_position, end_position - start_position + 1);
				}

				break;
			}

			start_position = end_position + 1;
		}

		return true;
	}

	bool config_io::replace_value(std::string name, std::string new_value) {
		if (this->buffer.empty())
			return false;

		return true;
	}

	bool config_io::value_exists(std::string name) {
		if (this->buffer.empty())
			return false;

		return false;
	}

	std::string config_io::get_value(std::string name) {
		if (this->buffer.empty())
			return std::string();

		return std::string();
	}

	//---------

	std::vector<std::string> config_io::get_split_value(std::string name) {
		if (this->buffer.empty())
			return std::vector<std::string>();

		std::vector<std::string> split;

		return split;
	}

	void config_io::show_split_value(std::string name) {
		if (this->buffer.empty())
			return;
	}

	//---------

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
		if (this->buffer.empty())
			return false;

		const char delimeter = '\n';

		std::size_t line_count = 1;
		std::size_t start_position = 0;
		std::size_t end_position;

		while ((end_position = this->buffer.find(delimeter, start_position)) != std::string::npos) {
			if (line_count == line_number) {
				if (this->buffer.length() == (end_position - start_position + 1)) {
					this->buffer.clear();
					break;
				}

				this->buffer.erase(start_position, end_position - start_position + 1);
				break;
			}

			start_position = end_position + 1;
			line_count++;
		}

		return true;
	}

}