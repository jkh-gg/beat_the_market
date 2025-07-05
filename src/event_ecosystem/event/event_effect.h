#ifndef EVENTEFFECT_H
#define EVENTEFFECT_H

#include <string>
#include <vector>

#include "common/region.h"
#include "common/sector.h"

struct EventEffect {
    std::vector<Sector> targetSectors;
    std::vector<Region> targetRegions;
    std::vector<std::string> targetTickers;

    double priceBiasInitial;
    double priceBiasDecayRate;

    double profitBiasStart;
    double profitBiasEnd;

    double volatilityChangeInitial;
    double volatilityChangeEnd;
};

#endif
