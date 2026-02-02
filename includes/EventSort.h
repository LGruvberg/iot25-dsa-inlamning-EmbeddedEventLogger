#pragma once
#include "EventLog.h"

//  Sort function type (Strategy)
typedef void (*EventSortFn)(EventLog *log);

//  Sorting algorithms
void event_sort_insertion(EventLog *log);
void event_sort_selection(EventLog *log);

//  Strategy selection
EventSortFn event_sort_get(const char *name);