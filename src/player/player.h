#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>
#include <vector>

#include "loan/loan.h"
#include "security/security.h"

class Player {
   private:
    std::string name;

    double cash;
    std::map<Security, int> portfolio;
    std::vector<Loan> activeLoans;
    int consecutiveDrawdownQuarters;

   public:
    Player(std::string name, double starting_cash);

    std::string getName() const { return name; }
    double getCash() const { return cash; }
    std::map<Security, int> getPortfolio() const { return portfolio; }
    std::vector<Loan> getLoans() const { return activeLoans; }
};

#endif
