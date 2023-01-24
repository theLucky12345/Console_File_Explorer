#include "Program.h"

// public methods
void Program::setup() {
    std::cout << "<" << std::filesystem::current_path().string() << ">";
    std::getline(std::cin, in);
    if (in.starts_with("ls") && in.length() == 2) {
        for (auto const &dir_entry: std::filesystem::directory_iterator{std::filesystem::current_path()}) {
            std::cout << dir_entry.path().filename().string() << "\t";
        }
        std::cout << std::endl;
    } else if (in.starts_with("mkdir") && in.length() >= 6) {
        try {
            std::filesystem::create_directory(in.substr(in.find(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("touch") && in.length() >= 6) {
        try {
            std::ofstream out(in.substr(in.find(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("rm") && in.length() >= 3) {
        try {
            std::filesystem::remove(in.substr(in.find(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("cd") && in.length() >= 3) {
        try {
            std::filesystem::current_path(in.substr(in.find(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("cd") && in.length() >= 2) {
        try {
            std::filesystem::current_path(std::filesystem::current_path().parent_path());
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("rename") && in.length() >= 7) {
        try {
            std::filesystem::rename(in.substr(in.find(" ") + 1, in.rfind(" ") - 7), in.substr(in.rfind(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("copy") && in.length() >= 5) {
        try {
            std::filesystem::copy_file(in.substr(in.find(" ") + 1, in.rfind(" ") - 5), in.substr(in.rfind(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("move") && in.length() >= 5) {
        try {
            std::filesystem::rename(in.substr(in.find(" ") + 1, in.rfind(" ") - 5), in.substr(in.rfind(" ") + 1));
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    }
}