#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <cstdlib>

namespace command {
    void init() {
        std::filesystem::current_path(std::getenv("HOME"));

        std::fstream aliases("aliases.oganesson"); aliases.close();
        std::fstream history("history.oganesson"); history.close();
        std::fstream setup("setup.oganesson"); setup.close();
    }

    void notBuiltIn(std::string cmd) {
        int exists = std::system(("type" + cmd).c_str());

        if (!exists) {
            int result = std::system(cmd.c_str());
            if (result != 0) {
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
        std::string username;
        uid_t uid = getuid();

        struct passwd* pw = getpwuid(uid);

        if (pw) {
            username = pw->pw_name;
        } else {
            std::cout << "ERR: Couldn't find a username for you";
            return;
        }
        
        std::string cmnd;
        
        std::fstream history(std::string(std::getenv("HOME")) +"/history.oganesson");
        history.seekg(-1, ios_base::end);
        
        bool loop = true;

        while (loop) {
            char ch();
            history.get(ch);

            if ((int)history.tellg() <= 1) { history.seekg(0); keeplooping =  false; }

            else if ( ch = '\n' ) keeplooping = false;

            else history.seekg(2-, ios_base::cur);
        }

        std::getline(history, cmnd);
    }

    void clear() {
        std::cout << "\033[2J\033[H";
    }

    void chdir(std::string path) {
        chdir(path);
    }
}
