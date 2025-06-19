#include "../core/BlobManager.h"
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    BlobManager bm;
    bm.saveBlob("example.txt");
    cout << "Blob saved.\n";
    return 0;
}

