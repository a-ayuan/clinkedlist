# Circular Linked List in C

This code implements a circular doubly linked list in C, providing several utility functions to manipulate and display the list. It includes functions to find the list tail, calculate its length, search for values, remove nodes, and insert new values either before or after specified positions. The program demonstrates these functions in the `main` function by creating a list and performing several operations.

## File Structure
The program includes:
- `#include <stdio.h>`
- `#include <stdlib.h>`
- `#include "linkedlist.h"` (a custom header presumably containing the definition of `cll_node` structure)

## Functions

### `cll_tail`
```c
cll_node *cll_tail(cll_node *list);
```

Finds and returns the tail node of a circular linked list (the last node that points back to the head). If the list is empty, it returns NULL.
