#include "player/player.h"

#include "../../dependencies/doctest/doctest.h"

TEST_CASE("Player Initialization") {
    SUBCASE("Player with positive starting cash") {
        Player p1("Alice", 1000.0);

        CHECK(p1.getName() == "Alice");
        CHECK(p1.getCash() == 1000.0);
        CHECK(p1.getPortfolio().empty());
        CHECK(p1.getLoans().empty());
    }
}
