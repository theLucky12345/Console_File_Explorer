#include "Program.h"

// private methods
struct Program::ReadableSize {
    std::uintmax_t size{};
private:
    friend std::ostream &
    operator<<(std::ostream &os, ReadableSize readableSize) {
        int i{};
        double mantissa = readableSize.size;
        for (; mantissa >= 1024.; mantissa /= 1024., ++i) {}
        printf("%4.2f %c", mantissa, "BKMGTPE"[i]);
        return i == 0 ? os : os << "B (" << readableSize.size << ')';
    }
};

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
    } else if (in.starts_with("size")) {
        try {
            if (std::filesystem::directory_entry().is_directory()) {
                //TODO
            } else {
                std::cout << in.substr(in.find(" ") + 1) << " -> "
                          << ReadableSize{std::filesystem::file_size(in.substr(in.find(" ") + 1))} << std::endl;
            }
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    } else if (in.starts_with("clear") || in.starts_with("cls") && in.length() == 5 || in.length() == 2) {
        system("cls");
    } else if (in.starts_with("exit")) {
        exit(0);
    } else if (in.starts_with("help") && in.length() == 4) {
        std::cout << "type 'help' for help" << std::endl
             << "type 'clear' to clear screen" << std::endl
             << "type 'exit' for exiting from program" << std::endl
             << "type 'ls' to view files/folder in current directory"
             << "type 'cd ../ cd' to go back" << std::endl
             << "type 'cd {folder_name}' to open folder" << std::endl
             << "type 'mkdir {folder_name}' to create folder" << std::endl
             << "type 'touch {file_name}' to create file" << std::endl
             << "type 'rm {file_name/folder_name}' to remove file/folder" << std::endl
             << "type 'copy {file_name/folder_name}' to copy file/folder" << std::endl
             << "type 'move {file_name/folder_name}' to move file/folder" << std::endl
             << "type 'size {file_name/folder_name}' to view size of file/folder" << std::endl;
    } else {
        std::cout << "Invalid input.." << std::endl << "\tTry typing 'help' for helping yourself";
    }
}