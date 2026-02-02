# iot25-dsa-inlamning-EmbeddedEventLogger
This repo contains code solutions for assignment in the course *Algorithms, Data Structures and Design Patterns*.

**GitHub repo:**
[iot25-dsa-inlamning-EmbeddedEventLogger](https://github.com/LGruvberg/iot25-dsa-inlamning-EmbeddedEventLogger.git)

## Compile instructions

1. **Navigate to the repository root:**
    `cd ..\iot25-dsa-inlamning-EmbeddedEventLogger\`
    *(Running 'ls' (list) from here should at least reveal the `includes` and `src` folders)*

2.  **Compile:**
    `gcc -std=c11 -Wall -Iincludes src/*.c -o event_logger`
    (... if the above does not compile, run the anti-lazy version:
    `gcc -std=c11 -Wall -Iincludes src/main.c src/EventLog.c src/EventQueue.c src/EventSort.c src/EventSearch.c -o event_logger` 
    )

3.  **Run .exe file:**
    `.\event_logger.exe`

---

## Overview, what it does

*The event_logger simulates sensor events and processes them like this producer/consumer pipeline:*
`Producer -> EventQueue -> Consumer -> EventLog`

Main components:
- **EventQueue:**
    Ring buffer that holds incoming events (fixed-size, First In First Out)
- **EventLog:**
    Stores processed events (grows dynamically)
- **Sorting:**
    Choose betweeen different sorting algorithms at runtime
- **Searching:**
    Find sensor events by ID (sensorId)
- **Tick-based event loop:**
    `tick <n>` runs the simulation for `n` steps.

### Notes
-   The event generation is deterministic, so you'll get the same behavior each time you run it with the same inputs. 
    -   I thought about adding randomization to make the results look more interesting (e.g. after sorting), but keeping it deterministic made testing easier.
-   Each data structure handles its own memory allocation/cleanup.