#include <iostream>

using namespace std;
struct Stack{
    int capacity;
    int* stack;
    int top;
    Stack(int cap){
        if (cap <= 0) {
        cout << "Invalid capacity." << endl;
        return;
    }
        top=-1;
        capacity=cap;
        stack=new int[capacity];
    }

    
    ~Stack(){
        delete[] stack;
    }

    bool isEmpty(){
        return top==-1;
    }
    
    bool isFull(){
        return top==capacity-1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
    
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<"->";
        }
        cout<<"NULL"<<endl;
    }
    
    void push(int value){
        if(isFull()){
            resize();
        }
        top++;
        stack[top]=value;
    }

     int pop(){
        if(isEmpty()){
            cout<<"It is empty"<<endl;
            return -1;
        }
        int poppedValue=stack[top];
        top--;
        return poppedValue;
    }


    void peek(){
        if(isEmpty()){
            cout<<"It is empty"<<endl;
            return;
        }
        cout<<"The top is "<<stack[top]<<endl;
    }
    private:
     void resize(){
        int cap=capacity*2;
        int* newStack=new int[cap];
        for(int i=0; i<=top; i++){
            newStack[i]=stack[i];
        }
        delete[] stack;
        stack=newStack;
        capacity=cap;
        cout<<"Resized to "<<capacity<<endl;

        
    }
};

int main(){
    Stack s(2);
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    cout<<"We removed "<<s.pop()<<endl;
    s.display();
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}