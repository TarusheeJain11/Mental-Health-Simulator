#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <random>

using namespace std;

// Utility functions
string getCurrentTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

string toLower(string str) {
    for (char &c : str) c = tolower(c);
    return str;
}

void clearScreen() {
    system("cls || clear");
}

// Simple delay function without threads
void sleepSeconds(int sec) {
    auto start = chrono::steady_clock::now();
    while (chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count() < sec) {
        // Busy wait - not ideal but works without threads
    }
}

// Quote Provider
class QuoteProvider {
private:
    vector<string> quotes = {
        "You're stronger than you think.",
        "Every day is a new beginning.",
        "It's okay not to be okay.",
        "Small steps still move you forward.",
        "You matter."
    };

public:
    string getRandomQuote() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, quotes.size()-1);
        return quotes[dist(gen)];
    }
};

// Calming Activity Provider
class CalmingActivity {
public:
    void breathingExercise() {
        clearScreen();
        cout << "Let's do a breathing exercise to relax...\n\n";
        
        for (int i = 0; i < 3; i++) {
            cout << "Breathe in... (3 seconds)\n";
            sleepSeconds(3);
            
            cout << "Hold... (2 seconds)\n";
            sleepSeconds(2);
            
            cout << "Breathe out... (3 seconds)\n\n";
            sleepSeconds(3);
        }
        
        cout << "Great job! I hope you feel more relaxed now.\n";
    }

    void fiveSensesExercise() {
        clearScreen();
        cout << "Let's do a 5-4-3-2-1 grounding exercise...\n\n";
        cout << "This will help you focus on the present moment.\n\n";
        
        cout << "Name 5 things you can SEE around you:\n";
        sleepSeconds(5);
        
        cout << "\nName 4 things you can TOUCH right now:\n";
        sleepSeconds(4);
        
        cout << "\nName 3 things you can HEAR:\n";
        sleepSeconds(3);
        
        cout << "\nName 2 things you can SMELL:\n";
        sleepSeconds(2);
        
        cout << "\nName 1 thing you can TASTE:\n";
        sleepSeconds(1);
        
        cout << "\nExcellent! You've completed the grounding exercise.\n";
    }

    void showMenu() {
        clearScreen();
        cout << "Calming Activities Menu:\n";
        cout << "1. Breathing Exercise\n";
        cout << "2. 5-4-3-2-1 Grounding Exercise\n";
        cout << "3. Back to Main Menu\n";
        cout << "Choose an activity: ";
        
        string choice;
        getline(cin, choice);
        
        if (choice == "1") {
            breathingExercise();
        }
        else if (choice == "2") {
            fiveSensesExercise();
        }
        else if (choice != "3") {
            cout << "Invalid choice. Returning to main menu.\n";
            sleepSeconds(2);
        }
    }
};

// User class
class User {
private:
    string name;
    vector<pair<string, string>> moodHistory;
    QuoteProvider quoteProvider;

    string getFilename() {
        return name + "_mood.txt";
    }

public:
    User(string n) : name(n) {}

    void addMood(string mood) {
        moodHistory.push_back({mood, getCurrentTime()});
        saveToFile();
        cout << "\n" << quoteProvider.getRandomQuote() << "\n";
    }

    void saveToFile() {
        ofstream file(getFilename());
        for (auto &entry : moodHistory) {
            file << entry.first << "|" << entry.second << "\n";
        }
    }

    void loadFromFile() {
        ifstream file(getFilename());
        string line;
        while (getline(file, line)) {
            size_t split = line.find('|');
            if (split != string::npos) {
                moodHistory.push_back({line.substr(0, split), line.substr(split+1)});
            }
        }
    }

    void showHistory() {
        cout << "\nYour Mood History:\n";
        if (moodHistory.empty()) {
            cout << "No history yet.\n";
            return;
        }
        for (auto &entry : moodHistory) {
            cout << entry.second << " - " << entry.first << endl;
        }
    }
};

// Main program
int main() {
    clearScreen();
    cout << "Mental Health Check-in\n";
    cout << "Enter your name: ";
    
    string name;
    getline(cin, name);
    User user(name);
    user.loadFromFile();
    CalmingActivity calmingActivity;

    while (true) {
        clearScreen();
        cout << "Main Menu:\n";
        cout << "1. Record mood\n";
        cout << "2. View history\n";
        cout << "3. Calming Activities\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        
        string choice;
        getline(cin, choice);
        
        if (choice == "1") {
            clearScreen();
            cout << "How are you feeling today?\n";
            cout << "1. Happy\n2. Sad\n3. Anxious\n4. Calm\n5. Angry\n6. Other\n";
            cout << "Enter your mood (1-6 or description): ";
            
            string mood;
            getline(cin, mood);
            
            if (mood == "1") mood = "Happy";
            else if (mood == "2") mood = "Sad";
            else if (mood == "3") mood = "Anxious";
            else if (mood == "4") mood = "Calm";
            else if (mood == "5") mood = "Angry";
            
            user.addMood(mood);

            cout << "\nWould you like to try a calming activity? (yes/no): ";
            string answer;
            getline(cin, answer);
            if (toLower(answer) == "yes" || toLower(answer) == "y") {
                calmingActivity.showMenu();
            }
        }
        else if (choice == "2") {
            clearScreen();
            user.showHistory();
        }
        else if (choice == "3") {
            calmingActivity.showMenu();
        }
        else if (choice == "4") {
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            sleepSeconds(2);
        }
        
        cout << "\nPress Enter to continue...";
        getline(cin, choice);
    }

    cout << "\nThank you for using Mental Health Check-in. Take care!\n";
    return 0;
}