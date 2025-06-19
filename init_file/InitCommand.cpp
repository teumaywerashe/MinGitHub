
#include "InitCommand.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void initRepository() {
    const std::string repoDir = ".minigit";
    const std::string objectsDir = repoDir + "/objects";
    const std::string commitsDir = repoDir + "/commits";
    const std::string branchesDir = repoDir + "/branches";
    const std::string headFile = repoDir + "/HEAD";

    if (fs::exists(repoDir)) {
        std::cout << "MiniGit repository already initialized in this directory.\n";
        return;
    }

    fs::create_directory(repoDir);
    fs::create_directory(objectsDir);
    fs::create_directory(commitsDir);
    fs::create_directory(branchesDir);

    std::ofstream head(headFile);
    head << "ref: master\n";
    head.close();

    std::cout << "Initialized empty MiniGit repository in " << fs::absolute(repoDir) << "\n";
}

