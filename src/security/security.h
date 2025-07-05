#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>

class Security {
   private:
    static constexpr int share_count = 1000;

    std::string name;
    std::string ticker;

    double currentPrice;
    double profit;

    std::string sector;          // TODO - This will be an enum
    std::string region;          // TODO - This will be an enum
    std::string dividendBucket;  // TODO - This will be an enum

    double debt;
    double growthBias;  // Secret
    double volatility;  // Secret
    double reputation;  // Secret

    std::vector<double> priceHistory;
    std::vector<double> profitHistory;

   public:
    Security(std::string name, std::string ticker, double initialPrice,
             double initialProfit, std::string sector, std::string region,
             std::string dividendBucket, double initialDebt,
             double baseBias = 0.0, double baseVol = 0.0,
             double baseReputation = 0.0);

    std::string getName() const;
    std::string getTicker() const;

    double getPrice() const;
    double getProfit() const;

    std::string getSector() const;
    std::string getRegion() const;
    std::string getDividendBucket() const;

    double getDebt() const;
    double getBias() const;
    double getVol() const;
    double getReputation() const;

    std::vector<double> getPriceHistory() const;
    std::vector<double> getProfitHistory() const;
};

#endif
