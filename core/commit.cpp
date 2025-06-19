#include "Commit.h"
#include <fstream>
#include <ctime>
#include <filesystem>

Commit::Commit() {}

void Commit::setMetadata(const std::string& msg, const std::string& parent) {
    message = msg;
    parentHash = parent;

    std::time_t now = std::time(nullptr);
    timestamp = std::ctime(&now);
    if (!timestamp.empty()) {
        timestamp.pop_back(); // remove newline
    }
}

void Commit::saveToFile(const std::string& commitID) const {
    std::filesystem::create_directories(".minigit/commits");

    std::ofstream file(".minigit/commits/" + commitID + ".txt");
    file << "Commit: " << commitID << "\n";
    file << "Timestamp: " << timestamp << "\n";
    file << "Message: " << message << "\n";
    file << "Parent: " << parentHash << "\n";
    file << "Blobs:\n";
    for (const std::string& blob : blobHashes) {
        file << "- " << blob << "\n";
    }
}

