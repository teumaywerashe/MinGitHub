#ifndef COMMIT_H
#define COMMIT_H

#include <string>
#include <vector>

class Commit {
public:
    std::string message;
    std::string timestamp;
    std::string parentHash;
    std::vector<std::string> blobHashes;

    Commit();
    void setMetadata(const std::string& msg, const std::string& parent);
    void saveToFile(const std::string& commitID) const;
};

#endif

