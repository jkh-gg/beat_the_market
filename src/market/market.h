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

    std::vector<Security> getListings() const;
    double getSofr() const;
    std::string getEventOrchestrator() const;
    std::vector<double> getRateHistory() const;
};

#endif
