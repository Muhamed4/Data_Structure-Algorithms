//
// Created by muhamed on 5/06/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_STACK_H
#define DATA_STRUCTURE_IMPLEMENTATION_STACK_H

#include <stdexcept>

namespace DSA
{
    template<typename T>
    class Stack
    {
        private:
            
            struct Node
            {
                T item;
                Node* Next;
                Node(T val): item(val), Next(nullptr) {}
            };

            Node* _top;
            int _size;

        public:
            Stack();

            ~Stack();

            void push(T element);

            void pop();

            bool empty();

            int size();

            T& top();

        private:

            void increment_size();

            void decrement_size();
    };

    template<typename T>
    Stack<T>::Stack(): _top(nullptr), _size(0) {}


    template<typename T>
    void Stack<T>::increment_size(){
        ++(*this)._size;
    }

    template<typename T>
    void Stack<T>::decrement_size(){
        --(*this)._size;
    }


    template<typename T>
    void Stack<T>::push(T element){
        Node* newNode = new Node(element);
        newNode->Next = this->_top;
        this->_top = newNode;
    }

    template<typename T>
    bool Stack<T>::empty(){
        return (this->_top == nullptr);
    }

    template<typename T>
    void Stack<T>::pop(){
        if(this->empty()){
            throw std::runtime_error("The stack is empty !!!");
        }
        Node* temp = this->_top;
        this->_top = this->_top->Next;
        delete temp;
        temp = nullptr;
    }

    template<typename T>
    int Stack<T>::size(){
        return this->_size;
    }
    
    template<typename T>
    T& Stack<T>::top(){
        if(this->empty()){
            throw std::runtime_error("The stack is empty !!!");
        }
        return this->_top->item;
    }

    template<typename T>
    Stack<T>::~Stack(){
        while(_top != nullptr){
            Node* temp = _top;
            _top = _top->Next;
            delete temp;
            temp = nullptr;
        }
        _top = nullptr;
    }
    
} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_STACK_H
