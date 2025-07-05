#include "player.h"

Player::Player(std::string name, double starting_cash)
    : name(name), cash(starting_cash), consecutiveDrawdownQuarters(0){};

std::string Player::getName() const { return name; }

double Player::getCash() const { return cash; }

std::map<Security, int> Player::getPortfolio() const { return portfolio; }

std::vector<std::string> Player::getLoans() const { return activeLoans; }
