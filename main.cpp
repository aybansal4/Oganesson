#include "cmds.h"

int main() {
    init();
    std::fstream setup("setup.oganesson");
    std::filesystem::path p = std::filesystem::current_path();

    
    std::string command;

    while (true) {
        std::cout << "user: " << std::filesystem::current_path() << "\n--->";
        std::cin >> command;

    }
}
