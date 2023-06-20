//
// Created by muhamed on 19/06/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_QUEUE_H
#define DATA_STRUCTURE_IMPLEMENTATION_QUEUE_H

#include <stdexcept>
// Include the implemenation of the Vector data structure that we Implemented it previously
#include "../../../../Array/Implement_Vector_From_Scratch/include/Vector.hpp"

namespace DSA
{

    template<typename T>
    class Queue{

        private:
            int head;
            int tail;
            int _size;
            Vector<T> *_data;
        public:

            Queue();

            Queue(int Size);

            void enqueue(T element);

            T dequeue();

            bool empty();

            bool full();

            T& front();

            T& back();
            
            int size();

            ~Queue();


    };

    template<typename T>
    Queue<T>::Queue(): head(-1), tail(-1), _size(0), _data(new Vector<T>()) {}

    template<typename T>
    Queue<T>::Queue(int Size): head(-1), tail(-1), _size(Size), _data(new Vector<T>(_size)) {}

    template<typename T>
    Queue<T>::~Queue(){
        delete this->_data;
        _data = nullptr;
        head = -1;
        tail = -1;
    }

    template<typename T>
    bool Queue<T>::empty(){
        return (tail == -1);
    }

    template<typename T>
    bool Queue<T>::full(){
        return (((tail + 1) % this->_size) == head);
    }

    template<typename T>
    void Queue<T>::enqueue(T element){
        if(this->full()){
            throw std::runtime_error("Queue is Full ...!");
        }
        head = (head == -1) ? 0 : head;
        tail = (tail + 1) % this->_size;
        (*this->_data)[tail] = element;
    }

    template<typename T>
    T Queue<T>::dequeue(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty ...!");
        }
        T value = (*this->_data)[head];
        head = (head == tail) ? -1 : (head + 1) % this->_size;
        tail = (head == -1) ? -1 : tail;
        return value;
    }

    template<typename T>
    T& Queue<T>::front(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty...!");
        }
        return (*this->_data)[head];
    }

    template<typename T>
    T& Queue<T>::back(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty...!");
        }
        return (*this->_data)[tail];
    }

    template<typename T>
    int Queue<T>::size(){
        return (*this)._size;
    }


} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_QUEUE_H
