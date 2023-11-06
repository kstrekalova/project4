#include "QueueOfStrings.hpp"

QueueOfStrings::QueueOfStrings()
{
		
	// 2 examples
	/*
	class MyLibrary {
public :
	MyLibrary();
private :
size_t m_numBooks;		// MAX_BOOKS no longer exists
Book ** m_shelves;		<< ** = pointer to array of pointers
constexpr static size_t INITIAL_SHELF_SIZE = 5;
size_t capacity;
}
MyLibrary::MyLibrary()
	: m_numBooks{0}, m_shelves( new Book*[INTIAL_SHELF_SIZE] ),  
	<< array of pointers m_capacity(INITIAL_SHELF_SIZE) )
	*/
	/*
	class LinkedList{ 	// mini class within LinkedList
		public: 
		{
		int sum() const noexcept;
		bool contains(int x) const noexcept;
		}
		private:
		{
			struct Node {
			Node(int v)
			: value{v}, next{nullptr}	// not the best way to do this
			{}
			int value;
			Node* next;
			};
			Node * front; 		//LL constructor sets to null pointer
			Node * back;		// what changes if we did this?
		}
}

	*/
}

// Be sure to do a "deep copy" -- if I 
// make a copy and modify one, it should not affect the other. 
QueueOfStrings::QueueOfStrings(const QueueOfStrings & st)
{

}

QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	return *this;
}

QueueOfStrings::~QueueOfStrings() 
{
}


size_t QueueOfStrings::size() const noexcept
{
	return 15; // stub, probably not the right answer.
}


bool QueueOfStrings::isEmpty() const noexcept
{
	return false; // stub, probably not the right answer.
}

void QueueOfStrings::enqueue(const std::string & elem)
{

}


std::string & QueueOfStrings::front()
{
	throw QueueEmptyException{"Queue is Empty"};
}

const std::string & QueueOfStrings::front() const
{
	throw QueueEmptyException{"Queue is Empty"};
}


// does not return anything.  Just removes. 
void QueueOfStrings::dequeue()
{
}


