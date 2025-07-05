// Event.h
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

#include "event_effect.h"

class Event {
   private:
    std::string name;
    std::string description;

    int totalDurationQuarters;
    int quartersElapsed;

    // Research-related Parameters
    std::string researchArea;
    int researchDifficulty;
    std::vector<std::string> researchInsights;
    int quartersBeforeTrigger;

    std::vector<EventEffect> effectRules;

   public:
    // Constructor
    Event(std::string name, std::string description, int totalDurationQuarters,
          std::string researchArea, int researchDifficulty,
          const std::vector<std::string> insights, int qBeforeTrigger,
          const std::vector<EventEffect> rules);

    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }

    int getTotalDurationQuarters() const { return totalDurationQuarters; }
    int getQuartersElapsed() const { return quartersElapsed; }

    std::string getResearchArea() const { return researchArea; }
    int getResearchDifficulty() const { return researchDifficulty; }
    const std::vector<std::string>& getResearchInsights() const {
        return researchInsights;
    }
    int getQuartersBeforeTrigger() const { return quartersBeforeTrigger; }
    bool isActive() const { return quartersElapsed < totalDurationQuarters; }

    const std::vector<EventEffect>& getEffectRules() const {
        return effectRules;
    }
};
#endif
