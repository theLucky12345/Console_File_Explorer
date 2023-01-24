#include "program/Program.h"
#include <clocale>

int main(int ac, char **av) {
    setlocale(LC_ALL, "");
    Program program;
    std::filesystem::current_path("C:\\");
    while (true)
        program.setup();
}