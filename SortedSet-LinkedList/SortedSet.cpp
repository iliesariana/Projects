#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <stdio.h>
SortedSet::SortedSet(Relation r) {
    this->rel=r;
    this->cap=10;
    this->head=-1;
    this->tail=-1;
    this->len=0;
    this->firstEmpty=0;
    this->nodes=new Node[this->cap];

}

//Bc=theta(1)
//WC=theta(n)
//AC=O(n)
bool SortedSet::add(TComp elem) {
    //if the element already exists we do not add it
    if(this->search(elem))
        return false;
    Node *newNode = new Node;
    newNode->value=elem;
    newNode->next= nullptr;
    if(this->head== nullptr)
    {
        this->head=newNode;
        this->tail=this->head;
        this->len++;
        return true;
    }
    if(!this->rel(this->head->value,elem)) {
        newNode->next=this->head;
        this->head=newNode;
        this->len++;
        return true;
    }
    //we add it somewhere else
    Node *prev= nullptr;
    Node *current=this->head;
    while(current != nullptr && this->rel(current->value,elem)){
        prev=current;
        current=current->next;
    }
    //we put it at the end
    if(current== nullptr)
    {
        this->tail->next=newNode;
        this->tail=newNode;
        this->len++;
        return true;
    }
    //we put it between two elems
    prev->next=newNode;
    newNode->next=current;
    this->len++;
    return true;






//    if (this->search(elem))
//        return false;
//
//    Node* newNode = new Node;
//    newNode->value = elem;
//    newNode->next = nullptr;
//
//    if (this->head == nullptr) {
//        this->head = newNode;
//        this->tail = newNode;
//    } else if (!this->rel(this->head->value, elem)) {
//        newNode->next = this->head;
//        this->head = newNode;
//    } else {
//        Node* prev = nullptr;
//        Node* current = this->head;
//        while (current != nullptr && this->rel(current->value, elem)) {
//            prev = current;
//            current = current->next;
//        }
//        if (current == nullptr) {
//            this->tail->next = newNode;
//            this->tail = newNode;
//        } else {
//            prev->next = newNode;
//            newNode->next = current;
//        }
//    }
//
//    this->len++;
//    return true;
}

//BC=theta(1)
//WC=theta(n)
//TC=O(N)
bool SortedSet::remove(TComp elem) {
    if (this->head == nullptr)
        return false;

    if(this->head->value==elem){
        Node *newNode=this->head;//stores the pointer to the node that will be removed
        this->head=this->head->next;
        delete newNode;
        this->len--;
        if(this->head== nullptr)
            this->tail= nullptr;
        return true;
    }



    Node* prev = this->head;
    Node* current = prev->next;
    while (current != nullptr) {
        if (current->value == elem) {
            prev->next = current->next;
            if (current == this->tail) {
                this->tail = prev;
            }
            delete current;
            this->len--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

//BC=theta(1)
//WC=theta(n)
//AC=O(n)


bool SortedSet::search(TComp elem) const {
	int current=this->head;
    if(this->len==0)
        return false;
    Node node=this->nodes[current];
    while(node.


}

//bc=wc=tc=theta(1)
int SortedSet::size() const {
	//TODO - Implementation
	return this->len;
}


//bc=wc=tc=theta(1)
bool SortedSet::isEmpty() const {
	if(this->head== nullptr)
        return true;
	return false;
}

SortedSetIterator SortedSet::iterator()  {
	return SortedSetIterator(*this);
}

//bc=theta(1)
//wc=theta(n)
//tc=O(n)
SortedSet::~SortedSet() {
    Node * currentNode=this->head;
    if(this->head== nullptr)
        return ;
    while(currentNode!= nullptr)
    {
        Node *nextNode=currentNode->next;
        delete currentNode;
        currentNode=nextNode;
    }

}


