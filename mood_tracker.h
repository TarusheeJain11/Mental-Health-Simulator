#ifndef MOOD_TRACKER_H
#define MOOD_TRACKER_H

#include <string>
#include <vector>
#include <iostream>

class MoodTracker {
public:
    std::string askMood(std::istream& input = std::cin, std::ostream& output = std::cout) const;
    
private:
    const std::vector<std::string> moodOptions = {
        "Happy", "Sad", "Anxious", "Stressed", "Angry",
        "Excited", "Tired", "Peaceful", "Confused", "Neutral"
    };
};

#endif // MOOD_TRACKER_H