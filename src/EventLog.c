#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../includes/EventLog.h"

void event_log_init(EventLog *log, int initial_capacity) {
    assert(log != NULL);
    assert(initial_capacity > 0);

    log->size = 0;
    log->capacity = initial_capacity;
    log->events = malloc(sizeof(Event) * initial_capacity);

    assert(log->events != NULL);
}

void event_log_free(EventLog *log) {
    assert(log != NULL);
    free(log->events);
    log->events = NULL;
    log->size = 0;
    log->capacity = 0;
}

int event_log_add(EventLog *log, Event event) {
    assert(log != NULL);

    if (log->size >= log->capacity) {
        int new_capacity = log->capacity * 2;

        Event *new_events =
            realloc(log->events, sizeof(Event) * new_capacity);

        if (new_events == NULL) {
            return 0;   // if allocation failed
        }
        
            log->events = new_events;
            log->capacity = new_capacity;
        }
        log->events[log->size++] = event;

        return 1;
}

int event_log_size(const EventLog *log) {
    assert(log != NULL);
    return log->size;
}

Event event_log_get(const EventLog *log, int index) { //  GET
    assert(log != NULL);
    assert(index >= 0 && index < log->size);

    return log->events[index];
}

void event_log_set(EventLog *log, int index, Event event) { //  SET
    assert(log != NULL);
    assert(index >= 0 && index < log->size);

    log->events[index] = event;
}

void event_log_print(const EventLog *log) {
    assert(log != NULL);

    for (int i=0; i < log->size; i++) {
        printf("Time: %d Sensor: %d Type: %d Value: %d\n",
            log->events[i].timestamp,
            log->events[i].sensorId,
            log->events[i].type,
            log->events[i].value
        );
    }
}

void event_log_find_by_sensor(const EventLog *log, int sensorId) {
    assert(log != NULL);

    int found = 0;
    for (int i = 0; i < log->size; i++) {
        if (log->events[i].sensorId == sensorId) {
            printf("Time: %d Sensor: %d Type: %d Value: %d\n",
            log->events[i].timestamp,
            log->events[i].sensorId,
            log->events[i].type,
            log->events[i].value
        );
        found = 1;
    }
}
    if (!found) {
        printf("No events found for sensor %d\n", sensorId);
    }
}