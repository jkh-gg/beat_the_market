#include "event_orchestrator.h"

void EventOrchestrator::addFutureEventAt(int quarter, Event newEvent) {
    std::vector<Event>& eventsAt = getFutureEventsAt(quarter);
    eventsAt.push_back(newEvent);
}
