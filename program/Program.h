#ifndef CONSOLE_FILE_EXPLORER_PROGRAM_H
#define CONSOLE_FILE_EXPLORER_PROGRAM_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

class Program {
private:
    std::string in;
    struct ReadableSize;
public:
    void setup();
};


#endif //CONSOLE_FILE_EXPLORER_PROGRAM_H
