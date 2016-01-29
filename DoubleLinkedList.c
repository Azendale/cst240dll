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

int Count(linked_list_t);

// Create and initialize a list. 
// Return pointer to list. Return NULL on failure.
linked_list_t* Init_List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}


/*********************************************************************
* Purpose: Remove a node (with still valid next and previous pointers
*  for its position in the list) and remove it from the list. Does NOT
*  delete the object pointed to by toRemove.
* Entry: Node pointed to by toRemove has the next and previous pointers
*  pointed at two adjacent "nodes" (including the head/tail pointers,
*  where appropriate) in the list.
*********************************************************************/
int RemoveNode(linked_list_t list, linked_list_t list, item_t * toRemove)
{
	list_t * this = (*list_t)list; 
	if (toRemove->prev == NULL)
	{
		m_head = toRemove->next;
	}
	else
	{
		toRemove->prev->next = toRemove->next);
	}
	if (toRemove->next == NULL)
	{
		m_tail = toRemove->prev;
	}
	else
	{
		toRemove->next->prev = toRemove->prev);
	}
}


/*********************************************************************
* Purpose: Take a node object that has its pointers set properly to be
*  between nodes (including at the end of the list), and update the 
*  "nodes" (including m_head or m_tail if needed) on either side so it
*   is between them.
*  Entry: Node pointed to by newItem has the next and previous pointers
*  pointed at two adjacent nodes in the list.
*********************************************************************/
void wedgeNode(linked_list_t list, linked_list_t list, item_t * newItem)
{
	list_t * this = (*list_t)list; 
	// if true, @ end of list, update tail pointer
	if (newItem->next == NULL) 
	{
		m_tail = newItem;
	}
	else
	{
		newItem->next->prev = newItem);
	}
	// if true, @ start of list, update head pointer
	if (newItem->prev == NULL)
	{
		m_head = newItem;
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
void Purge(linked_list_t list, linked_list_t list)
{
	list_t * this = (*list_t)list; 
	item_t * tempHead = m_head;
	m_head = NULL;
	m_tail = NULL;

	while (tempHead != NULL)
	{
		item_t * next = tempHead->next;
		delete tempHead;
		tempHead = next;
	}
}

/*********************************************************************
* Purpose: Determine if list is empty or not. If so, return true.
********************************************************************/
int isEmpty(linked_list_t list, linked_list_t l) const
{
	list_t * this = (*list_t)l; 
	if (m_head == NULL || m_tail == NULL)
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
item_t * FindData(linked_list_t list, const T & searchTerm, bool backward) const
{
	item_t * temp = NULL;
	if (backward)
	{
		temp = m_tail;
		// Using short-circuit logic here to avoid NULL dereference
		while (temp != NULL && temp->GetData() != searchTerm)
		{
			temp = temp->prev;
		}
	}
	else
	{
		temp = m_head;
		while (temp != NULL && temp->GetData() != searchTerm)
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
item_t * GetIndex(linked_list_t list, int index) const
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "Empty list.";
	}
	if (index < 0)
	{
		throw "Negative index.";
	}
	item_t * temp = m_head;
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
DoubleLinkedList(linked_list_t list, const DoubleLinkedList & source) : m_head(NULL), m_tail(NULL)
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
		if (rhs.m_head == NULL || rhs.m_tail == NULL)
		{
			// empty list -- do nothing, Purge just made this equal
		}
		else
		{
			m_head = new item_t(*(rhs.m_head));
			item_t * holder = m_head;
			while (holder->next != NULL)
			{
				holder->next = new item_t(*(holder->next)));
				holder->next->prev = holder);
				holder = holder->next;
			}
			m_tail = holder;
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
	this->m_head = NULL;
	this->m_tail = NULL;

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
void InsertAfter(linked_list_t list, const T & source, const T & searchTerm)
{
	item_t * posReference = this->FindData(searchTerm, true);
	item_t * newItem = new item_t(posReference, posReference->next, source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
void InsertBefore(linked_list_t list, const T & source, const T & searchTerm)
{
	item_t * posReference = this->FindData(searchTerm);
	item_t * newItem = new item_t(posReference->prev, posReference, source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source after the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
void InsertAfterIndex(linked_list_t list, const T & source, int index)
{
	item_t * newItem = NULL;

	if (m_head == NULL && m_tail == NULL && -1 == index)
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
void InsertBeforeIndex(linked_list_t list, const T & source, int index)
{
	item_t * newItem = NULL;

	if (m_head == NULL && m_tail == NULL && 0 == index)
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

/*********************************************************************
* Purpose: Add a new element at the start of the list that is a copy of source.
* Exit: New item inserted at the start of the list, and old items back pointer updated.
********************************************************************/
void Prepend(linked_list_t list, const T & source)
{
	item_t * newNode = new item_t((item_t *)NULL, m_head, source);
	/* Data structure inconsistent after this */
	if (newNode->next == NULL)
	{
		m_tail = newNode;
	}
	else
	{
		newNode->next->prev = newNode);
	}
	m_head = newNode;
	/* Data structure consistent again */
}

/*********************************************************************
* Purpose: Add a new element at the end of the list that is a copy of source.
* Exit: New item inserted at the end of the list, old last items forward pointer updated.
********************************************************************/
void Append(linked_list_t list, const T & source)
{
	item_t * newNode = new item_t(m_tail, (item_t *)NULL, source);
	/* Data structure inconsistent after this */
	if (newNode->prev == NULL)
	{
		m_head = newNode;
	}
	else
	{
		newNode->prev->next = newNode);
	}
	m_tail = newNode;
	/* Data structure consistent again */
}

/*********************************************************************
* Purpose: Remove, and return, a copy of the element at the front of the list.
* Entry: At least one item in the list.
* Exit: First item removed from the list.
********************************************************************/
T PopFront(linked_list_t list, )
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		item_t * toRemove = m_head;
		T temp = toRemove->GetData();
		// Go to the next node, the one that will be the in front when we are done
		item_t * nextFront = toRemove->next;
		/* Data structure inconsistent after this */

		// If next front is null, then we just took out the last item in the list
		if (nextFront == NULL)
		{
			m_tail = NULL;
		}
		else
		{
			// If its not null, then there is still at least one thing, and we need to update it's 
			// previous pointer to stop pointing at the old object and set it to NULL to say it's
			// at the start of the list
			nextFront->prev = NULL);
		}
		m_head = nextFront;
		/* Data structure consistent again */
		delete toRemove;
		return temp;
	}
}

/*********************************************************************
* Purpose: Remove, and return, a copy of the element at the back of the list.
* Entry: At least one item in the list.
* Exit: Last item removed from the list.
********************************************************************/
T PopBack(linked_list_t list, )
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		item_t * toRemove = m_tail;
		T temp = toRemove->GetData();
		// Go to the next node, the one that will be the in front when we are done
		item_t * nextBack = toRemove->prev;
		/* Data structure inconsistent after this */
		// If next front is null, then we just took out the last item in the list
		if (nextBack == NULL)
		{
			m_head = NULL;
		}
		else
		{
			// If its not null, then there is still at least one thing, and we need to update it's 
			// previous pointer to stop pointing at the old object and set it to NULL to say it's
			// at the start of the list
			nextBack->next = NULL);
		}
		m_tail = nextBack;
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
const T & First(linked_list_t list, ) const
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return m_head->GetData();
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
const T & Last(linked_list_t list, ) const
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return m_tail->GetData();
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the front of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & First(linked_list_t list, )
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		return m_head->GetData();
	}
}

/*********************************************************************
* Purpose: Return a reference to the element at the back of the list.
* Entry: At least one item in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & Last(linked_list_t list, )
{
	if (m_head == NULL || m_tail == NULL)
	{
		throw "0 items in list, can't return back";
	}
	else
	{
		return m_tail->GetData();
	}
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
T & GetIthElement(linked_list_t list, int index)
{
	return this->GetIndex(index)->GetData();
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
const T & GetIthElement(linked_list_t list, int index) const
{
	return this->GetIndex(index)->GetData();
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
const T & DoubleLinkedList<T>::operator[](int index) const
{
	return GetIthElement(index);
}


/*********************************************************************
* Purpose: Remove, and return, an element at index. Thows an exception if out of range.
* Entry: At least index+1 items in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
T ExtractIndex(linked_list_t list, int index)
{
	item_t * toRemove = this->GetIndex(index);
	T returnVal = toRemove->GetData();
	this->RemoveNode(toRemove);
	delete toRemove;
	return returnVal;
}

/*********************************************************************
* Purpose: Remove, and return, an element by searching by value. Thows an exception if that value is not found.
* Entry: At least one item matching searchTerm in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
T Extract(linked_list_t list, const T & searchTerm)
{
	item_t * temp = this->FindData(searchTerm);
	T returnVal = temp->GetData();
	this->RemoveNode(temp);
	delete temp;
	return returnVal;
}

/*********************************************************************
* Purpose: return the number of items in the list.
*********************************************************************/
template <typename T>
int Size(linked_list_t list, ) const
{
	int size = 0;
	item_t * currentPlace = m_head;
	while (currentPlace != NULL)
	{
		++size;
		currentPlace = currentPlace->next;
	}

	return size;
}
