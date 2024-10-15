#pragma once

#include "SortedMultiMap.h"

class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation
private:
    TElem *elements;
    int currentElement, numberOfElements, capacity;

public:
    void DFS(Node *node);
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

