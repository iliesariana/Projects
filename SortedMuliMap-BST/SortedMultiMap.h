#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


typedef struct Node
{
    TKey key;
    TValue value;
   // int size,capacity;
    Node *left, *right;
}Node;

class SortedMultiMap {
	friend class SMMIterator;
    private:
		//TODO - Representation
        Node *root;
        Relation relation;
        int sizeOfBst;

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
    void deleteNodeWhenNoChildren(Node *node, Node *parentNode);
    void deleteNodeWhenOneChild(Node *node, Node *parentNode);
    void deleteNodeWhenTwoChildren(Node *node);
    void initNode(Node *node, TKey c, TValue v);

    //void resize(Node *node);
    std::vector<TKey> keySet() const;
    void recursiveDestructor(Node *node);

};
