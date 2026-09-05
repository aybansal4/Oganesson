#include <filesystem>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "cmds.h"

int main() {
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    
    std::string command;

    while (true) {
        std::cout << "┌ user: " << std::filesystem::current_path() << "\n└---> ";
        std::getline(std::cin, command);
        
        std::vector<std::string> cmd_split;
        boost::split(cmd_split, command, boost::is_any_of(" "));
        for (std::string w : cmd_split) std::cout << w << "\n";
        if (command == "exit") return 0;


    }
}
