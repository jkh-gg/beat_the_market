#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../dependencies/doctest/doctest.h"

// Include the header for the code you want to test
#include "src/math.h"  // Make sure this path is correct relative to your test file

TEST_CASE("My first test") {
    CHECK(1 + 1 == 2);
    CHECK(2 * 2 == 4);
}

TEST_CASE("Testing the add function from src/math") {
    SUBCASE("Positive numbers") {
        CHECK(add(1, 2) == 3);
        CHECK(add(5, 5) == 10);
    }
    SUBCASE("Negative numbers") {
        CHECK(add(-1, -1) == -2);
        CHECK(add(-5, 2) == -3);
    }
    SUBCASE("Zero") {
        CHECK(add(0, 0) == 0);
        CHECK(add(10, 0) == 10);
    }
}