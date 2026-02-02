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

    //  Initialize EventLog with given initial capacity
    void event_log_init(EventLog *log, int initial_capacity); 

    // Free all memory owned by EventLog
    void event_log_free(EventLog *log);

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

  // Linear search -> print all events matching sensorId
  void event_log_find_by_sensor(const EventLog *log, int sensorId);