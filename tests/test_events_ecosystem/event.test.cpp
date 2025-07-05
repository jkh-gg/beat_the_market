
#include "event_ecosystem/event/event.h"

#include <string>
#include <vector>

#include "../../dependencies/doctest/doctest.h"

TEST_CASE("Event constructor") {
    std::string testName = "Economic Downturn";
    std::string testDescription = "A period of reduced economic activity.";
    int testTotalDuration = 8;
    std::string testResearchArea = "Macroeconomics";
    int testResearchDifficulty = 7;
    std::vector<std::string> testInsights = {"Inflation", "Unemployment"};
    int testQBeforeTrigger = 2;
    std::vector<EventEffect> testEffectRules;

    Event event(testName, testDescription, testTotalDuration, testResearchArea,
                testResearchDifficulty, testInsights, testQBeforeTrigger,
                testEffectRules);

    CHECK(event.getName() == testName);
    CHECK(event.getDescription() == testDescription);
    CHECK(event.getTotalDurationQuarters() == testTotalDuration);

    CHECK(event.getQuartersElapsed() == 0);

    CHECK(event.getResearchArea() == testResearchArea);
    CHECK(event.getResearchDifficulty() == testResearchDifficulty);

    CHECK(event.getResearchInsights().size() == testInsights.size());
    if (!testInsights.empty()) {
        CHECK(event.getResearchInsights()[0] == testInsights[0]);
    }

    CHECK(event.getQuartersBeforeTrigger() == testQBeforeTrigger);
    CHECK(event.isActive());

    CHECK(event.getEffectRules().empty());
}
