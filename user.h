#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "utils.h"

class User {
public:
    User(const std::string& name);
    
    std::string getName() const;
    void addMood(const std::string& mood, const std::string& timestamp = "");
    std::vector<std::pair<std::string, std::string>> getMoodHistory() const;
    bool saveToFile() const;
    bool loadFromFile();
    
    static std::shared_ptr<User> createOrLoadUser(const std::string& name);

private:
    std::string name;
    std::vector<std::pair<std::string, std::string>> moodHistory; // mood, timestamp
    
    std::string getFilename() const;
};

#endif // USER_H