#include "market.h"

Market::Market(std::default_random_engine &rng, double currentSofr)
    : rng(rng), currentSofr(currentSofr), eo(""){};
