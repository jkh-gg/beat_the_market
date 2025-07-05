#ifndef RESEARCH_ORCHESTRATOR_H
#define RESEARCH_ORCHESTRATOR_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include "../common/research_area.h"
#include "../event_ecosystem/event_orchestrator/event_orchestrator.h"
#include "../player/player.h"

class ResearchOrchestrator {
   private:
    std::map<ResearchArea, int> playerResearchScores;

    // TODO - this can probably go in the enum file along
    // with a conversion to dollar amounts
    std::map<ResearchArea, int> baseResearchCost;

    std::vector<std::string> currentInsights;
    std::vector<std::string> pastInsights;

    // This is a good idea, but we probably need to work this out in the events
    // themselves
    std::set<std::string> revealedEventInsightKeys;

    Player* playerPtr;
    EventOrchestrator* eoPtr;

   public:
    ResearchOrchestrator(Player* player, EventOrchestrator* eventOrchestrator);

    std::vector<std::string> getCurrentInsights() const {
        return currentInsights;
    }
    std::vector<std::string> getPastInsights() const { return pastInsights; }
};

#endif
