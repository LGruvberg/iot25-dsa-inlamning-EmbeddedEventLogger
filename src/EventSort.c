#include "../includes/EventSort.h"
#include <assert.h>
#include <string.h>

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

//  Map string -> sorting strategy
EventSortFn event_sort_get(const char *name) {
    if (name == NULL) {
        return NULL;
    }

    if (strcmp(name, "insertion") == 0) {   // strcmp -> the string pointed to by name is exactly the same as "insertion"
        return event_sort_insertion;
    } 
    if (strcmp(name, "selection") == 0) {
        return event_sort_selection;
    }

    return NULL;
}