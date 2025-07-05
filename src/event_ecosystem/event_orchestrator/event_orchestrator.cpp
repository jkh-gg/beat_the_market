#include "event_orchestrator.h"

std::vector<Event> EventOrchestrator::getFutureEventsAt(int quarter) const {
    try {
        std::vector<Event> events = quarterToEventMap.at(quarter);
        return events;
    } catch (const std::exception& e) {
        return std::vector<Event>();
    }
}
