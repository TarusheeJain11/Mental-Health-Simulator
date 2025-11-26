#include "mood_tracker.h"
#include "utils.h"

std::string MoodTracker::askMood(std::istream& input, std::ostream& output) const {
    output << "\nHow are you feeling today?\n";
    output << "Please choose from the following options:\n";
    
    for (size_t i = 0; i < moodOptions.size(); ++i) {
        output << i + 1 << ". " << moodOptions[i] << "\n";
    }
    
    output << "Enter your mood (1-" << moodOptions.size() << " or type your own): ";
    
    std::string response;
    std::getline(input, response);
    response = Utils::trim(response);
    
    // Check if it's a number selection
    try {
        int choice = std::stoi(response);
        if (choice >= 1 && choice <= static_cast<int>(moodOptions.size())) {
            return moodOptions[choice - 1];
        }
    } catch (...) {
        // Not a number, return the text as mood
    }
    
    return response.empty() ? "Unspecified" : response;
}