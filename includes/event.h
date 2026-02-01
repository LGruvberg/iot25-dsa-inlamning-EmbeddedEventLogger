#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVENT_SENSOR_READING,
    EVENT_ALARM,
    EVENT_SYSTEM
} EventType;

typedef struct {
    int timestamp; 
    // OBS: Timestamp ska vara stigande när events skapas (till exempel genom en global räknare som ökar med 1 för varje nytt event).
    int sensorId;
    EventType type;
    int value;
} Event;

#endif  // EVENT_H