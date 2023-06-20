#include <bits/stdc++.h>
#include "../include/Queue.hpp"
using DSA::Queue;
using namespace std;

 int MAX_LENGTH = 100;

class Queue_C{

        int rear;
        int front;
        int length;
        int *arr = nullptr;
    public:
        Queue_C(int size){
            arr = new int[size];
            MAX_LENGTH = size;
            front = 0;
            rear = MAX_LENGTH - 1;
            length = 0;
        }

        ~Queue_C(){
            delete[] arr;
        }

        bool isEmpty(){
            return length == 0;
        }

        bool isFull(){
            return length == MAX_LENGTH;
        }

        void addQueue(int element){
            if(isFull()){
                cout << "Queue Full Can't Enqueue ...!" << endl;
                return;
            }
            rear = (rear + 1) % MAX_LENGTH;
            arr[rear] = element;
            length++;
        }

        void deleteQueue(){
            if(isEmpty()){
                cout << "Empty Queue Can't Dequeue...!" << endl;
                return;
            }
            front = (front + 1) % MAX_LENGTH;
            --length;
        }

        int getFront(){
            if(isEmpty()){
                throw runtime_error("Queue is Empty");
            }
            return arr[front];
        }

        int getRear(){
            if(isEmpty()){
                throw runtime_error("Queue is Empty");
            }
            return arr[rear];
        }

        void printQueue(){
            for(int i = front; (i % MAX_LENGTH) <= rear;i++){
                cout << arr[i] << " \n"[(i % MAX_LENGTH) == rear];
            }
        }

};

int main(){
    Queue<int> q(4);
    for(int i = 0; i < 5;i++){
        int x;cin >> x;
        q.enqueue(x);
    }
    q.front() = 5555;
    // cout << q.front() << endl;
    // cout << q.back() << endl;

    while(!q.empty()){
        cout << q.front() << ' ';
        q.dequeue();
    }
    return 0;
}