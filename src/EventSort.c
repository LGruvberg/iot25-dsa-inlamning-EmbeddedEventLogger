#include "../includes/EventSort.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void event_sort_insertion(EventLog *log) {
    assert(log != NULL);

    for (int i = 1; i < event_log_size(log); i++) {
        Event key = event_log_get(log, i);
        int j = i - 1;

        while (j >= 0 && event_log_get(log, j).timestamp > key.timestamp) {
            event_log_set(log, j + 1, event_log_get(log, j));
            j--;
        }
        event_log_set(log, j + 1, key);
    }
}

void event_sort_selection(EventLog *log) {
    assert(log != NULL);

    int n = event_log_size(log);

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (event_log_get(log, j).timestamp 
                < event_log_get(log, min_index).timestamp) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Event temp = event_log_get(log, i);
            event_log_set(log, i, event_log_get(log, min_index));
            event_log_set(log, min_index, temp);
        }
    }
}
//  Sort registry
typedef struct {
    const char *name;
    EventSortFn fn;
} EventSortEntry;

static EventSortEntry SORTS[] = {
    { "insertion", event_sort_insertion },
    { "selection", event_sort_selection }
};

static const int SORT_COUNT = sizeof(SORTS) / sizeof(SORTS[0]);

//  Map string -> sorting strategy
EventSortFn event_sort_get(const char *name) {
    if (!name) return NULL;

    for (int i = 0; i < SORT_COUNT; i++) {
        if (strcmp(SORTS[i].name, name) == 0) { // NTS: strcmp returns 0 when two strings have identical contents (match algorithm name)
            return SORTS[i].fn;
        }
    }

    return NULL;
}

void event_sort_print_available(void) {
    printf("\nAvailable sort algorithms:\t");
    for (int i = 0; i < SORT_COUNT; i++) {
        printf("'%s'%s", SORTS[i].name,
               (i < SORT_COUNT - 1) ? ", " : "");
    }
    printf("\n");
}