#include "research_orchestrator.h"

ResearchOrchestrator::ResearchOrchestrator(Player* player,
                                           EventOrchestrator* eventOrchestrator)
    : playerPtr(player), eoPtr(eventOrchestrator){};
