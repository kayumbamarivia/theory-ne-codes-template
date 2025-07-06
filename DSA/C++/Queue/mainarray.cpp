#include <iostream>

using namespace std;
struct Queue{
    int capacity;
    int* queue;
    int front;
    int rear;
    Queue(int cap){
        if (cap <= 0) {
        cout << "Invalid capacity." << endl;
        return;
    }
        rear=front=-1;
        capacity=cap;
        queue=new int[capacity];
    }

    
    ~Queue(){
        delete[] queue;
    }
    
    bool isEmpty(){
        return front==-1 or front > rear;
    }
    
    bool isFull(){
        return rear==capacity-1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
    
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<"->";
        }
        cout<<"NULL"<<endl;
    }
    
    void push(int value){
        if(isFull()){
            resize();
        }
        if(isEmpty()){
            front=0;
        }
        rear++;
        queue[rear]=value;
    }

    int pop(){
        if(isEmpty()){
            cout<<"It is empty"<<endl;
            return -1;
        }
        int poppedValue=queue[front];
        front++;
        return poppedValue;
    }

    void peek(){
        if(isEmpty()){
            cout<<"It is empty"<<endl;
            return;
        }
        cout<<"The top is "<<queue[front]<<endl;
    }

    private:
     void resize(){
        int cap=capacity*2;
        int* newQueue=new int[cap];
        for(int i=0; i<=rear; i++){
            newQueue[i]=queue[i];
        }
        delete[] queue;
        queue=newQueue;
        capacity=cap;
        cout<<"Resized to "<<capacity<<endl;

        
    }
};

int main(){
    Queue q(2);
    q.push(10);
    q.push(20);
    q.push(30);
    q.peek();
    q.display();
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}