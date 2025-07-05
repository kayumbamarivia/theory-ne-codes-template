#include <iostream>
#include "lib.h"

using namespace std;

LL::~LL(){
    Node* temp = head;
    while (temp){
        Node* next = temp->link;
        delete temp;
        temp = next;
    }
}


int LL::length(){
    int counter = 0;
    Node* temp = head;
    while(temp){
        counter++;
        temp=temp->link;
    }
    return counter;
}

void LL::printHead(){
     if (head!=nullptr) {
        cout << "Our first node is (Pointed to by head): " << head->value << endl;
    } else {
        cout << "List is empty (head is null)" << endl;
    }
}

void LL::printTail(){
    if(tail){
        cout << "Our Last node is (Pointed to by tail): " << tail->value << endl;
    }else{
        cout << "Our Linked list is empty"<< endl;
    }

}
void LL::printList(){
    if(!head){
        cout<<"Empty list"<<endl;
        return;
    }
    cout<<"Traversing our Linked list"<<endl;
    Node* temp=head;
    while (temp)
    {
        cout<<temp->value<<"->";
        temp = temp->link;
    }

    cout<<"NULL"<<endl;
    
}

void LL::addHead(int val){
    Node* newNode = new Node(val);
    if(!head) return;
    newNode->link=head;
    head=newNode;
    if(!tail){
        tail=newNode;
    }
}

void LL::deleteHead(){
    if(!head) return;
    Node* temp=head;
    head=temp->link;
    delete temp;
}

void LL::addTail(int val){
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;
        tail = newNode;
    }
}

void LL::deleteTail(){
    if (!head) {
        cout << "List is empty already" << endl;
        return;
    }

    if (!head->link) {
        delete head;
        head = nullptr;
        tail = nullptr;
        cout << "Deleted the only node in the list" << endl;
        return;
    }

    Node* temp = head;
    while (temp->link->link != nullptr) {
        temp = temp->link;
    }

    delete temp->link;
    temp->link = nullptr;
    tail = temp;

    cout << "Tail node deleted" << endl;
}


void LL::addAnyWhere(int val, int pos){
    if(pos<=0){
        cout<<"We only accept nuture numbers for position"<<endl;
        return;
    }
    if(pos==1){
        cout<<"Added at head"<<endl;
        addHead(val);
        return;
    }

    int len = length();

    if(pos==len+1){
        cout<<"Added at tail"<<endl;
        addTail(val);
        return;
    }

    if(pos>len+1){
        cout<<"That position can't be reached"<<endl;
        return;
    }

    Node* temp=head;
    int i=1;
    while(i<pos-1 and temp){
        temp=temp->link;
        i++;
    }

    Node* newNode=new Node(val);
    newNode->link=temp->link;
    temp->link=newNode;
}

void LL::reverse(){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while(curr){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    tail=head;
    head=prev;
}

void LL::deleteAnyWhere(int pos){
    if(pos<=0){
        cout<<"Negatives and zeros are not supported"<<endl;
        return;
    }

    if(pos==1){
        deleteHead();
        return;
    }

    int len = length();
    if(pos==len){
        deleteTail();
        return;
    }

    if(pos>len){
        cout<<"We can't delete what we do not have"<<endl;
        return;
    }

    int i=1;
    Node* temp=head;
    while(i<pos-1 and temp){
        temp=temp->link;
        i++;
    }

    Node* toDelete = temp->link;
    temp->link=toDelete->link;
    delete toDelete;
}

void LL::sortBubble(){
    if(!head or !head->link){
        cout<<"Already sorted"<<endl;
        return;
    }

    Node* end=nullptr;
    Node* current=nullptr;
    int temp;
    bool swapped;

    do{
        swapped=false;
        current=head;
        while(current->link != end){
            if(current->value > current->link->value){
                temp=current->value;
                current->value=current->link->value;
                current->link->value=temp;
                swapped=true;
            }
            current=current->link;
        }

        end=current;

    }while(swapped);
}

Node* getMiddle(Node* head){
    if(!head) return head;

    Node* slow=head;
    Node* fast=head->link;
    while(fast and fast->link){
        fast=fast->link->link;
        slow=slow->link;
    }

    return slow;

}

Node* sortedMerge(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* result=nullptr;
    if(a->value<b->value){
        result=a;
        result->link=sortedMerge(a->link,b);
    }else{
        result=b;
        result->link=sortedMerge(a, b->link);
    }
    return result;
}

Node* sorter(Node* head){
    if(!head or !head->link) return head;
    Node* middle=getMiddle(head);
    Node* nextOfMiddle=middle->link;
    middle->link=nullptr;

    Node* left=sorter(head);
    Node* right=sorter(nextOfMiddle);
    return sortedMerge(left, right);
}

void LL::mergeSort(){
    head=sorter(head);
    tail=head;
    while(tail and tail->link){
        tail=tail->link;
    }
}

void LL::search(int value){
    int counter=1;
    if(head->value == value){
        cout<<value<<" is found at head at"<<counter<<endl;
        return;
    }

    if(tail->value==value){
        cout<<value<<" is found at tail at "<<length()<<endl;
        return;
    }

    Node* temp=head;
    while(temp and temp->link){
        if(temp->value==value){
            cout<<value<<" is found at "<<counter<<endl;
        }
        temp=temp->link;
        counter++;
    }

    cout<<"Value not found"<<endl;
}