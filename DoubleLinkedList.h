/*********************************************************************
* Author: Erik Andersen
* Created: Spring 2014
* Last Modified: 2014-01-07
*  Many additions and Removals, (Note to self, see BZR revision control.)
*  including Extract, InsertAfter, InsertBefore, First, Last, InsertBeforeIndex,
*  InsertAfterIndex, ExtractIndex, wedgeNode, RemoveNode, isEmpty, FindData,
*  getTail, getHead, PrintBackwards, PrintForwards (and others).
* Overview:
*  Implements a doubly linked list with a separate, friendly Node class.
*
* Class: DoubleLinkedList
*
* Constructors:
*  DoubleLinkedList()
*   Create an empty linked list.
*  DoubleLinkedList(const DoubleLinkedList & source)
*   Create a copy of source, including all the data elements.
*
* Operators:
*  const DoubleLinkedList & operator= (const DoubleLinkedList & rhs)
*   Set this object equal to rhs, making a full copy of all data elements.
*  T & operator= (const Node & rhs)
*   Return a reference to the Ith element in the list starting from the front.
*   Remember, this reference is invalid if that location of the list is popped,
*   removed, or set to something else.
*  T & operator[](int index)
*   Return a reference to the item at index
*  const T & operator[](int index) const
*   Return a const reference to the item at index
*
* Mutators:
*  void InsertAfterIndex(const T & source, int index)
*   Insert a copy of source after the item at index. 
*  void InsertBeforeIndex(const T & source, int index)
*   Insert a copy of source before the item at index. 
*  void InsertAfter(const T & source, const T & searchTerm)
*   Insert a copy of source before the first occurence of an item matching searchTerm.
*  void InsertBefore(const T & source, const T & searchTerm)
*   Insert a copy of source before the first occurence of an item matching searchTerm.
*  T Extract(const T & searchTerm)
*   Remove, and return, an element by searching by value. Thows an exception if that value is not found.
*  void wedgeNode(Node<T> * newItem)
*   Take a node object that has its pointers set properly to be
*   between nodes (including at the end of the list), and update the 
*   "nodes" (including m_head or m_tail if needed) on either side so it
*   is between them.
*  void RemoveNode(Node<T> * toRemove)
*   Remove a node (with still valid next and previous pointers
*   for its position in the list) and remove it from the list. Does NOT
*   delete the object pointed to by toRemove.
*  void Prepend(const T& source)
*   Add a new element at the front of the list that is a copy of source.
*  void Append(const T& source)
*   Add a new element at the back of the list that is a copy of source.
*  T PopFront()
*   Remove, and return, a copy of the element at the front of the list.
*  T PopBack()
*   Remove, and return, a copy of the element at the back of the list.
*  void Purge()
*   Remove all elements of the list, leaving an empty list.
*  T & GetIthElement(int index)
*   Return a reference to the Ith element in the list starting from the front.
*   Remember, this reference is invalid if that location of the list is popped,
*   removed, or set to something else.
*  T ExtractIndex(int index)
*   Remove, and return, an element at index. Thows an exception if out of range.
*
* Methods:
*  const T & GetIthElement(int index) const
*   Return a reference to the Ith element in the list starting from the front. 
*  bool isEmpty() const
*   Determine if list is empty or not. If so, return true. 
*  Node<T> * GetIndex(int index) const
*   Return a pointer to the Ith element 
*  Node<T> * FindData(const T & searchTerm, bool backward=false) const
*   Return a pointer to the first or last item matching searchTerm. 
*  const T & First() const
*   Return a reference to the element at the front of the list. Remember,
*   this reference is invalid if that location of the list is popped, removed,
*   or set to something else.
*  const T & Last() const
*   Return a reference to the element at the back of the list. Remember,
*   this reference is invalid if that location of the list is popped, removed,
*   or set to something else.
*  bool isEmpty() const
*   return true if the list is empty, otherwise false.
*  int Size() const
*   return the number of items in the list.
********************************************************************/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <stdexcept>
#include <iostream>
using std::cout;

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T> & source);
	const DoubleLinkedList<T> & operator= (const DoubleLinkedList<T> & rhs);
	~DoubleLinkedList();

	void Prepend(const T & source);
	void Append(const T & source);
	T PopFront();
	T PopBack();
	const T & First() const;
	const T & Last() const;
	T & First();
	T & Last();
	void Purge();
	T & GetIthElement(int index);
	T & operator[](int index);
	const T & GetIthElement(int index) const;
	const T & operator[](int index) const;
	bool isEmpty() const;
	int Size() const;
	void InsertAfterIndex(const T & source, int index);
	void InsertBeforeIndex(const T & source, int index);
	T ExtractIndex(int index);
	void InsertAfter(const T & source, const T & searchTerm);
	void InsertBefore(const T & source, const T & searchTerm);
	T Extract(const T & searchTerm);
private:
	Node<T> * m_head;
	Node<T> * m_tail;
	Node<T> * GetIndex(int index) const;
	void wedgeNode(Node<T> * newItem);
	void RemoveNode(Node<T> * toRemove);
	Node<T> * FindData(const T & searchTerm, bool backward=false) const;
};

/*********************************************************************
* Purpose: Remove a node (with still valid next and previous pointers
*  for its position in the list) and remove it from the list. Does NOT
*  delete the object pointed to by toRemove.
* Entry: Node pointed to by toRemove has the next and previous pointers
*  pointed at two adjacent "nodes" (including the head/tail pointers,
*  where appropriate) in the list.
*********************************************************************/
template<typename T>
void DoubleLinkedList<T>::RemoveNode(Node<T> * toRemove)
{
	if (toRemove->GetPrevP() == nullptr)
	{
		m_head = toRemove->GetNextP();
	}
	else
	{
		toRemove->GetPrevP()->SetNextP(toRemove->GetNextP());
	}
	if (toRemove->GetNextP() == nullptr)
	{
		m_tail = toRemove->GetPrevP();
	}
	else
	{
		toRemove->GetNextP()->SetPrevP(toRemove->GetPrevP());
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
template<typename T>
void DoubleLinkedList<T>::wedgeNode(Node<T> * newItem)
{
	// if true, @ end of list, update tail pointer
	if (newItem->GetNextP() == nullptr) 
	{
		m_tail = newItem;
	}
	else
	{
		newItem->GetNextP()->SetPrevP(newItem);
	}
	// if true, @ start of list, update head pointer
	if (newItem->GetPrevP() == nullptr)
	{
		m_head = newItem;
	}
	else
	{
		newItem->GetPrevP()->SetNextP(newItem);
	}
}

/*********************************************************************
* Purpose: Remove all elements of the list, leaving an empty list.
* Exit: List empty, no dynamically allocated memory left.
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::Purge()
{
	Node<T> * tempHead = m_head;
	m_head = nullptr;
	m_tail = nullptr;

	while (tempHead != nullptr)
	{
		Node<T> * next = tempHead->GetNextP();
		delete tempHead;
		tempHead = next;
	}
}

/*********************************************************************
* Purpose: Determine if list is empty or not. If so, return true.
********************************************************************/
template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (m_head == nullptr || m_tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
* Purpose: Return a pointer to the first or last item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
* Exit: List unchanged (but possible to change because there is now a pointer to data in it.)
********************************************************************/
template<typename T>
Node<T> * DoubleLinkedList<T>::FindData(const T & searchTerm, bool backward) const
{
	Node<T> * temp = nullptr;
	if (backward)
	{
		temp = m_tail;
		// Using short-circuit logic here to avoid nullptr dereference
		while (temp != nullptr && temp->GetData() != searchTerm)
		{
			temp = temp->GetPrevP();
		}
	}
	else
	{
		temp = m_head;
		while (temp != nullptr && temp->GetData() != searchTerm)
		{
			temp = temp->GetNextP();
		}
	}
	if (nullptr == temp)
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
template<typename T>
Node<T> * DoubleLinkedList<T>::GetIndex(int index) const
{
	if (m_head == nullptr || m_tail == nullptr)
	{
		throw "Empty list.";
	}
	if (index < 0)
	{
		throw "Negative index.";
	}
	Node<T> * temp = m_head;
	int position = 0;
	while (position < index)
	{
		if (temp->GetNextP() != nullptr)
		{
			temp = temp->GetNextP();
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
* Purpose: Create an empty linked list.
* Exit: This object an empty list in a valid state.
********************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr)
{

}

/*********************************************************************
* Purpose: Create a copy of source, including all the data elements.
* Entry: source in a valid state.
* Exit: This object created as a copy of source.
********************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList & source) : m_head(nullptr), m_tail(nullptr)
{
	*this = source;
}

/*********************************************************************
* Purpose: Set this object equal to rhs, making a full copy of all data elements.
* Entry: rhs a valid DoubleLinkedList object.
* Exit: This set to be a copy of rhs, old data deleted.
********************************************************************/
template<typename T>
const DoubleLinkedList<T> & DoubleLinkedList<T>::operator= (const DoubleLinkedList & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_head == nullptr || rhs.m_tail == nullptr)
		{
			// empty list -- do nothing, Purge just made this equal
		}
		else
		{
			m_head = new Node<T>(*(rhs.m_head));
			Node<T> * holder = m_head;
			while (holder->GetNextP() != nullptr)
			{
				holder->SetNextP(new Node<T>(*(holder->GetNextP())));
				holder->GetNextP()->SetPrevP(holder);
				holder = holder->GetNextP();
			}
			m_tail = holder;
		}
	}

	return *this;
}

/*********************************************************************
* Purpose: Clean up any memory dynamically allocated by this object.
* Exit: No dynamically allocated memory reserved by this object.
********************************************************************/
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertAfter(const T & source, const T & searchTerm)
{
	Node<T> * posReference = this->FindData(searchTerm, true);
	Node<T> * newItem = new Node<T>(posReference, posReference->GetNextP(), source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source before the first occurence of an item matching searchTerm.
* Entry: At least one item matching searchTerm in the list.
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertBefore(const T & source, const T & searchTerm)
{
	Node<T> * posReference = this->FindData(searchTerm);
	Node<T> * newItem = new Node<T>(posReference->GetPrevP(), posReference, source);
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source after the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertAfterIndex(const T & source, int index)
{
	Node<T> * newItem = nullptr;

	if (m_head == nullptr && m_tail == nullptr && -1 == index)
	{
		newItem = new Node<T>(nullptr, nullptr, source);
	}
	else
	{
		Node<T> * currentIndex = this->GetIndex(index);
		newItem = new Node<T>(currentIndex, currentIndex->GetNextP(), source);
	}

	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Insert a copy of source before the item at index.
* Entry: Length of the list must be at least index+1 items
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertBeforeIndex(const T & source, int index)
{
	Node<T> * newItem = nullptr;

	if (m_head == nullptr && m_tail == nullptr && 0 == index)
	{
		newItem = new Node<T>(nullptr, nullptr, source);
	}
	else
	{
		Node<T> * currentIndex = this->GetIndex(index);
		newItem = new Node<T>(currentIndex->GetPrevP(), currentIndex, source);
	}
	
	this->wedgeNode(newItem);
}

/*********************************************************************
* Purpose: Add a new element at the start of the list that is a copy of source.
* Exit: New item inserted at the start of the list, and old items back pointer updated.
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::Prepend(const T & source)
{
	Node<T> * newNode = new Node<T>((Node<T> *)nullptr, m_head, source);
	/* Data structure inconsistent after this */
	if (newNode->GetNextP() == nullptr)
	{
		m_tail = newNode;
	}
	else
	{
		newNode->GetNextP()->SetPrevP(newNode);
	}
	m_head = newNode;
	/* Data structure consistent again */
}

/*********************************************************************
* Purpose: Add a new element at the end of the list that is a copy of source.
* Exit: New item inserted at the end of the list, old last items forward pointer updated.
********************************************************************/
template<typename T>
void DoubleLinkedList<T>::Append(const T & source)
{
	Node<T> * newNode = new Node<T>(m_tail, (Node<T> *)nullptr, source);
	/* Data structure inconsistent after this */
	if (newNode->GetPrevP() == nullptr)
	{
		m_head = newNode;
	}
	else
	{
		newNode->GetPrevP()->SetNextP(newNode);
	}
	m_tail = newNode;
	/* Data structure consistent again */
}

/*********************************************************************
* Purpose: Remove, and return, a copy of the element at the front of the list.
* Entry: At least one item in the list.
* Exit: First item removed from the list.
********************************************************************/
template<typename T>
T DoubleLinkedList<T>::PopFront()
{
	if (m_head == nullptr || m_tail == nullptr)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		Node<T> * toRemove = m_head;
		T temp = toRemove->GetData();
		// Go to the next node, the one that will be the in front when we are done
		Node<T> * nextFront = toRemove->GetNextP();
		/* Data structure inconsistent after this */

		// If next front is null, then we just took out the last item in the list
		if (nextFront == nullptr)
		{
			m_tail = nullptr;
		}
		else
		{
			// If its not null, then there is still at least one thing, and we need to update it's 
			// previous pointer to stop pointing at the old object and set it to nullptr to say it's
			// at the start of the list
			nextFront->SetPrevP(nullptr);
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
template<typename T>
T DoubleLinkedList<T>::PopBack()
{
	if (m_head == nullptr || m_tail == nullptr)
	{
		throw "0 items in list, can't return front";
	}
	else
	{
		// I don't want to copy stuff 15 times here. Suggestions to minimize this would be appreciated
		Node<T> * toRemove = m_tail;
		T temp = toRemove->GetData();
		// Go to the next node, the one that will be the in front when we are done
		Node<T> * nextBack = toRemove->GetPrevP();
		/* Data structure inconsistent after this */
		// If next front is null, then we just took out the last item in the list
		if (nextBack == nullptr)
		{
			m_head = nullptr;
		}
		else
		{
			// If its not null, then there is still at least one thing, and we need to update it's 
			// previous pointer to stop pointing at the old object and set it to nullptr to say it's
			// at the start of the list
			nextBack->SetNextP(nullptr);
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
template<typename T>
const T & DoubleLinkedList<T>::First() const
{
	if (m_head == nullptr || m_tail == nullptr)
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
template<typename T>
const T & DoubleLinkedList<T>::Last() const
{
	if (m_head == nullptr || m_tail == nullptr)
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
template<typename T>
T & DoubleLinkedList<T>::First()
{
	if (m_head == nullptr || m_tail == nullptr)
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
template<typename T>
T & DoubleLinkedList<T>::Last()
{
	if (m_head == nullptr || m_tail == nullptr)
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
template<typename T>
T & DoubleLinkedList<T>::GetIthElement(int index)
{
	return this->GetIndex(index)->GetData();
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
template<typename T>
const T & DoubleLinkedList<T>::GetIthElement(int index) const
{
	return this->GetIndex(index)->GetData();
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
template<typename T>
T & DoubleLinkedList<T>::operator[](int index)
{
	return GetIthElement(index);
}

/*********************************************************************
* Purpose: Return a reference to the Ith element in the list starting from the front.
* Entry: At least index+1 items in the list.
* Exit: List unchanged (but possible to change because there is now a reference to data in it.)
********************************************************************/
template<typename T>
const T & DoubleLinkedList<T>::operator[](int index) const
{
	return GetIthElement(index);
}


/*********************************************************************
* Purpose: Remove, and return, an element at index. Thows an exception if out of range.
* Entry: At least index+1 items in the list.
* Exit: Item removed from list, with item(s) previously on either side linked to each other
********************************************************************/
template<typename T>
T DoubleLinkedList<T>::ExtractIndex(int index)
{
	Node<T> * toRemove = this->GetIndex(index);
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
template<typename T>
T DoubleLinkedList<T>::Extract(const T & searchTerm)
{
	Node<T> * temp = this->FindData(searchTerm);
	T returnVal = temp->GetData();
	this->RemoveNode(temp);
	delete temp;
	return returnVal;
}

/*********************************************************************
* Purpose: return the number of items in the list.
*********************************************************************/
template <typename T>
int DoubleLinkedList<T>::Size() const
{
	int size = 0;
	Node<T> * currentPlace = m_head;
	while (currentPlace != nullptr)
	{
		++size;
		currentPlace = currentPlace->GetNextP();
	}

	return size;
}


#endif
