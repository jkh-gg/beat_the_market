#ifndef SECTOR_H
#define SECTOR_H

#include <string>

enum class Sector {
    TECHNOLOGY,
    FINANCE,
    ENERGY,
    GOODS,
    HEALTH,
    INDUSTRIAL,
    PROPERTY,
    // ...
    ALL,
    NONE,
    // Below are iteration bounds for random selection
    FIRST = TECHNOLOGY,
    LAST = PROPERTY,
};

inline std::string sectorToString(Sector sector) {
    switch (sector) {
        case Sector::TECHNOLOGY:
            return "Technology";
        case Sector::FINANCE:
            return "Finance";
        case Sector::ENERGY:
            return "Energy";
        case Sector::GOODS:
            return "Goods";
        case Sector::HEALTH:
            return "Health";
        case Sector::INDUSTRIAL:
            return "Industrial";
        case Sector::PROPERTY:
            return "Property";
        case Sector::ALL:
            return "All";

        default:
            return "None";
    }
}

#endif
