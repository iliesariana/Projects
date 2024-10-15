#include "SMMIterator.h"
#include "SortedMultiMap.h"
//theta(n)
void SMMIterator::DFS(Node *node)
{
    if (node == nullptr)
        return;

    this->DFS(node->left);


    this->elements[this->numberOfElements++] = TElem(node->key, node->value);

    this->DFS(node->right);
}
//theta(n)
SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	//TODO - Implementation
    this->capacity = this->map.sizeOfBst;  // The capacity is at least the number of nodes in the map
    this->elements = new TElem[this->capacity];
    this->currentElement = 0;
    this->numberOfElements = 0;
    this->DFS(this->map.root);
}
//theta(1)
void SMMIterator::first(){
	//TODO - Implementation
    this->currentElement=0;
}
//theta(1)
void SMMIterator::next(){
	//TODO - Implementation
    if (!this->valid())
        throw std::exception();
    this->currentElement++;

}
//  theta(1)
bool SMMIterator::valid() const{
	//TODO - Implementation
    return this->currentElement < this->numberOfElements;
}
//theta(1)
TElem SMMIterator::getCurrent() const{
    if (!this->valid())
        throw std::exception();
    return this->elements[this->currentElement];
}


