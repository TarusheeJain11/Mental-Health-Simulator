#include "quote_provide.h"

QuoteProvider::QuoteProvider() : rd(), gen(rd()) {
    quotes = {
        "You are capable of amazing things.",
        "Take it one day at a time.",
        "Your mental health is a priority.",
        "It's okay not to be okay.",
        "Progress, not perfection.",
        "You are stronger than you think.",
        "Self-care is not selfish.",
        "This too shall pass.",
        "You matter.",
        "Be gentle with yourself."
    };
}

std::string QuoteProvider::getRandomQuote() const {
    std::uniform_int_distribution<> dis(0, quotes.size() - 1);
    return quotes[dis(gen)];
}