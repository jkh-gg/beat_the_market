#include "event_ecosystem/event_orchestrator/event_orchestrator.h"

#include <string>
#include <vector>

#include "../../dependencies/doctest/doctest.h"
#include "utils/event_mocks.h"

TEST_CASE("Testing EventOrchestrator methods") {
    EventOrchestrator orchestrator;

    Event e1 = getMockEvent();
    Event e2 = getMockEvent();
    Event e3 = getMockEvent();

    orchestrator.addFutureEventAt(0, e1);
    orchestrator.addFutureEventAt(1, e2);
    orchestrator.addFutureEventAt(1, e3);

    std::vector<Event> q1Events = orchestrator.getFutureEventsAt(0);
    CHECK(q1Events.size() == 1);

    std::vector<Event> q2Events = orchestrator.getFutureEventsAt(1);
    CHECK(q2Events.size() == 2);

    std::vector<Event> q3Events = orchestrator.getFutureEventsAt(2);
    CHECK(q3Events.size() == 0);
}
