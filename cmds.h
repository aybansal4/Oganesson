#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <boost/process.hpp>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>


void init() {
    std::filesystem::current_path(std::getenv("HOME"));

    std::fstream aliases("aliases.oganesson"); aliases.close();
    std::fstream history("history.oganesson"); history.close();
    std::fstream setup("setup.oganesson"); setup.close();
}

void notBuiltIn(std::string cmd) {
    boost::filesystem path = boost::process::search_path(cmd);

    if (!path.empty()) {
        int result = std::system("$PATH/" + cmd);
        if (result != 0) {
            std::cout << "ERR: Failed to run command.\n";
        }
    } else {
        std::cout << "ERR: Command not found.\n";
    }
}

void addToHist(std::string cmd) {
    std::fstream history(std::getenv("HOME").concat("/history.oganesson"), std::ios::app);

    if (!history.is_open()) {
        std::cout << "ERR: Couldn't open history file.\n";
        return;
    }

    history << "\n" << cmd;
}

void previous() {
    char buffer;
    std::string username;
    uid_t uid = getuid();

    struct passwd* pw = getpwuid(uid);

    if (pw) {
        username = pw->pw_name;
    } else {
        std::cout << "ERR: Couldn't find a username for you";
        return;
    }

    std::fstream history(std::getenv("HOME").concat("/history.oganesson"), std::ios::ate);
}

void clear() {
    std::cout << "\033[2J\033[H";
}