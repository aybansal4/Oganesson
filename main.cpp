#include <filesystem>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "json.hpp"
#include "cmds.h"

int main() {

    command::init();
    nlohmann::json aliases;
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    std::fstream aliases_("aliases.oganesson");

    if (aliases_.is_open()) {
        aliases_ >> aliases;
    }
    
    
    std::string cmd;

    while (true) {
        std::cout << "┌ user: " << std::filesystem::current_path() << "\n└---> ";
        std::getline(std::cin, cmd);
        if (cmd.empty()) continue;

        if (aliases.contains(cmd)) {
            cmd = aliases[cmd];
        }

        std::vector<std::string> cmd_split;
        boost::split(cmd_split, cmd, boost::is_any_of(" "));

        if (cmd_split[0] == "exit") return 0;
        else if (cmd_split[0] == "previous") {
            std::system(command::previous().c_str());
        } else if (cmd_split[0] == "clear") {
            command::clear();
        } else if (cmd_split[0] == "previous") {
            command::previous();
        } else if (cmd_split[0] == "chdir") {
            command::chdir(cmd_split[1].c_str());
        } else if (cmd_split[0] == "load") {
            aliases_ >> aliases;
        } else {
            command::notBuiltIn(cmd_split);
        }
        
        command::addToHist(cmd);

    }
}
