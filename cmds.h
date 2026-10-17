#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <cstdlib>
#include <vector>
#include "subprocess.hpp"

namespace command {
    void init() {
        std::filesystem::current_path(std::getenv("HOME"));

        std::fstream aliases("aliases.oganesson"); aliases.close();
        std::fstream history("history.oganesson"); history.close();
        std::fstream setup("setup.oganesson");
        std::system("chmod +x ~/setup.oganesson; ~/setup.oganesson");
    }

    void notBuiltIn(const std::vector<std::string> &cmd) {
        try {
            auto runner = subprocess::Popen(cmd);

            int exit = runner.wait();
        } catch (const subprocess::CalledProcessError& e) {
            std::cout << "ERR: Couldn't run command (see below)" << "\n" << e.what() << "\n";
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

    void chdir(const char* path) {
        ::chdir(path);
    }
}
