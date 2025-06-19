
#include <iostream>
#include "InitCommand.h"  // Include your init function

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: minigit <command>\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "init") {
        initRepository();
    } else {
        std::cout << "Unknown command: " << command << "\n";
    }

    return 0;
}

