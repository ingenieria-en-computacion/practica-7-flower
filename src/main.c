#define LINKED_LIST_IMPLEMENTATION
#include "../include/circular_list.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d", value);
}

bool int_cmp(int a, int b) {
    return a == b;
}

void print_char(char value) {
    printf("%c", value);
}

bool char_cmp(char a, char b) {
    return a == b;
}

int main() {
    // Lista circular de enteros
    CircularList_int* nums = circular_list_int_create();
    circular_list_int_append(nums, 10);
    circular_list_int_append(nums, 20);

    printf("Lista circular de enteros: ");
    circular_list_int_print(nums, print_int);

    circular_list_int_destroy(nums);

    // Lista circular de caracteres
    CircularList_char* chars = circular_list_char_create();
    circular_list_char_append(chars, 'a');
    circular_list_char_append(chars, 'b');
    circular_list_char_append(chars, 'c');
    circular_list_char_append(chars, 'd');
    circular_list_char_append(chars, 'e');

    printf("Lista circular de caracteres: ");
    circular_list_char_print(chars, print_char);

    circular_list_char_destroy(chars);
    return 0; }
