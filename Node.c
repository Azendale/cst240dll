#pragma once
/*********************************************************************
* Author: Erik Andersen
* Created: Spring 2014
* Last Modified: 2014-01-07
*  Change many things to private. Remove stuff for counting number of node instances.
* 
* Overview:
*  Implements a Node class to be used by the doubly linked list class.
* 
* Class: Node
*
* Constructors:
*  Node(Node * prevP, Node * nextP, const T & toAdd)
*   Creates a new node, with the m_prevP and m_nextP set to prevP & nextP respectively,
*   and the m_data member set to a copy of the toAdd object
*  Node(const Node & source)
*   Creates a copy of source, including the "forward" and "back" pointers.
*
* Operators:
* const Node & operator= (const Node & rhs)
*  Sets this object equal to rhs. This will free the current data member. Shallow copies the
*  m_prevP and m_nextP pointers.
*
* Mutators:
*  T & GetData()
*   Returns a reference to the current data member
*  void SetNextP(Node * nextP)
*   Sets the next node that this object points to.
*  void SetPrevP(Node * prevP)
*   Sets the previous node that this object points to.
*  void SetData(const T & data)
*   Sets the current data member to data.
*
* Methods:
*  Node * GetNextP() const
*   Returns a pointer to the next object this points to.
*  Node * GetPrevP() const
*   Returns a poniter to the previous object this points to.
*********************************************************************/

template<typename T>
class Node
{
	template<typename U> friend class DoubleLinkedList;
public:
	~Node();
private:
	Node<T> * GetNextP() const;
	Node<T> * GetPrevP() const;
	T & GetData();
	void SetNextP(Node<T> * nextP);
	void SetPrevP(Node<T> * prevP);
	void SetData(const T & data);
	const Node & operator= (const Node<T> & rhs);
	Node(Node<T> * prevP, Node<T> * nextP, const T & toAdd);
	Node(const Node & source);
	Node<T> * m_nextP;
	Node<T> * m_prevP;
	T m_data;
};


/*********************************************************************
* Purpose:  Returns a pointer to the next object this points to.
* Exit: Return a copy of the Forward/Next pointer.
********************************************************************/
template<typename T>
Node<T> * Node<T>::GetNextP() const
{
	return m_nextP;
}

/*********************************************************************
* Purpose: Returns a pointer to the previous object this points to.
* Exit: Return a copy of the Back/Prev pointer.
********************************************************************/
template<typename T>
Node<T> * Node<T>::GetPrevP() const
{
	return m_prevP;
}

/*********************************************************************
* Purpose: Returns a reference to the current data member
* Exit: List unchanged, but data in it can now be changed as a reference is returned.
********************************************************************/
template<typename T>
T & Node<T>::GetData()
{
	return m_data;
}

/*********************************************************************
* Purpose: Sets the next node that this object points to.
* Entry: None.
* Exit: Next/Forward pointer set to nextP
********************************************************************/
template<typename T>
void Node<T>::SetNextP(Node<T> * nextP)
{
	m_nextP = nextP;
}

/*********************************************************************
* Purpose: Sets the previous node that this object points to.
* Entry: None
* Exit: Back/Prev pointer set to prevP
********************************************************************/
template<typename T>
void Node<T>::SetPrevP(Node<T> * prevP)
{
	m_prevP = prevP;
}

/*********************************************************************
* Purpose: Sets the current data member to data.
* Entry: source a valid T reference.
* Exit: Previous data replaced with a copy of source.
********************************************************************/
template<typename T>
void Node<T>::SetData(const T & source)
{
	m_data = source;
}

/*********************************************************************
* Purpose: Creates a new node, with the m_prevP and m_nextP set to prevP & nextP respectively,
*   and the m_data member set to a copy of the toAdd object
* Entry: data a valid reference to a T object.
* Exit: This object a new node with a copy of data stored in it.
********************************************************************/
template<typename T>
Node<T>::Node(Node<T> * prevP, Node<T> * nextP, const T & data) : m_nextP(nextP), m_prevP(prevP), m_data(data)
{
}

/*********************************************************************
* Purpose: Sets this object equal to rhs. This will free the current data member. Shallow copies the
*  m_prevP and m_nextP pointers.
* Entry: rhs a valid node object reference.
* Exit: This object made eqaul to rhs.
********************************************************************/
template<typename T>
const Node<T> & Node<T>::operator= (const Node<T> & rhs)
{
	m_nextP = rhs.m_nextP;
	m_prevP = rhs.m_prevP;
	m_data = rhs.m_data;

	return *this;
}

/*********************************************************************
* Purpose: Free any memory dynamically allocated by this class.
* Exit: No dynamically allocated memory still reserved.
********************************************************************/
template<typename T>
Node<T>::~Node()
{
	// No need to delete m_data as that will happen automatically
	m_nextP = nullptr;
	m_prevP = nullptr;
}

/*********************************************************************
* Purpose: Creates a copy of source, including the "forward" and "back" pointers.
* Entry: source a valid reference to a node object
* Exit: This a new object equal to source.
********************************************************************/
template<typename T>
Node<T>::Node(const Node<T> & source) : m_nextP(source.m_nextP), m_prevP(source.m_prevP), m_data(source.m_data)
{
}