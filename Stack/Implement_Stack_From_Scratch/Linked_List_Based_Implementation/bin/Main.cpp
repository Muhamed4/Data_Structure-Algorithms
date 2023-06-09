#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{

    private:
        struct Node{
            T item;
            Node* Next;
            Node(T value): item(value), Next(nullptr) {}
        };

    public:
        Node* top;
        Stack(){
            top = nullptr;
        }

        void push(T element){
            Node* newNode = new Node(element);
            newNode->Next = top;
            top = newNode;
        }

        bool isEmpty(){
            return top == nullptr;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack empty on pop";
            }
            else{
                Node* temp = top;
                top = top->Next;
                temp->Next = nullptr;
                delete temp;
                temp = nullptr;
            }
        }

        T GetTop(){
            if(isEmpty()){
                throw std::runtime_error("Stack is empty");
            }
            else{
                return top->item;
            }
        }
};

int main(){
    

    return 0;
}