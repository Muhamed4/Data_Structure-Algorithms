#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
template<typename T>
class Stack{
    private:
        int top;
        T item[MAX_SIZE];
    public:
        Stack() : top(-1) {}

        void push(T element){
            if(top >= MAX_SIZE - 1){
                cout << "Stack is full on push" << endl;
                return;
            }
            item[++top] = element;
        }

        void pop(){
            if(top == -1){
                cout << "Stack is empty on pop" << endl;
                return;
            }
            --top;
        }

        void pop(T& Element){
            if(top == -1){
                cout << "Stack is empty on pop" << endl;
                return;
            }
            Element = item[top];
            --top;
        }

        void getTop(T& StackTop){
            if(top == -1){
                cout << "Stack is empty on pop" << endl;
                return;
            }
            StackTop = item[top];
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else return false;
        }

        void Print(){
            for(int i = top; i >= 0;i--){
                cout << item[i] << ' ';
            }
            cout << '\n';
        }
};

int main(){

    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.Print();

    return 0;
}