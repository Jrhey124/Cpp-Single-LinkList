// Basic Single Linked List C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class node {
    typedef string nodedata;
    nodedata value;
    node* next;

    node(nodedata val, node* next){
        this->value = val;
        this->next = next;
        }

    public:
    node(nodedata val){
        *this = node(val, NULL);
        }

    node* head(nodedata);
    node* tail(nodedata);
    node* move();
    node* search(nodedata);
    node copy();
    void free();

    int append(node);
    int replace(nodedata, nodedata);
    int insert(int, nodedata);
    int pop(nodedata);
    void traverse();

    };

node* node::head(nodedata val) {
    this->insert(0, val);
    return this;
}

node* node::tail(nodedata val) {
    node* tail = this;
    while (tail->next != NULL) tail = tail->next;// move to the tail of the linked list
    tail->next = new node(val);

    return tail->next;
}

node* node::move(){
    return this->next;
    }

node* node::search(nodedata val) {
    node* ptr = this;
    while (ptr != NULL) {
        if (ptr->value == val) return ptr; // return where the value was found.
        ptr = ptr->next;
        }
    return ptr; // NULL
    }

void node::traverse(){
    node* tail = this;
    while (tail != NULL) {
        cout << tail->value << endl;
        tail = tail->next;
    }
}



int node::replace(nodedata cmp, nodedata newval) {
    node* ptr = this->search(cmp);
    if (ptr == NULL) return -1; // value not found
    ptr->value = newval;
    return 0;
    }

int node::append(node node1) {
    node* ptr = &node1;
    while (ptr != NULL) {
        this->tail(ptr->value);
        ptr = ptr->next;
        }
    return 0;
    }


int node::insert(int position, nodedata val) {
    node* tail = this;

    for (int i = 0; i < position; i++) {
        if (tail == NULL) return -1;
        tail = tail->next;
    }

    tail->next = new node(tail->value, tail->next);
    tail->value = val;
    return 0;
}

int node::pop(nodedata cmp) {
    node* ptr = this, *copy = NULL;
    if (this->value == cmp) { // special case! pop the beginning
        if (this->next == NULL) {
            memset(&this->value, '\0', sizeof(nodedata));
        }
        else { // head are replaced by the next node
            copy = this->next;
            this->value = copy->value;
            this->next = copy->next;
            delete copy;
        }
        return 0;
    }

    while (ptr != NULL) {

        if (ptr->value == cmp) {
            copy->next = ptr->next;
            delete ptr;
            return 0;
            }
        copy = ptr;
        ptr = ptr->next;
    }
    return -1; // not found
}

node node::copy(){
    node* tail = this;
    node newnode = node(this->value);
    while (tail->next != NULL) {
        tail = tail->next;
        newnode.tail(tail->value);
        }
    return newnode;
    }

void node::free() {
    node* tail = this->next;
    while (tail != NULL) {
        node* ref = tail;
        tail = tail->next;
        delete ref;
        }

    this->next = NULL;
    }



int main(){

    }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
