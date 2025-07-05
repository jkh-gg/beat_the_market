
#include "event_ecosystem/event/event.h"

#include <string>
#include <vector>

#include "../../dependencies/doctest/doctest.h"
#include "utils/event_mocks.h"

TEST_CASE("Event constructor") {
    std::string testName = "Economic Downturn";
    std::string testDescription = "A period of reduced economic activity.";
    int testTotalDuration = 8;
    std::string testResearchArea = "Macroeconomics";
    int testResearchDifficulty = 7;
    std::vector<std::string> testInsights = {"Inflation", "Unemployment"};
    int testQBeforeTrigger = 2;
    std::vector<EventEffect> testEffectRules;

    Event e1 = getMockEvent();

    CHECK(e1.getName() == testName);
    CHECK(e1.getDescription() == testDescription);
    CHECK(e1.getTotalDurationQuarters() == testTotalDuration);

    CHECK(e1.getQuartersElapsed() == 0);

    CHECK(e1.getResearchArea() == testResearchArea);
    CHECK(e1.getResearchDifficulty() == testResearchDifficulty);

    CHECK(e1.getResearchInsights().size() == testInsights.size());
    if (!testInsights.empty()) {
        CHECK(e1.getResearchInsights()[0] == testInsights[0]);
    }

    CHECK(e1.getQuartersBeforeTrigger() == testQBeforeTrigger);
    CHECK(e1.isActive());

    CHECK(e1.getEffectRules().empty());
}
