#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <boost>

void init() {
    std::filesystem::current_path(std::getenv("HOME"));

    std::fstream aliases("aliases.oganesson"); aliases.close();
    std::fstream history("history.oganesson"); history.close();
    std::fstream setup("setup.oganesson"); setup.close();
}

void notBuiltIn(std::string cmd) {
    boost::filesystem path = boost::process::search_path(cmd);

    if (!path.empty()) {
        std::system("$PATH/" + cmd);
    } else {
        std::cout << "ERR: Command not found.\n";
    }
}