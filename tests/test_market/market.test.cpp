#include "market/market.h"

#include <random>

#include "../../dependencies/doctest/doctest.h"

TEST_CASE("Market initializes with correct SOFR and empty state") {
    std::default_random_engine rng(123);
    double initialSofr = 0.04;

    Market market(rng, initialSofr);

    CHECK(market.getSofr() == initialSofr);

    CHECK(market.getListings().empty());
    CHECK(market.getEventOrchestrator().empty());
    CHECK(market.getRateHistory().empty());
}
