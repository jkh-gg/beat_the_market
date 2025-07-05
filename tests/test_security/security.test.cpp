#include "security/security.h"

#include <string>
#include <vector>

#include "../../dependencies/doctest/doctest.h"

TEST_CASE("Security Constructor and Basic Getters") {
    std::string name = "Tech Innovators Inc.";
    std::string ticker = "TII";
    double initialPrice = 100.50;
    double initialProfit = 10.25;
    double initialDebt = 5.00;
    std::string sector = "Technology";
    std::string region = "North America";
    std::string dividendBucket = "Growth";
    double baseBias = 0.1;
    double baseVol = 0.05;
    double baseReputation = 0.9;

    Security security1(name, ticker, initialPrice, initialProfit, sector,
                       region, dividendBucket, initialDebt, baseBias, baseVol,
                       baseReputation);

    CHECK(security1.getName() == name);
    CHECK(security1.getTicker() == ticker);
    CHECK(security1.getPrice() == initialPrice);
    CHECK(security1.getProfit() == initialProfit);
    CHECK(security1.getDebt() == initialDebt);
    CHECK(security1.getSector() == sector);
    CHECK(security1.getRegion() == region);
    CHECK(security1.getDividendBucket() == dividendBucket);
    CHECK(security1.getBias() == baseBias);
    CHECK(security1.getVol() == baseVol);
    CHECK(security1.getReputation() == baseReputation);
}

TEST_CASE("Security Constructor with Default Parameters") {
    std::string name = "Default Co.";
    std::string ticker = "DEF";
    double initialPrice = 50.0;
    double initialProfit = 5.0;
    double initialDebt = 2.0;
    std::string sector = "Finance";
    std::string region = "Europe";
    std::string dividendBucket = "Value";

    Security security2(name, ticker, initialPrice, initialProfit, sector,
                       region, dividendBucket, initialDebt);

    CHECK(security2.getBias() == 0.0);
    CHECK(security2.getVol() == 0.0);
    CHECK(security2.getReputation() == 0.0);
}
