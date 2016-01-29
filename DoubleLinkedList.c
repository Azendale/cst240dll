#pragma once
#include "DoubleLinkedList.h"

#include "stdlib.h"
#include "stdio.h"

typdef struct item_s
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



int Count(linked_list_t)
{
	return (list_t *)->count;
}

// Create and initialize a list. 
// Return pointer to list. Return NULL on failure.
linked_list_t* Init_List()
{
	list_t * this = (list_t *)malloc(sizeof(list_t));
	this->head = NULL;
	this->tail = NULL;
	count = 0;
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
int DLL_RemoveNode(linked_list_t list, linked_list_t list, item_t * toRemove)
{
	list_t * this = (*list_t)list; 
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


/*********************************************************************
* Purpose: Take a node object that has its pointers set properly to be
*  between nodes (including at the end of the list), and update the 
*  "nodes" (including head or tail if needed) on either side so it
*   is between them.
*  Entry: Node pointed to by newItem has the next and previous pointers
*  pointed at two adjacent nodes in the list.
*********************************************************************/
void DLL_wedgeNode(linked_list_t list, linked_list_t list, item_t * newItem)
{
	list_t * this = (*list_t)list; 
	// if true, @ end of list, update this->tail pointer
	if (newItem->next == NULL) 
	{
		this->tail = newItem;
	}
	else
	{
		newItem->next->prev = newItem);
	}
	// if true, @ start of list, update head pointer
	if (newItem->prev == NULL)
	{
		this->head = newItem;
	}
	else
	{
		newItem->prev->next = newItem);
	}
}

/*********************************************************************
* Purpose: Remove all elements of the list, leaving an empty list.
* Exit: List empty, no dynamically allocated memory left.
********************************************************************/
void DLL_Purge(linked_list_t list)
{
	list_t * this = (*list_t)list; 
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

// Return true (non-zero) if the list is empty
//    list: list to examine
int Empty(linked_list_t list);
{
	list_t * this = (*list_t)list; 
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
item_t * DLL_FindData(linked_list_t list, int searchTerm, int backward)
{
	list_t * this = (*list_t)list; 
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
	if (NULL == temp)
	{
		throw "Did not find data that matches the search.";
	}
	return temp;
}

/*********************************************************************
* Purpose: Return a pointer to the Ith element
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a pointer to data in it.)
********************************************************************/
item_t * DLL_GetIndex(linked_list_t list, int index)
{
	list_t * this = (*list_t)list; 
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


/*********************************************************************
* Purpose: Create a copy of source, including all the data elements.
* Entry: source in a valid state.
* Exit: This object created as a copy of source.
********************************************************************/
DLL_DoubleLinkedList(linked_list_t list, const DoubleLinkedList & source) : head(NULL), tail(NULL)
{
	*this = source;
}

/*********************************************************************
* Purpose: Set this object equal to rhs, making a full copy of all data elements.
* Entry: rhs a valid DoubleLinkedList object.
* Exit: This set to be a copy of rhs, old data deleted.
********************************************************************/
const DoubleLinkedList<T> & DoubleLinkedList<T>::operator= (const DoubleLinkedList & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.head == NULL || rhs.tail == NULL)
		{
			// empty list -- do nothing, Purge just made this equal
		}
		else
		{
			head = new item_t(*(rhs.head));
			item_t * holder = head;
			while (holder->next != NULL)
			{
				holder->next = new item_t(*(holder->next)));
				holder->next->prev = holder);
				holder = holder->next;
			}
			this->tail = holder;
		}
	}

	return *this;
}

// Delete a list are free all memory used by the list
// It is erroneous to use the list pointer after caling this routine.
// Return zero on success
int Delete_List(linked_list_t list)
{
	list_t * this = (*list_t)list; 
	item_t * tempHead = this->head;
	this->head = NULL;
	this->tail = NULL;

	while (tempHead != NULL)
	{
		item_t * next = tempHead->next;
		delete tempHead;
		tempHead = next;
	}
}

/*********************************************************************
* Purpose: Clean up any memory dynamically allocated by this object.
* Exit: No dynamically allocated memory reserved by this object.
********************************************************************/
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
void DLL_InsertAfter(linked_list_t list, int source, int searchTerm)
{
	list_t * this = (*list_t)list; 
	item_t * posReference = this->FindData(searchTerm, true);
	item_t * newItem = new item_t(posReference, posReference->next, source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
void DLL_InsertBefore(linked_list_t list, int source, int searchTerm)
{
	list_t * this = (*list_t)list; 
	item_t * posReference = this->FindData(searchTerm);
	item_t * newItem = new item_t(posReference->prev, posReference, source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source after the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
void DLL_InsertAfterIndex(linked_list_t list, int source, int index)
{
	list_t * this = (*list_t)list; 
	item_t * newItem = NULL;

	if (this->head == NULL && this->tail == NULL && -1 == index)
	{
		newItem = new item_t(NULL, NULL, source);
	}
	else
	{
		item_t * currentIndex = this->GetIndex(index);
		newItem = new item_t(currentIndex, currentIndex->next, source);
	}

	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source before the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
void DLL_InsertBeforeIndex(linked_list_t list, int source, int index)
{
	list_t * this = (*list_t)list; 
	item_t * newItem = NULL;

	if (this->head == NULL && this->tail == NULL && 0 == index)
	{
		newItem = new item_t(NULL, NULL, source);
	}
	else
	{
		item_t * currentIndex = this->GetIndex(index);
		newItem = new item_t(currentIndex->prev, currentIndex, source);
	}
	
	this->wedgeNode(newItem);
}


// Insert an item at the beginning of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_Beginning(linked_list_t list, int data);
/*********************************************************************
* Purpose: Add a new element at the start of the list that is a copy of source.
* Exit: New item inserted at the start of the list, and old items back pointer updated.
********************************************************************/
void DLL_Prepend(linked_list_t list, int source)
{
	list_t * this = (*list_t)list; 
	item_t * newNode = new item_t((item_t *)NULL, this->head, source);
	/* Data structure inconsistent after this */
	if (newNode->next == NULL)
	{
		this->tail = newNode;
	}
	else
	{
		newNode->next->prev = newNode);
	}
	this->head = newNode;
	/* Data structure consistent again */
}


// Insert an item at the end of the list
// Return zero on success
// Params:
//    list: list to add item to
//    data: Data to be added to the list
int Insert_At_End(linked_list_t list, int data);
/*********************************************************************
* Purpose: Add a new element at the end of the list that is a copy of source.
* Exit: New item inserted at the end of the list, old last items forward pointer updated.
********************************************************************/
void DLL_Append(linked_list_t list, int source)
{
	list_t * this = (*list_t)list; 
	item_t * newNode = new item_t(this->tail, (item_t *)NULL, source);
	/* Data structure inconsistent after this */
	if (newNode->prev == NULL)
	{
		this->head = newNode;
	}
	else
	{
		newNode->prev->next = newNode);
	}
	this->tail = newNode;
	/* Data structure consistent again */
}


// Remove an item from the beginning of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_Beginning(linked_list_t list, int* data);
/*********************************************************************
* Purpose: Remove, and return, a copy of the element at the front of the list.
* Entry: At least one item in the list.
* Exit: First item removed from the list.
********************************************************************/
T DLL_PopFront(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		item_t * toRemove = this->head;
		T temp = toRemove->data;
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
			nextFront->prev = NULL);
		}
		this->head = nextFront;
		/* Data structure consistent again */
		delete toRemove;
		return temp;
	}
}


// Remove an item from the end of the list 
// Return zero on success
// Params:
//    list: list to remove item from
//    data: pointer to location to store data of removed item
//          if data is NULL, data is not returned
int Remove_From_End(linked_list_t list, int* data);
/*********************************************************************
* Purpose: Remove, and return, a copy of the element at the back of the list.
* Entry: At least one item in the list.
* Exit: Last item removed from the list.
********************************************************************/
T DLL_PopBack(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		item_t * toRemove = this->tail;
		T temp = toRemove->data;
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
			nextBack->next = NULL);
		}
		this->tail = nextBack;
		/* Data structure consistent again */
		delete toRemove;
		return temp;
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the front of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
int DLL_First(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return head->data;
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
int DLL_Last(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return this->tail->data;
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the front of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & DLL_First(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return this->head->data;
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & DLL_Last(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	if (this->head == NULL || this->tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return this->tail->data;
	}
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & DLL_GetIthElement(linked_list_t list, int index)
{
	list_t * this = (*list_t)list; 
	return this->GetIndex(index)->data;
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
int DLL_GetIthElement(linked_list_t list, int index)
{
	list_t * this = (*list_t)list; 
	return this->GetIndex(index)->data;
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & DoubleLinkedList<T>::operator[](int index)
{
	return GetIthElement(index);
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
int DoubleLinkedList<T>::operator[](int index)
{
	return GetIthElement(index);
}


/*********************************************************************
* Purpose: Remove, and return, an element at index. Thows an exception if out of range.
* Entry: At least index+1 items in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
T DLL_ExtractIndex(linked_list_t list, int index)
{
	list_t * this = (*list_t)list; 
	item_t * toRemove = this->GetIndex(index);
	T returnVal = toRemove->data;
	this->RemoveNode(toRemove);
	delete toRemove;
	return returnVal;
}

/*********************************************************************
* Purpose: Remove, and return, an element by searching by value. Thows an exception if that value is not found.
* Entry: At least one item matching searchTerm in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
T DLL_Extract(linked_list_t list, int searchTerm)
{
	list_t * this = (*list_t)list; 
	item_t * temp = this->FindData(searchTerm);
	T returnVal = temp->data;
	this->RemoveNode(temp);
	delete temp;
	return returnVal;
}

/*********************************************************************
* Purpose: return the number of items in the list.
*********************************************************************/
template <typename T>
int DLL_Size(linked_list_t list, )
{
	list_t * this = (*list_t)list; 
	int size = 0;
	item_t * currentPlace = this->head;
	while (currentPlace != NULL)
	{
		++size;
		currentPlace = currentPlace->next;
	}

	return size;
}
