#include "QueueOfStrings.hpp"



QueueOfStrings::QueueOfStrings()
{
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


