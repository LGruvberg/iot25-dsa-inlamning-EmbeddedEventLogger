#include "../includes/EventQueue.h"
#include <stdlib.h>
#include <assert.h>

void event_queue_init(EventQueue *queue, int capacity) {
    assert(queue != NULL);
    assert(capacity > 0);

    queue->buffer = malloc(sizeof(Event) * capacity);
    assert(queue->buffer != NULL);

    queue->capacity = capacity;
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
}

void event_queue_free(EventQueue *queue) {
    assert(queue != NULL);

    free(queue->buffer);
    queue->buffer = NULL;
    queue->capacity = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
}

int event_queue_is_empty(const EventQueue *queue) {
    assert(queue != NULL);
    return queue->count == 0;
}

int event_queue_is_full(const EventQueue *queue) {
    assert(queue != NULL);
    return queue->count == queue->capacity;
}

int event_queue_enqueue(EventQueue *queue, Event event) {
    assert(queue != NULL);

    if (event_queue_is_full(queue)) {
        return 0;
    }

    queue->buffer[queue->tail] = event;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->count++;

    return 1;
}

int event_queue_dequeue(EventQueue *queue, Event *out_event) {
    assert(queue != NULL);
    assert(out_event != NULL);

    if (event_queue_is_empty(queue)) {
        return 0;
    }

    *out_event = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->count--;

    return 1;
}