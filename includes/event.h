#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVENT_SENSOR_READING,
    EVENT_ALARM,
    EVENT_SYSTEM
} EventType;

typedef struct {
    int timestamp;
    int sensor_id;
    EventType type;
    int value;
} Event;

#endif