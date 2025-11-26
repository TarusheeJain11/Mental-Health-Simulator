#include "assistant.h"
#include "utils.h"

Assistant::Assistant(std::shared_ptr<User> user) : user(user) {}

void Assistant::startSession(std::istream& input, std::ostream& output) {
    showWelcomeMessage(output);
    
    std::string mood = moodTracker.askMood(input, output);
    user->addMood(mood);
    user->saveToFile();
    
    output << "\nThank you for sharing. Here's a quote for you:\n";
    output << ">> " << quoteProvider.getRandomQuote() << " <<\n\n";
    
    suggestActivity(input, output);
    
    output << "\nThank you for using the Mental Health Check-in.\n";
}

void Assistant::showMoodHistory(std::ostream& output) const {
    auto history = user->getMoodHistory();
    
    if (history.empty()) {
        output << "\nNo mood history recorded yet.\n";
        return;
    }
    
    output << "\nYour Mood History:\n";
    output << "-----------------\n";
    
    for (const auto& entry : history) {
        output << entry.second << " - " << entry.first << "\n";
    }
    
    output << "\n";
}

void Assistant::suggestActivity(std::istream& input, std::ostream& output) const {
    output << "\nWould you like to try a relaxation activity? (yes/no): ";
    std::string answer;
    std::getline(input, answer);
    answer = Utils::toLower(Utils::trim(answer));
    
    if (answer == "yes" || answer == "y") {
        output << "\nChoose an activity:\n";
        output << "1. Breathing Exercise\n";
        output << "2. Guided Meditation\n";
        output << "3. Progressive Muscle Relaxation\n";
        output << "Enter your choice (1-3): ";
        
        std::string choice;
        std::getline(input, choice);
        choice = Utils::trim(choice);
        
        output << "\n";
        if (choice == "1") {
            calmingActivity.breathingExercise(output);
        } else if (choice == "2") {
            calmingActivity.guidedMeditation(output);
        } else if (choice == "3") {
            calmingActivity.progressiveRelaxation(output);
        } else {
            output << "Invalid choice. Starting breathing exercise by default.\n";
            calmingActivity.breathingExercise(output);
        }
    }
}

void Assistant::showWelcomeMessage(std::ostream& output) const {
    output << "\nWelcome back, " << user->getName() << "!\n";
    output << "This is your mental health check-in session.\n";
}