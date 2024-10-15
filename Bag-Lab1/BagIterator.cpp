#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->position=0;
    this->occurrences=this->bag.frequencies[this->position];
}
//BC=WC=TC=theta(1)
void BagIterator::first() {
	//TODO - Implementation
    this->position = 0;
    this->occurrences = this->bag.frequencies[this->position];
}
//BC=theta(1)
//wc=theta(n)
//tc=o(n)

void BagIterator::next() {
	//TODO - Implementation
    if(!this->valid())
    {
        this->position=-1;
        throw exception();
    }
    if(this->occurrences > 1)
    {
        this->occurrences--;
        return ;
    }
    do
    {
        this->position++;
    }while(this->position<this->bag.capacity &&this->bag.frequencies[this->position]==0);

    if (this->position < this->bag.capacity) {
        this->occurrences = this->bag.frequencies[this->position];
    } else {
        this->position = -1;
    }


}

//BC=WC=TC=theta(1)
bool BagIterator::valid() const {
	//TODO - Implementation
    return this->bag.length!=0 && this->position!=-1 && this->position<this->bag.capacity;
	//return false;
}


//BC=WC=TC=theta(1)
TElem BagIterator::getCurrent() const
{
	if(!this->valid())
        throw exception();
	return this->position+this->bag.minimum;
}
