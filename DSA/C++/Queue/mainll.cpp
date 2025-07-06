#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int value) {
        data = value;
        link = nullptr;
    }
};

struct Queue {
    Node* front;
    Node* rear;
    
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "The front is " << front->data << endl;
        }
    }

    void push(int value) {
        Node* temp = new Node(value);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->link = temp;
            rear = temp;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int poppedValue = front->data;
        front = front->link;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return poppedValue;
    }

    void display() {
        if (isEmpty()) {
            cout << "The Queue is empty" << endl;
        } else {
            Node* temp = front;
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->link;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Queue q;
    int numbers[3];
    q.push(10);
    q.push(20);
    q.push(30);

    for (int i = 0; i < 3; i++) {
        numbers[i] = q.pop();
    }

    cout << "We removed " << q.pop() << endl;

    q.display();
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Our array:" << endl;
    for (int num : numbers) {
        cout << num << endl;
    }

    return 0;
}
