// intlist.cpp
// Implements class IntList
// Hechenjin Yu, Ruijie Tao
// Thu Oct 19

#include "intlist.h"

#include <limits.h>
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    Node *curr = source.first;
    while (curr){
        this->append(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    clear();
}

void IntList::clear(){
    Node* curr = first;
    Node* toDelete;
    while (curr){
        toDelete = curr;
        curr = curr->next;
        delete toDelete;
    }
    first = nullptr;
}

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = this->first;
    while (curr){
        sum += curr->info;
        curr = curr->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = this->first;
    while(curr){
        if (curr->info == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!first){
        return 0;
    }
    int max_value = INT_MIN;
    Node* curr = first;
    while (curr){
        max_value = std::max(max_value, curr->info);
        curr = curr->next;
    }
    return max_value;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!first){
        return 0;
    }
    int num = this->count();
    int sum = this->sum();
    return static_cast<double>(sum) / num;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* head = new Node;
    head->info = value;
    head->next = first;
    first = head;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }
    this->clear();
    
    Node *curr = source.first;
    while(curr != nullptr) {
        this->append(curr->info);
        curr = curr->next;
    }

    return *this;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
