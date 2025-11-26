#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <memory>
#include "user.h"
#include "quote_provide.h"
#include "mood_tracker.h"
#include "calming_activity.h"

class Assistant {
public:
    Assistant(std::shared_ptr<User> user);
    
    void startSession(std::istream& input = std::cin, std::ostream& output = std::cout);
    void showMoodHistory(std::ostream& output = std::cout) const;
    void suggestActivity(std::istream& input = std::cin, std::ostream& output = std::cout) const;
    
private:
    std::shared_ptr<User> user;
    QuoteProvider quoteProvider;
    MoodTracker moodTracker;
    CalmingActivity calmingActivity;
    
    void showWelcomeMessage(std::ostream& output) const;
};

#endif // ASSISTANT_H