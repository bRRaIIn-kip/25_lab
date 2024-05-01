#include "Event.h"

int main() {
    EventManager eventManager;
    Group group;

    eventManager.setEventListener(&group);
    eventManager.processCommands();

    return 0;
}
