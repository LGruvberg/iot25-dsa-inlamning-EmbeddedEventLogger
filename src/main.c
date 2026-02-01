// [ Producer ] -> EventQueue -> [ Consumer ] -> EventLog
#include <stdio.h>
#include "../includes/Event.h"
#include "../includes/EventLog.h"
#include "../includes/EventQueue.h"

int main(void) {
    EventQueue queue;
    EventLog log;

    event_queue_init(&queue, 4);
    event_log_init(&log, 4);
    
    //  PRODUCER (simulated)
    for (int t = 0; t < 6; t++) {
        Event e = {
            .timestamp = t,
            .sensorId = 1,
            .type = EVENT_SENSOR_READING,
            .value = 100 + t
        };

        if(!event_queue_enqueue(&queue, e)) {
            printf("Queue full at time %d\n", t);
        }
    }
    //  CONSUMER
    Event temp;
    while (!event_queue_is_empty(&queue)) {
        event_queue_dequeue(&queue, &temp);
        event_log_add(&log, temp);
    }
    //  INSPECT RESULT
    event_log_print(&log);
    event_queue_free(&queue);
    event_log_free(&log);

    return 0;

}