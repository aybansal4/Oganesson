#include "cmds.h"

int main() {
    init();
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    
    std::string command;
    std::string PROMPT;
    while (true) {
        std::cout << std::getline();
    }
}