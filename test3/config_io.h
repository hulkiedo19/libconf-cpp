#pragma once

class config_io {
	std::string filename;
	std::string line;

	std::ifstream input_file;
	std::ofstream output_file;
public:
	config_io(std::string filename);

	void AppendLine(std::string data);

	std::string ReadLine();

	void ReadFile();

	std::string ReadFileToString();
};