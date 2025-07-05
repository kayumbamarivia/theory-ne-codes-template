#pragma once
struct Node {
    int value;
    Node* link;
    Node(int val);
};

class LL {
    public:
    Node* head;
    Node* tail;
    LL(){
        this->head=nullptr;
        this->tail=nullptr;
    }

    ~LL();

    void printHead();
    void printTail();
    void printList();
    int length();
    void addHead(int val);
    void addTail(int val);
    void reverse();
    void addAnyWhere(int val, int pos);  
    void deleteHead();
    void deleteTail();  
    void deleteAnyWhere(int pos);
    void sortBubble();
    void mergeSort();
    void search(int value);
};