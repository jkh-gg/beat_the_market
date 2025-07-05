#include "event_mocks.h"

Event getMockEvent() {
    std::string testName = "Economic Downturn";
    std::string testDescription = "A period of reduced economic activity.";
    int testTotalDuration = 8;
    std::string testResearchArea = "Macroeconomics";
    int testResearchDifficulty = 7;
    std::vector<std::string> testInsights = {"Inflation", "Unemployment"};
    int testQBeforeTrigger = 2;
    std::vector<EventEffect> testEffectRules;

    return Event(testName, testDescription, testTotalDuration, testResearchArea,
                 testResearchDifficulty, testInsights, testQBeforeTrigger,
                 testEffectRules);
}
