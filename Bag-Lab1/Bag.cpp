#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {

    this->frequencies=new int[1];
    this->capacity=1;
    this->length=0;
    this->maximum=NULL_TELEM;
    this->minimum=NULL_TELEM;
}
//array-size =max-min+1 at all times -denote it n
//BC theta(1)
//WC theta(n)
//TC O(n)
void Bag::add(TElem elem) {
    int oldMin=this->minimum;
    int oldMax=this->maximum;
    if(Bag::size()==0)
    {
        this->minimum=elem;
        this->maximum=elem;
        this->frequencies[0]=1;
        this->length=1;
        return ;
    }
    bool resize=false;
    if(elem<this->minimum){
        this->minimum=elem;
        resize=true;
    }
    if(elem>this->maximum)
    {
        this->maximum=elem;
        resize=true;
    }
    if(resize==false)
    {
        this->frequencies[elem-this->minimum]++;
        this->length=this->length+1;
        return;
    }
    int newCap=maximum-minimum+1;
    int *newFreq=new int[newCap];
    for(int i=0;i<newCap;i++)
        newFreq[i]=0;
    if(this->minimum < oldMin)
    {
        int j=0;
        for(int i=oldMin-this->minimum;i<newCap;i++)
            newFreq[i]=this->frequencies[j++];
        newFreq[0]++;
    }

    if(this->maximum > oldMax)
    {
        for(int i=0;i<this->capacity;i++)
            newFreq[i]=this->frequencies[i];
        newFreq[newCap-1]++;
    }
    delete[] this->frequencies;
    this->frequencies=newFreq;
    this->capacity=newCap;
    this->length++;


}
//BC theta(1)
//WC theta(n)
//TC O(n)

bool Bag::remove(TElem elem) {
    if (this->length == 0 || search(elem) == false) {
        return false;
    }

    if (elem != this->minimum && elem != this->maximum) {
        this->frequencies[elem - this->minimum]--;
        this->length = this->length - 1;
        return true;
    }

    if (elem == this->minimum) {
        if (this->frequencies[elem - this->minimum] > 1) {
            this->frequencies[elem - this->minimum]--;
            this->length = this->length - 1;
            return true;
        } else {
            // If we only have one element, then go back to the initial structure
            if (this->length == 1) {
                this->minimum = NULL_TELEM;
                this->maximum = NULL_TELEM;
                this->length = 0;
                this->capacity = 1;
                delete[] this->frequencies;
                this->frequencies = new int[1];
                return true;
            }

            // Find the new minimum
            int oldMinimum = this->minimum;
            for (int i = 1; i < this->capacity; i++) {
                if (this->frequencies[i] > 0) {
                    this->minimum = i + this->minimum;
                    break;
                }
            }

            // Calculate the new capacity based on the new minimum element
            int newCapacity = this->maximum - this->minimum + 1;
            int *newFrequencies = new int[newCapacity];

            // Init a new list with 0
            for (int i = 0; i < newCapacity; i++) {
                newFrequencies[i] = 0;
            }

            // Logic for copying all frequencies starting from the new minimum element
            int j = 0;
            for (int i = this->minimum - oldMinimum; i < this->capacity; i++) {
                newFrequencies[j++] = this->frequencies[i];
            }

            // cleanup
            delete[] this->frequencies;
            this->frequencies = newFrequencies;
            this->capacity = newCapacity;
            this->length = this->length - 1;
        }
    }
    if (elem == this->maximum) {
        // If the element appears more than 1 time, good, just decrement
        if (this->frequencies[elem - this->minimum] > 1) {
            this->frequencies[elem - this->minimum]--;
            this->length = this->length - 1;
            return true;
        } else {
            // Else check if it's the only element, and go back to the initial
            // structure
            if (this->length == 1) {
                this->minimum = NULL_TELEM;
                this->maximum = NULL_TELEM;
                this->length = 0;
                this->capacity = 1;
                delete[] this->frequencies;
                this->frequencies = new int[1];
                return true;
            }

            // find the new maximum for the array
            for (int i = this->capacity - 2; i >= 0; i--) {
                if (this->frequencies[i] > 0) {
                    this->maximum = i + this->minimum;
                    break;
                }
            }

            // calculate the new capacity for the new maximum
            int newCapacity = this->maximum - this->minimum + 1;

            int *newFrequencies = new int[newCapacity];

            // just copy everything as it was until we reach the new maximum element
            for (int i = 0; i < newCapacity; i++) {
                newFrequencies[i] = this->frequencies[i];
            }

            // cleanup
            delete[] this->frequencies;
            this->frequencies = newFrequencies;
            this->capacity = newCapacity;
            this->length = this->length - 1;
        }
    }

    return true;
}
//BC=WC=TC=Theta(1)

bool Bag::search(TElem elem) const {

    return elem >= this->minimum && elem <= this->maximum && this->frequencies[elem - this->minimum] > 0;
}

//BC=WC=Tc=theta(n)
int Bag::nrOccurrences(TElem elem) const {
	if(elem<this->minimum || elem>this->maximum)
        return 0;
	return this->frequencies[elem-this->minimum];
}

//BC=Wc=TC=theta(1)
int Bag::size() const {

	return this->length;
}

//BC=WC=TC=theta(1)
bool Bag::isEmpty() const {
	if(this->length==0)
        return true;
	return false;
}

//BC=WC=TC=theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//theta(1)
Bag::~Bag() {
	delete[] this->frequencies;
}
//BC=theta(1)
//WC=theta(n)
//O(n)

int Bag::removeOccurrences(int nr, TElem elem) {


    if(nr<0)
        throw exception();
    int actual_nr=0;
    if(this->search(elem)==false)
        return 0;
    int pos=elem-this->minimum;
    actual_nr=this->frequencies[pos];
    if(actual_nr<=nr)
    {
        //this->frequencies[pos]=0;
        this->remove(elem);
        return actual_nr;
    }

    else
    {
        this->frequencies[pos]-=nr;
        return nr;
    }

}

