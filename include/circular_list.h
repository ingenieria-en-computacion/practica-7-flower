#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// -------- Macro de declaración --------
#define DECLARE_CIRCULAR_LIST(TYPE) \
    typedef struct NodeCirc_##TYPE { \
        TYPE data; \
        struct NodeCirc_##TYPE* next; \
    } NodeCirc_##TYPE; \
    \
    typedef struct { \
        NodeCirc_##TYPE* head; \
        NodeCirc_##TYPE* tail; \
        size_t length; \
    } CircularList_##TYPE; \
    \
    CircularList_##TYPE* circular_list_##TYPE##_create(void); \
    void circular_list_##TYPE##_destroy(CircularList_##TYPE* list); \
    bool circular_list_##TYPE##_append(CircularList_##TYPE* list, TYPE data); \
    bool circular_list_##TYPE##_remove_at(CircularList_##TYPE* list, size_t pos); \
    void circular_list_##TYPE##_print(const CircularList_##TYPE* list, void (*print_fn)(TYPE)); \
    size_t circular_list_##TYPE##_length(const CircularList_##TYPE* list);

// -------- Declaraciones concretas --------
DECLARE_CIRCULAR_LIST(int)
DECLARE_CIRCULAR_LIST(float)
DECLARE_CIRCULAR_LIST(char)
