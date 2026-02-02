#pragma once

typedef enum {
    EVENT_SENSOR_READING,
    EVENT_ALARM,
    EVENT_SYSTEM
} EventType;

typedef struct {
    int timestamp;
    int sensorId;
    EventType type;
    int value;
} Event;