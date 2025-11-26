#ifndef CALMING_ACTIVITY_H
#define CALMING_ACTIVITY_H

#include <iostream>

class CalmingActivity {
public:
    void breathingExercise(std::ostream& output = std::cout) const;
    void guidedMeditation(std::ostream& output = std::cout) const;
    void progressiveRelaxation(std::ostream& output = std::cout) const;
    
private:
    void showBreathingAnimation(int seconds, const std::string& message, 
                              std::ostream& output) const;
};

#endif // CALMING_ACTIVITY_H