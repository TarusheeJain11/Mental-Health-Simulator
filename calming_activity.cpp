#include "calming_activity.h"
#include "utils.h"
#include <thread>

void CalmingActivity::breathingExercise(std::ostream& output) const {
    output << "\nLet's do a breathing exercise to help you relax...\n";
    output << "Follow the instructions and breathe along:\n\n";
    
    for (int i = 0; i < 3; ++i) {
        showBreathingAnimation(4, "Breathe IN...", output);
        showBreathingAnimation(4, "Hold...", output);
        showBreathingAnimation(6, "Breathe OUT...", output);
        
        if (i < 2) {
            output << "\nGood! Let's do another round...\n\n";
        }
    }
    
    output << "\nExcellent! I hope you're feeling more relaxed now.\n";
}

void CalmingActivity::guidedMeditation(std::ostream& output) const {
    output << "\nLet's do a quick 1-minute guided meditation...\n";
    output << "Close your eyes and follow the instructions:\n\n";
    
    output << "Find a comfortable position...\n";
    Utils::sleep(2000);
    
    output << "Focus on your breath...\n";
    Utils::sleep(2000);
    
    for (int i = 0; i < 5; ++i) {
        output << "Breathe in... and out... (" << i+1 << "/5)\n";
        Utils::sleep(5000);
    }
    
    output << "\nSlowly bring your awareness back to the present...\n";
    output << "Open your eyes when you're ready.\n";
    output << "\nI hope this short meditation helped you center yourself.\n";
}

void CalmingActivity::progressiveRelaxation(std::ostream& output) const {
    output << "\nLet's try progressive muscle relaxation...\n";
    output << "We'll tense and relax different muscle groups:\n\n";
    
    const std::vector<std::string> muscleGroups = {
        "feet", "legs", "abdomen", "arms", "shoulders", "face"
    };
    
    for (const auto& group : muscleGroups) {
        output << "Tense your " << group << " for 5 seconds...\n";
        Utils::sleep(5000);
        output << "Now relax your " << group << " completely...\n";
        Utils::sleep(3000);
    }
    
    output << "\nNotice how your body feels more relaxed now.\n";
}

void CalmingActivity::showBreathingAnimation(int seconds, const std::string& message, 
                                           std::ostream& output) const {
    output << message << " ";
    for (int i = 0; i < seconds; ++i) {
        output << "." << std::flush;
        Utils::sleep(1000);
    }
    output << "\n";
}