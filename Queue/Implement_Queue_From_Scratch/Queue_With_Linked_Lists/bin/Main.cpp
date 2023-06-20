#include <bits/stdc++.h>
#include "../include/Queue.hpp"
using DSA::Queue;
using namespace std;

class LinkedQueue{
    private:
        struct Node
        {
            int item;
            Node* Next;
            Node(int val): item(val), Next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int _size;


    public:

        LinkedQueue(): head(nullptr), tail(nullptr), _size(0) {}

        bool empty(){
            return (tail == nullptr);
        }

        void enqueue(int element){
            Node* newNode = new Node(element);
            if(this->empty()){
                head = tail = newNode;
            }
            else{
                tail->Next = newNode;
                tail = newNode;
            }
            ++_size;
        }

        void dequeue(){
            if(this->empty()){
                cout << "Queue is Empty...!" << endl;
                return;
            }
            Node* temp = head;
            if(head == tail){
                head = tail = nullptr;
            }
            else {
                head = head->Next;
                temp->Next = nullptr;
            }
            delete temp;
            temp = nullptr;
            --_size;
        }

        void clear(){
            Node* current;
            while(head != nullptr){
                current = head;
                head = head->Next;
                delete current;
            }
            tail = nullptr;
            _size = 0;
        }

        void Display(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->item << ' ';
                temp = temp->Next;
            }
            cout << endl;
        }

        int front(){
            if(this->empty()){
                return -1;
            }
            return head->item;
        }

        int back(){
            if(this->empty()){
                return -1;
            }
            return tail->item;
        }
        
};

int main(){
    
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(20);
    // q.front() = 5555;
    // q.back() = 302020;
    // cout << q.front() << endl;
    // cout << q.back() << endl;

    while(!q.empty()){
        cout << q.front() << ' ';
        q.dequeue();
    }

    return 0;
}