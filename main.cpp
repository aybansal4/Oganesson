#include <filesystem>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "cmds.h"

int main() {
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    
    std::string cmd;

    while (true) {
        std::cout << "┌ user: " << std::filesystem::current_path() << "\n└---> ";
        std::getline(std::cin, cmd);
        
        std::vector<std::string> cmd_split;
        boost::split(cmd_split, cmd, boost::is_any_of(" "));

        if (cmd_split[0] == "exit") return 0;
        else if (cmd_split[0] == "previous") {
            std::system(command::previous().c_str());
        } else if (cmd_split[0] == "clear") {
            command::clear();
        } else {
            command::notBuiltIn(cmd_split);
        }
        
        command::addToHist(cmd);

    }
}
