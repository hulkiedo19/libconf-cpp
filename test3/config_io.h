#pragma once

class ConfigIO {
	std::string filename;
	std::string buffer;
public:
	ConfigIO(std::string filename);
	~ConfigIO();

	std::string GetBuffer();
	void ShowBuffer();

	bool AppendLine(std::string data);

	bool DeleteLine(std::string line);
	bool DeleteLine(int line_number);

	//std::string ReadLine();
};