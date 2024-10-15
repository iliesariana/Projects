#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;
#include <set>
//theta(1)
SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation
    this->relation=r;
    this->root=NULL;
    this->sizeOfBst=0;
}

//theta(1)
void SortedMultiMap::initNode(Node *node, TKey c, TValue v) {
    node->key=c;
    node->value=v;
    node->right= nullptr;
    node->left= nullptr;

}
//BC=Theta(1), WC=theta(n), t=O(n)
void SortedMultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
    if (this->root == NULL)
    {
        this->root = new Node;
        this->initNode(this->root, c, v);
        this->sizeOfBst++;
        return;
    }


    Node* currentNode = this->root;
    while (true) {
        if (this->relation(c, currentNode->key)) {
            if (currentNode->left == NULL) {
                currentNode->left = new Node;
                this->initNode(currentNode->left, c, v);
                this->sizeOfBst++;
                return;
            } else {
                currentNode = currentNode->left;
            }
        } else {
            if (currentNode->right == NULL) {
                currentNode->right = new Node;
                this->initNode(currentNode->right, c, v);
                this->sizeOfBst++;
                return;
            } else {
                currentNode = currentNode->right;
            }
        }
    }
}
//best case: theta(1), worst case: theta(n), average case: theta(n)

vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation
//    vector<TValue> values;
//    Node* currentNode = this->root;
//    while (currentNode != NULL) {
//        if (currentNode->key == c) {
//            values.push_back(currentNode->value);
//        }
//        if (this->relation(c, currentNode->key)) {
//            currentNode = currentNode->left;
//        } else {
//            currentNode = currentNode->right;
//        }
//    }
//    return values;
    vector<TValue> matching;
    Node * currentNode = this->root;
    while (currentNode != nullptr) {
        if (this->relation(c, currentNode->key)) {
            // the elements are on the left tree if they exist
            if (c == currentNode->key) {
                matching.push_back(currentNode->value);
            }
            currentNode = currentNode->left;
        } else {
            // the elements are on the right tree if they exist
            currentNode = currentNode->right;
        }
    }
    return matching;
}

//BC=Theta(1), wc=theta(1)  AC=theta(1)
void SortedMultiMap::deleteNodeWhenNoChildren(Node* node, Node* parentNode) {
    if (parentNode == NULL) {
        this->root = NULL;
    } else if (parentNode->left == node) {
        parentNode->left = NULL;
    } else {
        parentNode->right = NULL;
    }
    delete node;
}
//BC=Theta(1) wc=theta(1) tc=theta(1)
void SortedMultiMap::deleteNodeWhenOneChild(Node* node, Node* parentNode) {
   Node *child;
   if(node->left!=NULL)
       child=node->left;
   else
       child=node->right;

    if (parentNode == NULL) {
        this->root = child;
    } else if (parentNode->left == node) {
        parentNode->left = child;
    } else {
        parentNode->right = child;
    }
    delete node;
}


// Best case: Theta(1), Worst case: O(n), Average case: O(n)
void SortedMultiMap::deleteNodeWhenTwoChildren(Node* node) {
    Node* parent = node;
    Node* successor = node->right;

    // Find the in-order successor (leftmost child in the right subtree)
    while (successor->left != NULL) {
        parent = successor;
        successor = successor->left;
    }

    // Replace node's key and value with successor's key and value
    node->key = successor->key;
    node->value = successor->value;

    // Remove successor node
    if (parent->left == successor) {
        parent->left = successor->right;
    } else {//if we dont have the left subtree of the right child
        parent->right = successor->right;
    }
    delete successor;

}

//BC=Theta(1), WC=O(n), AC=O(n)
bool SortedMultiMap::remove(TKey c, TValue v) {
    Node* currentNode = this->root;

    Node* parentNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == c && currentNode->value == v) {
            if (currentNode->left == NULL && currentNode->right == NULL) {
                this->deleteNodeWhenNoChildren(currentNode, parentNode);
            } else if (currentNode->left == NULL || currentNode->right == NULL) {
                this->deleteNodeWhenOneChild(currentNode, parentNode);
            } else {
                this->deleteNodeWhenTwoChildren(currentNode);
            }
            this->sizeOfBst--;
            return true;
        } else if (this->relation(c, currentNode->key)) {
            parentNode = currentNode;
            currentNode = currentNode->left;
        } else {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
    }
    return false;
}



//BC=Theta(1), WC=Theta(1), AC=Theta(1)
int SortedMultiMap::size() const {
	//TODO - Implementation
	return this->sizeOfBst;
}
//BC=Theta(1), WC=Theta(1), AC=Theta(1)
bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation
	return this->sizeOfBst==0;
}
//BC=Theta(1), WC=Theta(1), AC=Theta(1)

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}
//theta(n) since we always go through all the nodes
void SortedMultiMap::recursiveDestructor(Node *node)
{
    if (node == NULL)
        return;
    this->recursiveDestructor(node->left);
    this->recursiveDestructor(node->right);
   // delete[] node->values;
    delete node;
}
//theta(n) since we always go through all the nodes
SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
    this->recursiveDestructor(this->root);
}
//theta(n) since we always go through all the nodes
std::vector<TKey> SortedMultiMap::keySet() const {
    SMMIterator it=this->iterator();
    std::vector<TKey> keys;
    while (it.valid()) {
        TElem elem = it.getCurrent();

        if (keys.empty() || keys.back() != elem.first) {
            keys.push_back(elem.first);
        }
        it.next();
    }
    return keys;
}
