#pragma once
//*************************************************
// linked list definition
//
// This header files defines types and functions for a linked list used to 
// store key-value pairs.
//
// Author: Philip Howard
// Date:   2015/12/30
// Two lines added at the end of the file by Erik Andersen <erik.andersen@oit.edu> on 2016-01-28
//

// Opaque type for lists
typedef void *linked_list_t;

// Create and initialize a list. 
// Return pointer to list. Return NULL on failure.
linked_list_t* Init_List();

// Delete a list are free all memory used by the list
// It is erroneous to use the list pointer after caling this routine.
// Return zero on success
int Delete_List(linked_list_t list);

// Insert an item at the beginning of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_Beginning(linked_list_t list, int data);

// Insert an item at the end of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_End(linked_list_t list, int data);

// Return true (non-zero) if the list is empty
//    list: list to examine
int Empty(linked_list_t list);

// Remove an item from the beginning of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_Beginning(linked_list_t list, int* data);

// Remove an item from the end of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_End(linked_list_t list, int* data);

// Return the number of nodes in the linked list
// Params:
//     list: the list to get the size of
int Count(linked_list_t);

// Traverse the list, calling action on each int
// Return 0 on success
// Params:
//    list: list to traverse
//    action: callback to call with int data. Must return void
int Traverse(linked_list_t list, void (*action)(int data));

// Insert int into the list in the proper sorted position
// Return 0 on success
// Params:
//     list: list to insert int into
//     value: int to insert into the list
int Insert_in_order(linked_list_t list, int value);
