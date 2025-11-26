#include "user.h"
#include <fstream>
#include <iostream>

User::User(const std::string& name) : name(Utils::trim(name)) {}

std::string User::getName() const {
    return name;
}

void User::addMood(const std::string& mood, const std::string& timestamp) {
    std::string ts = timestamp.empty() ? Utils::getCurrentDateTime() : timestamp;
    moodHistory.emplace_back(mood, ts);
}

std::vector<std::pair<std::string, std::string>> User::getMoodHistory() const {
    return moodHistory;
}

std::string User::getFilename() const {
    return "data/users/" + name + ".dat";
}

bool User::saveToFile() const {
    try {
        if (!Utils::createDirectoryIfNotExists("data/users")) {
            return false;
        }
        
        std::ofstream outFile(getFilename());
        if (!outFile) {
            return false;
        }
        
        for (const auto& entry : moodHistory) {
            outFile << entry.first << "|" << entry.second << "\n";
        }
        
        return true;
    } catch (...) {
        return false;
    }
}

bool User::loadFromFile() {
    moodHistory.clear();
    
    try {
        std::ifstream inFile(getFilename());
        if (!inFile) {
            return false;
        }
        
        std::string line;
        while (std::getline(inFile, line)) {
            auto parts = Utils::splitString(line, '|');
            if (parts.size() == 2) {
                moodHistory.emplace_back(parts[0], parts[1]);
            }
        }
        
        return true;
    } catch (...) {
        return false;
    }
}

std::shared_ptr<User> User::createOrLoadUser(const std::string& name) {
    auto user = std::make_shared<User>(name);
    user->loadFromFile();
    return user;
}