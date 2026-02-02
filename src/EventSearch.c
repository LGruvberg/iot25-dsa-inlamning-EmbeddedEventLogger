#include "../includes/EventSearch.h"
#include <stdio.h>
#include <assert.h>

void event_log_search_by_sensor(const EventLog *log, int sensorId) {
    assert(log != NULL);
    int found = 0;
    
    for (int i = 0; i < event_log_size(log); i++) {
        Event e = event_log_get(log, i);
        if (e.sensorId == sensorId) {
            printf("Time: %d Sensor: %d Type: %d Value: %d\n",
                e.timestamp, e.sensorId, e.type, e.value);
            found = 1;
        }
    }
    if (!found) {
        printf("No events found for sensor %d\n", sensorId);
    }
}
