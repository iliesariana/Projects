#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator( SortedSet& m) : multime(m)
{
	this->currentNode=multime.head;
}

//bc=wc=tc=theta(1)
void SortedSetIterator::first() {
	//TODO - Implementation
    this->currentNode=multime.head;
}

//bc=wc=tc=theta(1)
void SortedSetIterator::next() {
	//TODO - Implementation
    if(!this->valid())
        throw exception();
    this->currentNode=this->currentNode->next;
}

//bc=wc=tc=theta(1)
TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
    if (this->valid()==false)
        throw exception();
    return this->currentNode->value;

}
//bc=wc=tc=theta(1)
bool SortedSetIterator::valid() const {
	if(this->currentNode != nullptr)
        return true;
	return false;
}
//bc=theta(1)  wc=theta(n) tc=o(n)
TElem SortedSetIterator::remove() {
    if(!this->valid())
        throw exception();
    TElem current=this->getCurrent();
    this->next();
    this->multime.remove(current);
    return current;
}
