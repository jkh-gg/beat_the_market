#include "player.h"

Player::Player(std::string name, double starting_cash)
    : name(name), cash(starting_cash), consecutiveDrawdownQuarters(0){};
