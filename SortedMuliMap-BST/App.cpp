#include <iostream>
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
bool relation5(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}
#include <assert.h>
int main(){
    testAll();
//
   testAllExtended();
    SortedMultiMap smm = SortedMultiMap(relation5);
    ;
    smm.add(1,2);
    smm.add(1,3);
    smm.add(2,3);

    std::vector<TKey> keys=smm.keySet();
    assert(keys.size()==2);
    assert(keys[0]==1);
    assert(keys[1]==2);
    smm.add(3,4);
    keys=smm.keySet();
    assert(keys.size()==3);
    std::cout<<"Finished SMM Tests!"<<std::endl;
	system("pause");


}
