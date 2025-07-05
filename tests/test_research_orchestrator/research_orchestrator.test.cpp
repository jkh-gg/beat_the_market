
#include "research_orchestrator/research_orchestrator.h"

#include "../../dependencies/doctest/doctest.h"
#include "event_ecosystem/event_orchestrator/event_orchestrator.h"
#include "player/player.h"

TEST_CASE("Research orchestrator init") {
    Player p1("Alice", 1000.0);
    EventOrchestrator eo;

    ResearchOrchestrator ro(&p1, &eo);

    CHECK(ro.getCurrentInsights().empty());
    CHECK(ro.getPastInsights().empty());
}
