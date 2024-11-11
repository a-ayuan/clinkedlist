#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

cll_node *cll_tail(cll_node *list) {
    if (list == NULL) {
        return NULL;
    }

    cll_node *tail = list;
    while (tail->next != list) {
        tail = tail->next;
    }

    return tail;
}


unsigned long cll_length(cll_node *list) {
    if (list == NULL) {
        return 0;
    }

    unsigned long length = 0;
    cll_node *current = list;

    do {
        length++;
        current = current->next;
    } while (current != list);

    return length;
}


cll_node *cll_find(cll_node *list, int value) {
    if (list == NULL) {
        return NULL;
    }

    cll_node *current = list;
    do {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    } while (current != list);

    return NULL;
}


cll_node *cll_remove(cll_node *list, cll_node *node) {
    if (list == NULL || node == NULL) {
        return list;
    }

    cll_node *prev = node->prev;
    cll_node *next = node->next;

    if (node == list) { 
        if (list->next == list) {
            free(node);
            return NULL;
        } else { 
            list = next;
        }
    }

    prev->next = next;
    next->prev = prev;

    free(node);

    return list;
}


cll_node *cll_insert(int value, cll_node *list, int before) {
    cll_node *newNode = (cll_node *)malloc(sizeof(cll_node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;

    if (list == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }

    cll_node *tail = cll_tail(list);

    if (before) {
        newNode->prev = list->prev;
        newNode->next = list;
        list->prev->next = newNode;
        list->prev = newNode;
    } else {
        newNode->prev = list;
        newNode->next = list->next;
        list->next->prev = newNode;
        list->next = newNode;
    }

    return list;
}


/**
 * Displays the contents of the list separated by commas and surrounded by
 * brackets, with the pointed-to node highlighted with asterisks.
 */
void cll_show(cll_node *list) {
    if (list == NULL) {
        puts("[]");
        return;
    }

    cll_node *ptr = list;
    putchar('[');

    do {
        printf("%d", ptr->value);
        ptr = ptr->next;
        if (ptr != list) printf(", ");
    } while (ptr != list);

    puts("]");
}


int main(int argc, const char *argv[]) {

    cll_node *x = NULL;
    putchar('A'); cll_show(x);
    x = cll_insert(25, x, 1);
    putchar('B'); cll_show(x);
    x = cll_insert(1, x, 0);
    putchar('C'); cll_show(x);
    x = cll_insert(98, x, 1);
    putchar('D'); cll_show(x);
    x = cll_insert(0, x, 1);
    putchar('E'); cll_show(x);
    x = cll_insert(-8, cll_tail(x), 0);
    putchar('F'); cll_show(x);
    printf("Length: %lu\n", cll_length(x));
    x = cll_remove(x, x);
    putchar('G'); cll_show(x);
    x = cll_remove(x, cll_find(x, 98));
    putchar('H'); cll_show(x);

    return 0;
}
