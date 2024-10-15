#include "ExtendedTest.h"
#include "ShortTest.h"

#include "SortedMap.h"
#include "SMIterator.h"

#include <iostream>
using namespace std;

bool relatie3(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
	testAll();
    cout<<"Short tests are over"<<"\n";
    testAllExtended();
	cout << "That's all!" << endl;


	system("pause");
	return 0;
}


