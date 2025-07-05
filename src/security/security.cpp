#include "security.h"

Security::Security(std::string name, std::string ticker, double initialPrice,
                   double initialProfit, std::string sector, std::string region,
                   std::string dividendBucket, double initialDebt,
                   double baseBias, double baseVol, double baseReputation)
    : name(name),
      ticker(ticker),
      currentPrice(initialPrice),
      profit(initialProfit),
      sector(sector),
      region(region),
      dividendBucket(dividendBucket),
      debt(initialDebt),
      growthBias(baseBias),
      volatility(baseVol),
      reputation(baseReputation){};

std::string Security::getName() const { return name; }
std::string Security::getTicker() const { return ticker; }

double Security::getPrice() const { return currentPrice; }
double Security::getProfit() const { return profit; }

double Security::getDebt() const { return debt; }
double Security::getBias() const { return growthBias; }
double Security::getVol() const { return volatility; }
double Security::getReputation() const { return reputation; }

std::string Security::getSector() const { return sector; }
std::string Security::getRegion() const { return region; }
std::string Security::getDividendBucket() const { return dividendBucket; }

std::vector<double> Security::getPriceHistory() const { return priceHistory; }
std::vector<double> Security::getProfitHistory() const { return profitHistory; }
