#include <filesystem>
#include "cmds.h"

int main() {
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    
    std::string command;

    while (true) {
        std::cout << "┌ user: " << std::filesystem::current_path() << "\n└---> ";
        std::getline(std::cin, command);
        std::cout << command << "\n";
        if (command == "exit") return 0;

    }
}
