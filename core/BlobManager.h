#ifndef BLOBMANAGER_H
#define BLOBMANAGER_H

#include <string>

class BlobManager {
public:
    std::string hashFile(const std::string& filename);
    void saveBlob(const std::string& filename);
};

#endif

