#include <iostream>
#include "pstream.h"
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <cstdlib>
#include <vector>

namespace command {
    void init() {
        std::filesystem::current_path(std::getenv("HOME"));

        std::fstream aliases("aliases.oganesson"); aliases.close();
        std::fstream history("history.oganesson"); history.close();
        std::fstream setup("setup.oganesson"); setup.close();
    }

    void notBuiltIn(std::vector<std::string> cmd) {

        int exists = std::system(("which " + cmd[0] + "> /dev/null").c_str());

        if (!exists) {
            
            std::vector<std::string> args(cmd.begin() + 1, cmd.end());

            redi::ipstream run(cmd[0], args); run.close();
            
            if (run.rdbuf()->status() != 0) {
                std::cout << "ERR: Failed to run command.\n";
            }
        } else {
            std::cout << "ERR: Command not found.\n";
        }
    }

    void addToHist(std::string cmd) {
        std::string home = std::string(std::getenv("HOME")) + "/history.oganesson";
        std::fstream history(home, std::ios::app);

        if (!history.is_open()) {
            std::cout << "ERR: Couldn't open history file.\n";
            return;
        }

        history << "\n" << cmd;
    }

    std::string previous() {        
        std::string cmnd;
        
        int r = std::system("tail -n 1 ~/history.oganesson > /tmp/command.txt");
        std::ifstream f("/tmp/command.txt");

        std::getline(f, cmnd);

        return cmnd;
    }

    void clear() {
        std::cout << "\033[2J\033[H";
    }

    void chdir(std::string path) {
        chdir(path);
    }
}
