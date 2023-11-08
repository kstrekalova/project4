#include "QueueOfStrings.hpp"

QueueOfStrings::QueueOfStrings()
{
	beginning = nullptr;
}

// Be sure to do a "deep copy" -- if I 
// make a copy and modify one, it should not affect the other. 
QueueOfStrings::QueueOfStrings(const QueueOfStrings & st)
{
	Node * temp{ st.beginning };
	Node * prevNode { st.beginning} ;	
	// Throw QueueEmptyException if queueOfStrings is empty	// If problematic, delete
	if ( temp == nullptr )
	{
		throw QueueEmptyException("queueOfStrings is empty");
	}
	
	// Copy 1st node & save this queue's beginning as 1st node
	Node * newNode = new Node( temp->value );
	beginning = newNode;
	prevNode = newNode;
	temp = temp -> next;

	// while value of temp->next is not a nullptr 
	// as a result, values of all nodes of st are copied to newNode
	while ( temp != nullptr )
	{
		newNode = new Node( temp -> value );
		prevNode -> next = newNode;
		temp = temp -> next;
	}
}

/* Also creates a deep copy, but..... it's fine I don't care
*/
QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	Node * temp{ st.beginning };
	Node * prevNode { st.beginning} ;	
	// Throw QueueEmptyException if queueOfStrings is empty	// If problematic, delete
	if ( temp == nullptr )
	{
		throw QueueEmptyException("queueOfStrings is empty");
	}
	
	// Copy 1st node & save this queue's beginning as 1st node
	Node * newNode = new Node( temp->value );
	beginning = newNode;
	prevNode = newNode;
	temp = temp -> next;

	// while value of temp->next is not a nullptr 
	// as a result, values of all nodes of st are copied to newNode
	while ( temp != nullptr )
	{
		newNode = new Node( temp -> value );
		prevNode -> next = newNode;
		temp = temp -> next;
	}
	return *this;
}

QueueOfStrings::~QueueOfStrings() 
{
	// loooooop through every node & until you hit a nullptr, delete every node
	Node * temp{ beginning };
	Node * ptrToNext;
	while ( temp != nullptr ) 
	{
		ptrToNext = temp -> next;
		delete temp;
		temp = ptrToNext;
	}
}


size_t QueueOfStrings::size() const noexcept
{
	// loop through every node & until you hit a nullptr, increment size
	Node * temp{ beginning };
	size_t size{0};
	while ( temp != nullptr ) 
	{
		temp = temp -> next;
		size++;
	}
	return size; 
}


bool QueueOfStrings::isEmpty() const noexcept
{
	if ( beginning == nullptr ) { return true; }
	else { return false; } 
}

void QueueOfStrings::enqueue(const std::string & elem)
{
	// create new node
	Node * newNode = new Node{ elem };
	// if queue is empty, need to set beginning to newNode
	if ( beginning == nullptr )
	{
		beginning = newNode;
	}
	else 
	{
		// find last node, set its next to newNode
		Node * temp{ beginning };
		while ( temp != nullptr )
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}

// both versions of front(), as well as dequeue(), throw a QueueEmptyException if called when empty.
std::string & QueueOfStrings::front()
{
	if ( beginning == nullptr )
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	else 
	{
		return beginning -> value;
	}
}

const std::string & QueueOfStrings::front() const
{
	if ( beginning == nullptr )
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	else 
	{
		return beginning -> value;
	}
}

// does not return anything.  Just removes. 
void QueueOfStrings::dequeue()
{
	// find last node, set its next to newNode
	Node * temp{ beginning };
	while ( temp -> next != nullptr )
	{
		temp = temp -> next;
	}
	delete temp;
}


