#include "program/Program.h"
#include <clocale>

int main(int ac, char **av) {
    setlocale(LC_ALL, "");
	SetConsoleTitleA("Console File Explorer");
	SetWindowLongA(GetConsoleWindow(), -16, GetWindowLongA(GetConsoleWindow(), -16) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    Program program;
    std::cout << "type 'help' for help" << std::endl;
    std::filesystem::current_path("C:\\");
    while (true)
        program.setup();
}