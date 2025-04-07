#define LINKED_LIST_IMPLEMENTATION
#include "../include/circular_list.h"

// -------- Macro de implementación --------
#define IMPLEMENT_CIRCULAR_LIST(TYPE) \
    CircularList_##TYPE* circular_list_##TYPE##_create(void) { \
        CircularList_##TYPE* list = malloc(sizeof(CircularList_##TYPE)); \
        list->head = list->tail = NULL; \
        list->length = 0; \
        return list; \
    } \
    void circular_list_##TYPE##_destroy(CircularList_##TYPE* list) { \
        if (!list || !list->head) return; \
        NodeCirc_##TYPE* current = list->head; \
        do { \
            NodeCirc_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } while (current != list->head); \
        free(list); \
    } \
    bool circular_list_##TYPE##_append(CircularList_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        NodeCirc_##TYPE* new_node = malloc(sizeof(NodeCirc_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        if (!list->head) { \
            new_node->next = new_node; \
            list->head = list->tail = new_node; \
        } else { \
            new_node->next = list->head; \
            list->tail->next = new_node; \
            list->tail = new_node; \
        } \
        list->length++; \
        return true; \
    } \
    bool circular_list_##TYPE##_remove_at(CircularList_##TYPE* list, size_t pos) { \
        if (!list || list->length == 0 || pos >= list->length) return false; \
        NodeCirc_##TYPE* current = list->head; \
        NodeCirc_##TYPE* prev = list->tail; \
        for (size_t i = 0; i < pos; ++i) { \
            prev = current; \
            current = current->next; \
        } \
        if (current == list->head) list->head = current->next; \
        if (current == list->tail) list->tail = prev; \
        if (list->length == 1) list->head = list->tail = NULL; \
        else prev->next = current->next; \
        free(current); \
        list->length--; \
        return true; \
    } \
    void circular_list_##TYPE##_print(const CircularList_##TYPE* list, void (*print_fn)(TYPE)) { \
        if (!list || !list->head || !print_fn) return; \
        printf("["); \
        NodeCirc_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; ++i) { \
            print_fn(current->data); \
            if (i != list->length - 1) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    } \
    size_t circular_list_##TYPE##_length(const CircularList_##TYPE* list) { \
        return list ? list->length : 0; \
    }

// -------- Implementaciones concretas --------
IMPLEMENT_CIRCULAR_LIST(int)
IMPLEMENT_CIRCULAR_LIST(float)
IMPLEMENT_CIRCULAR_LIST(char)
