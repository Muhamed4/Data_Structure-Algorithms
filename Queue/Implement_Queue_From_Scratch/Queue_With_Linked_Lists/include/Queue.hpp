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

            struct Node
            {
                T item;
                Node* Next;
                Node(T element): item(element), Next(nullptr) {}
            };

            Node* head;
            Node* tail;
            int _size;

        public:

            Queue();

            void enqueue(T element);

            T dequeue();

            bool empty();

            T& front();

            T& back();

            ~Queue();


        private:

            void increment_size();

            void decrement_size();
            
    };

    template<typename T>
    Queue<T>::Queue(): head(nullptr), tail(nullptr), _size(0) {}

    template<typename T>
    void Queue<T>::increment_size(){
        ++this->_size;
    }

    template<typename T>
    void Queue<T>::decrement_size(){
        --this->_size;
    }

    template<typename T>
    void Queue<T>::enqueue(T element){
        Node* newNode = new Node(element);
        head = (head == nullptr) ? newNode : head;
        if(tail != nullptr)
            tail->Next = newNode;
        tail = newNode;
        this->increment_size();
    }

    template<typename T>
    bool Queue<T>::empty(){
        return (head == nullptr);
    }

    template<typename T>
    T Queue<T>::dequeue(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty...!");
        }
        Node* temp = head;
        T value = head->item;
        head = (head == tail) ? nullptr : head->Next;
        tail = (head == nullptr) ? nullptr : tail;
        delete temp;
        temp = nullptr;
        this->decrement_size();
        return value;
    }

    template<typename T>
    T& Queue<T>::front(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty...!");
        }
        return head->item;
    }

    template<typename T>
    T& Queue<T>::back(){
        if(this->empty()){
            throw std::runtime_error("Queue is Empty...!");
        }
        return tail->item;
    }

    template<typename T>
    Queue<T>::~Queue(){
        while(head != nullptr){
            Node* temp = head;
            head = head->Next;
            delete temp;
            temp = nullptr;
        }
        head = tail = nullptr;
        this->_size = 0;
    }

} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_QUEUE_H
