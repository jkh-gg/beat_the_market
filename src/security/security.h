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

    std::string getName() const;
    std::string getTicker() const;

    double getPrice() const;
    double getProfit() const;

    Sector getSector() const;
    Region getRegion() const;
    DBucket getDividendBucket() const;

    double getDebt() const;
    double getBias() const;
    double getVol() const;
    double getReputation() const;

    std::vector<double> getPriceHistory() const;
    std::vector<double> getProfitHistory() const;
};

#endif
