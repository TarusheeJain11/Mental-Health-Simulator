#ifndef QUOTE_PROVIDER_H
#define QUOTE_PROVIDER_H

#include <string>
#include <vector>
#include <random>

class QuoteProvider {
public:
    QuoteProvider();
    std::string getRandomQuote() const;
    
private:
    std::vector<std::string> quotes;
    mutable std::random_device rd;
    mutable std::mt19937 gen;
};

#endif // QUOTE_PROVIDER_H