#pragma once

namespace libconf {

	class config_io {
		std::string filename;
		std::string buffer;
	public:
		config_io();
		config_io(std::string filename);
		~config_io();

		// buffer
		std::string get_buffer();
		void show_buffer();
		bool fill_buffer(std::string filename);
		bool dump_buffer();
		bool dump_buffer(std::string filename);

		// values
		bool append_value(std::string name, std::string value);
		bool delete_value(std::string name);
		bool replace_value(std::string name, std::string new_value);
		bool value_exists(std::string name);
		std::string get_value(std::string name);

		// split
		std::vector<std::string> get_split_value(std::string name);
		void show_split_value(std::string name);

		// lines
		bool append_line(std::string data);
		bool delete_line(std::string line);
		bool delete_line(int line_number);
	};

}