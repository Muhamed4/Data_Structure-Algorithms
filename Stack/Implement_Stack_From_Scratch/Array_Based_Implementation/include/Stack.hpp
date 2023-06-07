//
// Created by muhamed on 5/06/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_STACK_H
#define DATA_STRUCTURE_IMPLEMENTATION_STACK_H

#include <stdexcept>
// Include the implemenation of the Vector data structure that we Implemented it previously
#include "../../../../Array/Implement_Vector_From_Scratch/include/Vector.hpp"

namespace DSA
{

    template<typename T>
    class Stack{
        private:
            // Using the Vector data structure that we implemented previously
            Vector<T> *_data;
            int _top;
            int _size;
        public :
            
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
    Stack<T>::Stack(){
        _data = new Vector<T>();
        _top = -1;
        _size = 0;
    }

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
        (*this)._data->push_back(element);
        (*this).increment_size();
    }

    template<typename T>
    void Stack<T>::pop(){
        if((*this).size() == 0){
            throw std::runtime_error("You are trying to pop from an empty stack !!!");
        }
        (*this)._data->pop_back();
        (*this).decrement_size();
    }

    template<typename T>
    int Stack<T>::size(){
        return (*this)._size;
    }

    template<typename T>
    bool Stack<T>::empty(){
        return ((*this).size() == 0);
    }

    template<typename T>
    T& Stack<T>::top(){
        if((*this).empty()){
            throw std::runtime_error("You are trying to access an empty stack");
        }
        return (*this)._data->back();
    }

    template<typename T>
    Stack<T>::~Stack(){
        delete _data;
        _data = nullptr;
        _top = -1;
    }

} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_STACK_H
