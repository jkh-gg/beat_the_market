#include "event.h"

Event::Event(std::string name, std::string description,
             int totalDurationQuarters, std::string researchArea,
             int researchDifficulty, std::vector<std::string> insights,
             int qBeforeTrigger, std::vector<EventEffect> rules)
    : name(name),
      description(description),
      totalDurationQuarters(totalDurationQuarters),
      quartersElapsed(0),
      researchArea(researchArea),
      researchDifficulty(researchDifficulty),
      researchInsights(insights),
      quartersBeforeTrigger(qBeforeTrigger),
      effectRules(rules){};
