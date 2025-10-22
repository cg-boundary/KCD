#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;


int main() {
    // 1. Get current working directory
    fs::path currentDir = fs::current_path();
    std::cout << "Current directory: " << currentDir << "\n\n";

    // 2. Check if a file exists
    fs::path testFile = currentDir / "example.txt";
    if (fs::exists(testFile)) {
        std::cout << "File exists: " << testFile << "\n";
    } else {
        std::cout << "File does not exist: " << testFile << "\n";
    }

    // 3. List all files in the current directory
    std::cout << "\nListing directory contents:\n";
    for (const auto& entry : fs::directory_iterator(currentDir)) {
        std::cout << (entry.is_directory() ? "[DIR]  " : "[FILE] ") << entry.path().filename().string() << "\n";
    }

    // 4. Read a file’s contents
    if (fs::exists(testFile)) {
        std::ifstream file(testFile);
        std::string line;
        std::cout << "\nContents of " << testFile.filename() << ":\n";
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    }

    // 5. Create a new folder if it doesn’t exist
    fs::path newFolder = currentDir / "test_folder";
    if (!fs::exists(newFolder)) {
        fs::create_directory(newFolder);
        std::cout << "\nCreated folder: " << newFolder << "\n";
    }

    // 6. Recursively search for files
    std::cout << "\nSearching for .txt files:\n";
    for (const auto& entry : fs::recursive_directory_iterator(currentDir)) {
        if (entry.path().extension() == ".txt") {
            std::cout << "Found: " << entry.path() << "\n";
        }
    }

    return 0;
}
