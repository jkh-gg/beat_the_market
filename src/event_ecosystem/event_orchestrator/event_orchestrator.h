#ifndef EVENT_ORCHESTRATOR_H
#define EVENT_ORCHESTRATOR_H

#include <map>
#include <vector>

#include "../event/event.h"

class EventOrchestrator {
   private:
    std::map<int, std::vector<Event>> quarterToEventMap;
    std::vector<Event> activeEvents;

   public:
    std::vector<Event>& getFutureEventsAt(int quarter) {
        return quarterToEventMap[quarter];
    }
    std::vector<Event> getActiveEvents() const { return activeEvents; }

    void addFutureEventAt(int quarter, Event newEvent);
};

#endif
