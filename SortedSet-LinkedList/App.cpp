#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
#include <cassert>

using namespace std;
bool r3(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
	testAll();
	testAllExtended();
	cout << "Test end" << endl;

//	system("pause");
    SortedSet set= SortedSet(r3);
    SortedSetIterator it = set.iterator();

    try {
        it.remove();
        assert(false);
    }
    catch(exception &e)
    {
        assert(true);
    }

    set.add(2);
    set.add(3);
    set.add(4);
    it.first();
    assert(set.size()==3);
    assert(it.remove()==2);
    assert(set.size()==2);
    assert(it.remove()==3);
    assert(set.size()==1);
    it.next();
    try {
        assert(it.remove());
        assert(false);
    }
    catch (exception &e)
    {
        assert(true);
    }

}