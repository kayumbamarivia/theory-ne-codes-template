#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* link;
    Node(int value){
        this->data=value;
        this->link=nullptr;
    }
};

struct Stack{
    Node* top;
    Stack():top(nullptr){}

    bool isEmpty(){
        return top==nullptr;
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"The top is"<<top->data<<endl;
        }
    }

    void push(int value){
        Node* temp=new Node(value);
        if(isEmpty()){
            top=temp;
        }
        temp->link=top;
        top=temp;
    }

    void display(){
        if (isEmpty())
        {
            cout<<"The stack is empty"<<endl;
        }else{
            Node* temp=top;
            while(temp){
                cout<<temp->data<<"->";
                temp=temp->link;
            }
            cout<<"NULL"<<endl;
        }
        
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        Node* temp=top;
        int poppedValue=top->data;
        top=top->link;
        delete temp;
        return poppedValue;
    }
};

int main(){
    Stack s;
    int numbers[3];
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.display();
    for (int i = 0; i < 3; i++) {
        numbers[i] = s.pop();
    }
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "Our array:" << endl;
    for (int num : numbers) {
        cout << num << endl;
    }
    return 0;
}