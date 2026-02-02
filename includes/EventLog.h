#pragma once
#include "Event.h"

typedef struct{
    Event *events; 
    int size;      
    int capacity;  
} EventLog;

//  Initialize EventLog with given initial capacity
void event_log_init(EventLog *log, int initial_capacity);

// Free all memory owned by EventLog
void event_log_free(EventLog *log);

int event_log_add(EventLog *log, Event event);

int event_log_size(const EventLog *log);

Event event_log_get(const EventLog *log, int index);

void event_log_set(EventLog *log, int index, Event event);

void event_log_print(const EventLog *log);

// Linear search -> print all events matching sensorId
void event_log_find_by_sensor(const EventLog *log, int sensorId);