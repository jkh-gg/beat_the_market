#include "market.h"

Market::Market(std::default_random_engine &rng, double currentSofr)
    : rng(rng), currentSofr(currentSofr), eo(""){};

std::vector<Security> Market::getListings() const { return listings; }

double Market::getSofr() const { return currentSofr; }

std::string Market::getEventOrchestrator() const { return eo; }

std::vector<double> Market::getRateHistory() const {
    return interestRateHistory;
}
