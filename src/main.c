// [Producer] -> EventQueue -> [Consumer] -> EventLog -> EventSort -> Print
#include "../includes/Event.h"
#include "../includes/EventLog.h"
#include "../includes/EventQueue.h"
#include "../includes/EventSort.h"
#include "../includes/EventSearch.h"
#include <stdio.h>

static Event generate_event(int tick, int offset) { // deterministic cycling makes behavior easier to test and reason about (instead of random values)
    Event e;
    e.timestamp = tick;
    e.sensorId = (tick + offset) % 3 + 1;
    e.type = (EventType)((tick + offset) % 3);
    e.value = 100 + tick;

    return e;
}

static void print_menu(void) {
    printf("\n.:MENU::Embedded Event Logger:.\n");
    printf("1.\tTick <n>\n");
    printf("2.\tPrint log\n");
    printf("3.\tSort log using <algorithm>\n");
    printf("4.\tFind sensor ID\n");
    printf("5.\tExit\n");
    printf("Choice:\t");
}

int main(void) {
    int current_tick = 0;
    EventQueue queue;
    EventLog log;
    event_queue_init(&queue, 4);
    event_log_init(&log, 4);

    int choice;
    int running = 1;

    while (running) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: { // tick <n> // [Produce]
            int n;
            printf("Enter number of ticks: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    Event e = generate_event(current_tick, j);
                    if (event_queue_enqueue(&queue, e)) {
                        Event temp;
                        event_queue_dequeue(&queue, &temp);
                        event_log_add(&log, temp);
                    }
                }
                current_tick++;
            }
            printf("%d ticks have been executed\n", n);
            break;
        }
        
        case 2: { // Print log
            event_log_print(&log);
            break;
        }
        case 3: { // Sort <algorithm>
            char sort_name[20];

            event_sort_print_available();
            printf("Enter sort algorithm:\t");
            scanf("%19s", sort_name);

            EventSortFn sort_fn = event_sort_get(sort_name);
            if (sort_fn) {
                sort_fn(&log);
                printf("Log sorted using '%s' sort\n", sort_name);
            } else {
                printf("Unknown: %s sort algorithm.\n", sort_name);
            }
            break;
        }
        
        case 4: { // Find
            int sensorId;
            printf("Enter sensor id: ");
            scanf("%d", &sensorId);
            event_log_search_by_sensor(&log, sensorId);
            break;
        }
        
        case 5: // EXIT
            running = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    event_queue_free(&queue);
    event_log_free(&log);

    return 0;
}