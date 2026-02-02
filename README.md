# iot25-dsa-inlamning-EmbeddedEventLogger
This repo contains code solutions for assignment in the course *Algorithms, Data Structures and Design Patterns*.

**REPORT:**
[love-gruvberg-iot25-dsa-inlamning-EmbeddedEventLogger-report](https://docs.google.com/document/d/12YaVIcAoNuyYWEqmsAa9NEmTgvA1Xeg6tlWy48Y859k/edit?usp=sharing)

**GitHub repo:**
[iot25-dsa-inlamning-EmbeddedEventLogger](https://github.com/LGruvberg/iot25-dsa-inlamning-EmbeddedEventLogger.git)

---

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

---

### Example run

To create an event, select menu option 1, **Tick <n>**
    Enter number of ticks: **5**

<img width="576" height="326" alt="image" src="https://github.com/user-attachments/assets/e0d76f0d-2b5a-4448-b47b-322a386cd68a" />

    *5 Ticks have been executed*

To see them, select menu option 2, **Print log**

<img width="443" height="443" alt="image" src="https://github.com/user-attachments/assets/0c097dbc-6f32-40c1-bd2d-325f4d243842" />

To sort log, select menu option 3, **Sort log using <algorithm>**
Input: **'selection'**
*Sorting using selection sort*

<img width="645" height="294" alt="image" src="https://github.com/user-attachments/assets/c59eb2ca-2bc3-47bf-b72e-afc9edd0415b" />

To search by sensor ID, select menu option 4, **Find sensor ID** 
input: **3**

<img width="469" height="574" alt="image" src="https://github.com/user-attachments/assets/d9862e3d-190b-4deb-b89b-5e5dd76e6e2c" />