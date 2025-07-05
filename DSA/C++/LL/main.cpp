#include "lib.h"
#include <iostream>
using namespace std;
int main(){
    LL list;
    list.addHead(15);
    list.addHead(25);
    list.addHead(10);
    // list.deleteAnyWhere(2);
    // list.addTail(30);
    // list.addAnyWhere(40,2);
    // list.addAnyWhere(40,5);
    // list.deleteHead();
    // list.deleteTail();
    // list.reverse();
    // list.sortBubble();
    // list.mergeSort();
    list.search(10);
    list.printHead();
    list.printTail();
    list.printList();
    int length = list.length();
    cout<<"We have "<<length<<" Nodes"<<endl;
    return 0;
}