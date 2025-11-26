#include <iostream>
#include <memory>
#include <limits>
#include "assistant.h"
#include "user.h"
#include "utils.h"

void showMainMenu() {
    Utils::clearScreen();
    std::cout << "MENTAL HEALTH CHECK-IN SIMULATOR\n";
    std::cout << "================================\n";
    std::cout << "1. Start a new session\n";
    std::cout << "2. View mood history\n";
    std::cout << "3. Exit\n";
    std::cout << "================================\n";
    std::cout << "Enter your choice (1-3): ";
}

int main() {
    try {
        // Initialize user
        std::cout << "Welcome to Mental Health Check-in Simulator\n";
        std::cout << "Please enter your name: ";
        
        std::string name;
        std::getline(std::cin, name);
        
        auto user = User::createOrLoadUser(name);
        Assistant assistant(user);
        
        while (true) {
            showMainMenu();
            
            std::string choice;
            std::getline(std::cin, choice);
            choice = Utils::trim(choice);
            
            if (choice == "1") {
                assistant.startSession();
            } else if (choice == "2") {
                assistant.showMoodHistory();
            } else if (choice == "3") {
                std::cout << "\nThank you for using the Mental Health Check-in Simulator.\n";
                std::cout << "Remember to take care of your mental health every day!\n";
                break;
            } else {
                std::cout << "\nInvalid choice. Please try again.\n";
            }
            
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
}