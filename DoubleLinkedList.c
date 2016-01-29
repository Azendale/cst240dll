#include "DoubleLinkedList.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct item_s
{
    int data;
    struct item_s *next;
    struct item_s *prev;
} item_t;

typedef struct list_s
{
	item_t * head;
	item_t * tail;
	int count;
} list_t;

item_t * NewItem_t(item_t * p, item_t * n, int d)
{
	item_t * this = malloc(sizeof(item_t));
	this->data = d;
	this->next = n;
	this->prev = p;
	return this;
}

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
* Purpose: Remove a node (with still valid next and previous pointers
*  for its position in the list) and remove it from the list. Does NOT
*  delete the object pointed to by toRemove.
* Entry: Node pointed to by toRemove has the next and previous pointers
*  pointed at two adjacent "nodes" (including the head/tail pointers,
*  where appropriate) in the list.
*********************************************************************/
/*
int DLL_RemoveNode(linked_list_t list, linked_list_t list, item_t * toRemove)
{
	list_t * this = (list_t *)list; 
	if (toRemove->prev == NULL)
	{
		this->head = toRemove->next;
	}
	else
	{
		toRemove->prev->next = toRemove->next);
	}
	if (toRemove->next == NULL)
	{
		this->tail = toRemove->prev;
	}
	else
	{
		toRemove->next->prev = toRemove->prev);
	}
}
*/

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
}

/*********************************************************************
* Purpose: Remove all elements of the list, leaving an empty list.
* Exit: List empty, no dynamically allocated memory left.
********************************************************************/
/*
void DLL_Purge(linked_list_t list)
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
}
*/
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

/*********************************************************************
* Purpose: Return a pointer to the first or last item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
* Exit: List unchanged (but possible to change because there is now a pointer to data in it.)
********************************************************************/
/*
item_t * DLL_FindData(linked_list_t list, int searchTerm, int backward)
{
	list_t * this = (list_t *)list; 
	item_t * temp = NULL;
	if (backward)
	{
		temp = this->tail;
		// Using short-circuit logic here to avoid NULL dereference
		while (temp != NULL && temp->data != searchTerm)
		{
			temp = temp->prev;
		}
	}
	else
	{
		temp = this->head;
		while (temp != NULL && temp->data != searchTerm)
		{
			temp = temp->next;
		}
	}
	return temp;
}
*/

/*********************************************************************
* Purpose: Return a pointer to the Ith element
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a pointer to data in it.)
********************************************************************/
/*
item_t * DLL_GetIndex(linked_list_t list, int index)
{
	list_t * this = (list_t *)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "Empty list.";
	}
	if (index < 0)
	{
		throw "Negative index.";
	}
	item_t * temp = this->head;
	int position = 0;
	while (position < index)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
			++position;
		}
		else
		{
			throw "Given index beyond the end of the list";
		}
	}
	// Ok, now we should be wound forward to the one we want.
	return temp;
}
*/


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
	return 0;
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
/*
void DLL_InsertAfter(linked_list_t list, int source, int searchTerm)
{
	list_t * this = (list_t *)list; 
	item_t * posReference = this->FindData(searchTerm, 1); // Magic 1 is true
	item_t * newItem = NewItem_t(posReference, posReference->next, source);
	this->wedgeNode(newItem);
}
*/

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
/*
void DLL_InsertBefore(linked_list_t list, int source, int searchTerm)
{
	list_t * this = (list_t *)list; 
	item_t * posReference = this->FindData(searchTerm);
	item_t * newItem = NewItem_t(posReference->prev, posReference, source);
	this->wedgeNode(newItem);
}
*/

/*********************************************************************
* Purpose: Insert a copy of source after the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
/*
void DLL_InsertAfterIndex(linked_list_t list, int source, int index)
{
	list_t * this = (list_t *)list; 
	item_t * newItem = NULL;

	if (this->head == NULL && this->tail == NULL && -1 == index)
	{
		newItem = NewItem_t(NULL, NULL, source);
	}
	else
	{
		item_t * currentIndex = this->GetIndex(index);
		newItem = NewItem_t(currentIndex, currentIndex->next, source);
	}

	this->wedgeNode(newItem);
}
*/

/*********************************************************************
* Purpose: Insert a copy of source before the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
/*
void DLL_InsertBeforeIndex(linked_list_t list, int source, int index)
{
	list_t * this = (list_t *)list; 
	item_t * newItem = NULL;

	if (this->head == NULL && this->tail == NULL && 0 == index)
	{
		newItem = NewItem_t(NULL, NULL, source);
	}
	else
	{
		item_t * currentIndex = this->GetIndex(index);
		newItem = NewItem_t(currentIndex->prev, currentIndex, source);
	}
	
	this->wedgeNode(newItem);
}
*/


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
	this->count++;
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
	this->count++;
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
		/* Data structure consistent again */
		free(toRemove);
		this->count--;
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
		/* Data structure consistent again */
		free(toRemove);
		return 0;
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the front of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
int DLL_First(linked_list_t list, )
{
	list_t * this = (list_t *)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return head->data;
	}
}
*/

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
int DLL_Last(linked_list_t list, )
{
	list_t * this = (list_t *)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return this->tail->data;
	}
}
*/

/*********************************************************************
* Purpose: Return a reference to the element at the front of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
T & DLL_First(linked_list_t list, )
{
	list_t * this = (list_t *)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return this->head->data;
	}
}
*/

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
T & DLL_Last(linked_list_t list, )
{
	list_t * this = (list_t *)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return this->tail->data;
	}
}
*/

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
T & DLL_GetIthElement(linked_list_t list, int index)
{
	list_t * this = (list_t *)list; 
	return this->GetIndex(index)->data;
}
*/

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
int DLL_GetIthElement(linked_list_t list, int index)
{
	list_t * this = (list_t *)list; 
	return this->GetIndex(index)->data;
}
*/

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
T & DoubleLinkedList<T>::operator[](int index)
{
	return GetIthElement(index);
}
*/

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
/*
int DoubleLinkedList<T>::operator[](int index)
{
	return GetIthElement(index);
}
*/


/*********************************************************************
* Purpose: Remove, and return, an element at index. Thows an exception if out of range.
* Entry: At least index+1 items in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
/*
T DLL_ExtractIndex(linked_list_t list, int index)
{
	list_t * this = (list_t *)list; 
	item_t * toRemove = this->GetIndex(index);
	T returnVal = toRemove->data;
	this->RemoveNode(toRemove);
	delete toRemove;
	return returnVal;
}
*/

/*********************************************************************
* Purpose: Remove, and return, an element by searching by value. Thows an exception if that value is not found.
* Entry: At least one item matching searchTerm in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
/*
T DLL_Extract(linked_list_t list, int searchTerm)
{
	list_t * this = (list_t *)list; 
	item_t * temp = this->FindData(searchTerm);
	T returnVal = temp->data;
	this->RemoveNode(temp);
	delete temp;
	return returnVal;
}
*/

/*********************************************************************
* Purpose: return the number of items in the list.
*********************************************************************/
/*
int DLL_SizeCount(linked_list_t list)
{
	list_t * this = (list_t *)list; 
	int size = 0;
	item_t * currentPlace = this->head;
	while (currentPlace != NULL)
	{
		++size;
		currentPlace = currentPlace->next;
	}

	return size;
}
*/