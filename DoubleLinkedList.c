#include "DoubleLinkedList.h"
#include <stdlib.h>
// Some function headers and structs by Phil Howard
// Rest by Erik Andersen <erik.andersen@oit.edu>, 2016-01-28

// Double Linked list Node
typedef struct item_s
{
    int data;
    struct item_s *next;
    struct item_s *prev;
} item_t;

// Double linked list
typedef struct list_s
{
    item_t * head;
    item_t * tail;
    int count;
} list_t;

// Creates a new node. Safe to free a pointer to this without a deconstructor
// function as all pointers in this are managed by the linked list
item_t * NewItem_t(item_t * p, item_t * n, int d)
{
    item_t * this = malloc(sizeof(item_t));
    this->data = d;
    this->next = n;
    this->prev = p;
    return this;
}

// Return the number of nodes in the linked list
// Params:
//     list: the list to get the size of
int Count(linked_list_t list)
{
    list_t * this = (list_t *)list; 
    return this->count;
}

// Create and initialize a list. 
// Return pointer to list. Return NULL on failure.
linked_list_t* Init_List()
{
    list_t * this = (list_t *)malloc(sizeof(list_t));
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
    return (linked_list_t *)this;
}


/*********************************************************************
* Purpose: Take a node object that has its pointers set properly to be
*  between nodes (including at the end of the list), and update the 
*  "nodes" (including head or tail if needed) on either side so it
*   is between them.
*  Entry: Node pointed to by newItem has the next and previous pointers
*  pointed at two adjacent nodes in the list.
*********************************************************************/
void DLL_wedgeNode(linked_list_t list, item_t * newItem)
{
    list_t * this = (list_t *)list; 
    // if true, @ end of list, update this->tail pointer
    if (newItem->next == NULL) 
    {
        this->tail = newItem;
    }
    else
    {
        newItem->next->prev = newItem;
    }
    // if true, @ start of list, update head pointer
    if (newItem->prev == NULL)
    {
        this->head = newItem;
    }
    else
    {
        newItem->prev->next = newItem;
    }
    ++(this->count);
}

// Return true (non-zero) if the list is empty
//    list: list to examine
int Empty(linked_list_t list)
{
    list_t * this = (list_t *)list; 
    if (this->head == NULL || this->tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Delete a list are free all memory used by the list
// It is erroneous to use the list pointer after caling this routine.
// Return zero on success
int Delete_List(linked_list_t list)
{
    list_t * this = (list_t *)list; 
    item_t * tempHead = this->head;
    this->head = NULL;
    this->tail = NULL;

    while (tempHead != NULL)
    {
        item_t * next = tempHead->next;
        free(tempHead);
        tempHead = next;
    }
    this->count = 0;
    return 0;
}

// Insert an item at the beginning of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_Beginning(linked_list_t list, int data)
{
    list_t * this = (list_t *)list; 
    item_t * newNode = NewItem_t((item_t *)NULL, this->head, data);
    /* Data structure inconsistent after this */
    if (newNode->next == NULL)
    {
        this->tail = newNode;
    }
    else
    {
        newNode->next->prev = newNode;
    }
    this->head = newNode;
    ++(this->count); // Parenthesis not required, but more readable
    /* Data structure consistent again */
    return 0;
}


// Insert an item at the end of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_End(linked_list_t list, int data)
{
    list_t * this = (list_t *)list; 
    item_t * newNode = NewItem_t(this->tail, (item_t *)NULL, data);
    /* Data structure inconsistent after this */
    if (newNode->prev == NULL)
    {
        this->head = newNode;
    }
    else
    {
        newNode->prev->next = newNode;
    }
    this->tail = newNode;
    ++(this->count); // Parenthesis not required, but more readable
    /* Data structure consistent again */
    return 0;
}


// Remove an item from the beginning of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_Beginning(linked_list_t list, int* data)
{
    list_t * this = (list_t *)list; 
    if (this->head == NULL || this->tail == NULL)
    {
        return 1;
    }
    else
    {
        item_t * toRemove = this->head;
        *data = toRemove->data;
        // Go to the next node, the one that will be the in front when we are done
        item_t * nextFront = toRemove->next;
        /* Data structure inconsistent after this */

        // If next front is null, then we just took out the last item in the list
        if (nextFront == NULL)
        {
            this->tail = NULL;
        }
        else
        {
            // If its not null, then there is still at least one thing, and we need to update it's 
            // previous pointer to stop pointing at the old object and set it to NULL to say it's
            // at the start of the list
            nextFront->prev = NULL;
        }
        this->head = nextFront;
        --(this->count); // Parenthesis not required, but helpful for reading
        /* Data structure consistent again */
        free(toRemove);
        return 0;
    }
}


// Remove an item from the end of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_End(linked_list_t list, int* data)
{
    list_t * this = (list_t *)list; 
    if (this->head == NULL || this->tail == NULL)
    {
        return 1;
    }
    else
    {
        item_t * toRemove = this->tail;
        *data = toRemove->data;
        // Go to the next node, the one that will be the in front when we are done
        item_t * nextBack = toRemove->prev;
        /* Data structure inconsistent after this */
        // If next front is null, then we just took out the last item in the list
        if (nextBack == NULL)
        {
            this->head = NULL;
        }
        else
        {
            // If its not null, then there is still at least one thing, and we need to update it's 
            // previous pointer to stop pointing at the old object and set it to NULL to say it's
            // at the start of the list
            nextBack->next = NULL;
        }
        this->tail = nextBack;
        --(this->count); // Parenthesis not required, prefix decrement is lower precedence than ->
        /* Data structure consistent again */
        free(toRemove);
        return 0;
    }
}

// Traverse our list, calling the callback function action
// Return 0 on success
// Params:
//    list: list to traverse
//    action: callback to call with int data. Must return void
int Traverse(linked_list_t list, void (*action)(int data))
{
    list_t * this = (list_t *)list;
    item_t * travel = this->head;
    while (travel != NULL)
    {
        action(travel->data);
        travel = travel->next;
    }
    // Didn't specify what to return, so I'll just return 0 since that means
    // success everywhere else
    return 0;
}

// Insert int into the list in the proper sorted position
// Return 0 on success
// Params:
//     list: list to insert int into
//     value: int to insert into the list
int Insert_in_order(linked_list_t list, int value)
{
    list_t * this = (list_t *)list;
    
    // Track where we are in the list
    item_t * travel = this->head;
    
    // Find where to put it, stopping when we find something larger or the end 
    // of the list
    while (NULL != travel && value > travel->data)
    {
       travel = travel->next; 
    }
    // If we found the end of the list instead of something larger, than 
    // just append to the list
    if (NULL == travel)
    {
        return Insert_At_End(this, value);
    }
    // Otherwise, just insert it before the item we found that was larger
    else
    {
        // Create the node
        // Note that traverse->prev could be NULL, if we are prepending the
        // list, but DLL_wedgeNode handles that
        item_t * newNode = NewItem_t(travel->prev, travel, value);
        // Wedge the node in
        DLL_wedgeNode(this, newNode);
    }
    // return 0 to say it worked
    return 0;
}