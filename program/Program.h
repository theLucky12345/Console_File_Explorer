#ifndef CONSOLE_FILE_EXPLORER_PROGRAM_H
#define CONSOLE_FILE_EXPLORER_PROGRAM_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <windows.h>

class Program {
private:
	void SetColor(int text, int bg);
	std::string in;
	struct ReadableSize;

	uintmax_t DirectorySize(const std::filesystem::path &directory);

public:
	void setup();
};


#endif //CONSOLE_FILE_EXPLORER_PROGRAM_H
