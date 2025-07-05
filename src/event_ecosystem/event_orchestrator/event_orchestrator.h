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
    std::vector<Event> getFutureEventsAt(int quarter) const;
    std::vector<Event> getActiveEvents() const { return activeEvents; }
};

#endif
