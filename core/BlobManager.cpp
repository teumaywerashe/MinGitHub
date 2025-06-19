#include "blobManager.h"
#include <fstream>
#include <sstream>
#include <filesystem>
using namespace std;

string BlobManager::hashFile(const string& filename) {
    ifstream file(filename);
    string content, line;

    while (getline(file, line)) {
        content += line;
    }

    unsigned long hash = 0;
    for (char c : content) {
        hash = (hash * 31 + c) % 1000000007;
    }

    return to_string(hash);
}

void BlobManager::saveBlob(const string& filename) {
    string hash = hashFile(filename);

    filesystem::create_directories(".minigit/objects");

    ifstream src(filename, ios::binary);
    ofstream dst(".minigit/objects/" + hash, ios::binary);
    dst << src.rdbuf();
}

