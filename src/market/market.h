#ifndef MARKET_H
#define MARKET_H

#include <random>
#include <string>
#include <vector>

#include "../security/security.h"

class Market {
   private:
    std::default_random_engine &rng;

    std::vector<Security> listings;
    double currentSofr;

    std::string eo;  // TODO- Will be event orchestrator

    std::vector<double> interestRateHistory;

   public:
    Market(std::default_random_engine &rng, double currentSofr);

    std::vector<Security> getListings() const { return listings; }
    double getSofr() const { return currentSofr; }
    std::string getEventOrchestrator() const { return eo; }
    std::vector<double> getRateHistory() const { return interestRateHistory; }
};

#endif
