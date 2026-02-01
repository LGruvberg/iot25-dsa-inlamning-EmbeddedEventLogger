#pragma once
#include "Event.h"

typedef struct {
    Event *events;  // dynamically allocated array of Event
    int size;       // no. of stored events
    int capacity;   // allocated capacity
} EventLog; // The struct exists so the ADT has somewhere to keep its data
/*
Lifecycle functions:
    Init an EventLog

    Preconditions:
    -   log != NULL
    -   initial_capacity > 0

    Postconditions:
    -   log->size == 0
    -   log->capacity == initial capacity
    -   log->events points to allocated memory */

// Free all memory owned by EventLog    !Fromulera OM!!
void event_log_init(EventLog *log, int initial_capacity); 
/*After this call:
-   log is left in a safe empty state
-   it may be re-initialized again*/
void event_log_free(EventLog *log);
/*Core operations:
Append an event to the log
If the log is full, it grows dynamically.
    Returns:
    -   1 on success
    -   0 if memory allocation fails*/
int event_log_add(EventLog *log, Event event);
// GET number of stored events.
int event_log_size(const EventLog *log);
/*  get event at index
        Preconditions:
        -   0 <= index < log->size
    */
Event event_log_get(const EventLog *log, int index);
/*Overwrite event at index
        Preconditions:
        -   0 <= index < log->size*/
void event_log_set(EventLog *log, int index, Event event);
/*Print all events in the log
(Temporary helper for debugging and testing)
*/
void event_log_print(const EventLog *log);

// EVENT_LOG_H       // KÖR enkel array ist för länkade listor