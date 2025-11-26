#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace Utils {
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    std::string getCurrentDateTime();
    std::string toLower(const std::string& str);
    std::string trim(const std::string& str);
    bool createDirectoryIfNotExists(const fs::path& path);
    bool fileExists(const fs::path& path);
    void clearScreen();
    void sleep(unsigned int milliseconds);
}

#endif // UTILS_H