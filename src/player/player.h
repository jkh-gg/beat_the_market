#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>
#include <vector>

class Player {
   private:
    std::string name;

    double cash;
    std::map<std::string, int> portfolio;  // this will be Stock* => int
    std::vector<std::string> activeLoans;  // this will be Loan
    int consecutiveDrawdownQuarters;

   public:
    Player(std::string name, double starting_cash);

    std::string getName() const;
    double getCash() const;
    std::map<std::string, int> getPortfolio() const;
    std::vector<std::string> getLoans() const;
};

#endif
