#pragma once
#include "Event.h"

//  FIFO-queue implemented as ring buffer
typedef struct {
    Event *buffer;  // fixed-size array
    int capacity;   // max number of elements
    int head;       // index of next element to dequeue
    int tail;       // index of next element to enqueue
    int count;      // current number of elements
}   EventQueue;

//  Lifecycle
void event_queue_init(EventQueue *queue, int capacity);
void event_queue_free(EventQueue *queue);

//  Status checks
int event_queue_is_empty(const EventQueue *queue);
int event_queue_is_full(const EventQueue *queue);

//  Operations
int event_queue_dequeue(EventQueue *queue, Event *out_event);
int event_queue_enqueue(EventQueue *queue, Event event);