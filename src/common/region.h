#ifndef REGION_H
#define REGION_H

#include <string>

enum class Region {
    AMERICA,
    EMEA,
    ASIA,
    // ...
    ALL,
    NONE,
    // Below are iteration bounds for random selection
    FIRST = AMERICA,
    LAST = ASIA,
};

inline std::string regionToString(Region region) {
    switch (region) {
        case Region::AMERICA:
            return "Americas";
        case Region::EMEA:
            return "EMEA";
        case Region::ASIA:
            return "ASIA";
        case Region::ALL:
            return "All";

        default:
            return "None";
    }
}

#endif
