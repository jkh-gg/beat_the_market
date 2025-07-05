#ifndef MARKET_H
#define MARKET_H

#include <random>
#include <string>
#include <vector>

#include "../event_ecosystem/event_orchestrator/event_orchestrator.h"
#include "../security/security.h"

class Market {
   private:
    std::default_random_engine &rng;

    double currentSofr;
    std::vector<Security> listings;
    std::vector<double> interestRateHistory;

    EventOrchestrator eo;

   public:
    Market(std::default_random_engine &rng, double currentSofr);

    double getSofr() const { return currentSofr; }
    std::vector<Security> getListings() const { return listings; }
    std::vector<double> getRateHistory() const { return interestRateHistory; }
    EventOrchestrator getEventOrchestrator() const { return eo; }
};

#endif
