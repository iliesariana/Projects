#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include "assert.h"
using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All test over" << endl;
   // testNew();
    Bag b;
    b.add(1);
    b.add(2);
    b.add(1);
    b.add(3);
    b.add(3);
    b.add(3);
    assert(b.removeOccurrences(5,3)==3);
    assert(b.nrOccurrences(1)==2);
    assert(b.removeOccurrences(1,1)==1);
    assert(b.nrOccurrences(1)==1);
    try {
        b.removeOccurrences(-1,2);
        assert(false);
    }
    catch(exception &ex)
    {
        assert(true);
    }
    assert(b.removeOccurrences(1,1)==1);
    assert(b.size()==4);

}