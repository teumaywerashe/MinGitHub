# MinGitHub
A lightweight local version control system implemented in C++ for managing file versions and commits

## Structure
- `core/`: Handles file hashing and commit logic
- `tests/`: Contains test drivers for BlobManager
- `test_files/`: Sample files for testing

## How to Compile
```bash
g++ core/BlobManager.cpp tests/test_BlobManager.cpp -o test_blob
./test_blob
