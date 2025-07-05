#include "security.h"

Security::Security(std::string name, std::string ticker, double initialPrice,
                   double initialProfit, Sector sector, Region region,
                   DBucket dividendBucket, double initialDebt, double baseBias,
                   double baseVol, double baseReputation)
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
