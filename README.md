This project implements a circular doubly linked list in C, providing several utility functions to manipulate and display the list. It includes functions to find the list tail, calculate its length, search for values, remove nodes, and insert new values either before or after specified positions. The program demonstrates these functions in the `main` function by creating a list and performing several operations.

## File Structure

The program includes:
- `#include <stdio.h>`
- `#include <stdlib.h>`
- `#include "linkedlist.h"` (a custom header, presumably containing the definition of the `cll_node` structure)

## Functions

### `cll_tail`

```c
cll_node *cll_tail(cll_node *list);
```

Finds and returns the tail node of a circular linked list (the last node that points back to the head). If the list is empty, it returns `NULL`.

### `cll_length`

```c
unsigned long cll_length(cll_node *list);
```

Calculates and returns the number of nodes in the circular linked list. If the list is empty, it returns 0.

### `cll_find`

```c
cll_node *cll_find(cll_node *list, int value);
```

Searches for the first occurrence of a node containing `value` in the list. Returns a pointer to the node if found, otherwise returns `NULL`.

### `cll_remove`

```c
cll_node *cll_remove(cll_node *list, cll_node *node);
```

Removes the specified `node` from the list. If the node is the head, it updates the list head. Memory for the removed node is freed. Returns the new head of the list.

### `cll_insert`

```c
cll_node *cll_insert(int value, cll_node *list, int before);
```

Inserts a new node with the specified `value` into the list. The `before` parameter determines whether the node is inserted before or after the head. If the list is empty, it initializes it with a single node. Returns the head of the updated list.

### `cll_show`

```c
void cll_show(cll_node *list);
```

Displays the contents of the list in a comma-separated format surrounded by brackets. If the list is empty, it prints `[]`.

## `main` Function

The `main` function demonstrates the functionality of the circular linked list functions:
1. Creates an empty list.
2. Inserts several nodes with different values.
3. Displays the list after each insertion.
4. Prints the length of the list.
5. Removes nodes from the list and displays the list after each removal.

### Example Output

Each letter in the output corresponds to a step in the `main` function:

```text
A[]             // Initial empty list
B[25]           // Insert 25
C[25, 1]        // Insert 1 after 25
D[98, 25, 1]    // Insert 98 before 25
...
Length: 6       // Display list length
```

This code demonstrates a straightforward implementation of a circular linked list with various operations, making it useful for managing dynamically sized, non-linear data in memory.
