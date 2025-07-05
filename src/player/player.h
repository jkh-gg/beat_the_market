#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>
#include <vector>

#include "security/security.h"

class Player {
   private:
    std::string name;

    double cash;
    std::map<Security, int> portfolio;
    std::vector<std::string> activeLoans;  // TODO - this will be Loan
    int consecutiveDrawdownQuarters;

   public:
    Player(std::string name, double starting_cash);

    std::string getName() const;
    double getCash() const;
    std::map<Security, int> getPortfolio() const;
    std::vector<std::string> getLoans() const;
};

#endif
