#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>

#include "common/dividend_bucket.h"
#include "common/region.h"
#include "common/sector.h"

class Security {
   private:
    static constexpr int share_count = 1000;

    std::string name;
    std::string ticker;

    double currentPrice;
    double profit;

    Sector sector;
    Region region;
    DBucket dividendBucket;

    double debt;
    double growthBias;  // Secret
    double volatility;  // Secret
    double reputation;  // Secret

    std::vector<double> priceHistory;
    std::vector<double> profitHistory;

   public:
    Security(std::string name, std::string ticker, double initialPrice,
             double initialProfit, Sector sector, Region region,
             DBucket dividendBucket, double initialDebt, double baseBias = 0.0,
             double baseVol = 0.0, double baseReputation = 0.0);

    std::string getName() const { return name; }
    std::string getTicker() const { return ticker; }

    double getPrice() const { return currentPrice; }
    double getProfit() const { return profit; }

    Sector getSector() const { return sector; }
    Region getRegion() const { return region; }
    DBucket getDividendBucket() const { return dividendBucket; }

    double getDebt() const { return reputation; }
    double getBias() const { return debt; }
    double getVol() const { return growthBias; }
    double getReputation() const { return volatility; }

    std::vector<double> getPriceHistory() const { return priceHistory; }
    std::vector<double> getProfitHistory() const { return profitHistory; }
};

#endif
