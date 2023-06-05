

#ifndef DATA_STRUCTURE_IMPLEMENTATION_List_H
#define DATA_STRUCTURE_IMPLEMENTATION_List_H

#include<stdexcept>

namespace DSA
{

    template<typename T>
    class List{

        private:

            struct Node{
                T item;
                Node* next;
                Node(T element) : item(element), next(nullptr) {}
            };

            Node *head;
            Node *tail;
            int _size;

        public:

            List();

            ~List();

            int size() const;

            bool empty() const;

            T value_at(int index) const;

            void push_front(T element);

            T pop_front();

            void push_back(T element);

            T pop_back();

            T front();

            T back();

            void insert(int index, T element);

            void erase(int index);

            T value_n_from_end(int index);

            void reverse();

            void remove_value(T value);

        private:

            void increment_size();

            void decrement_size();
    };

    template<typename T>
    List<T>::List() : head(nullptr), tail(nullptr), _size(0) {}

    template<typename T>
    void List<T>::increment_size(){
        ++(*this)._size;
    }

    template<typename T>
    void List<T>::decrement_size(){
        --(*this)._size;
    }

    template<typename T>
    int List<T>::size() const{
        return (*this)._size;
    }

    template<typename T>
    bool List<T>::empty() const{
        return this->head == nullptr;
    }

    template<typename T>
    T List<T>::value_at(int index) const{
        if(index < 0 || index >= this->size()){
            throw std::out_of_range("the index is out of the range");
        }
        Node* temp = head;
        for(int i = 0 ; i < index;i++){
            temp = temp->next;
        }
        return temp->item;
    }

    template<typename T>
    void List<T>::push_front(T element){
        Node* temp = new Node(element);
        if(head == nullptr){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        (*this).increment_size();
    }

    template<typename T>
    T List<T>::pop_front(){
        T value;
        if(head == nullptr){
            throw std::runtime_error("There are no elements in the List");
        }
        else if(head == tail){
            value = head->item; 
            delete head;
            head = tail = nullptr;
        }
        else{
            value = head->item;
            Node *temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        (*this).decrement_size();
        return value;
    }

    template<typename T>
    void List<T>::push_back(T element){
        Node *temp = new Node(element);
        if(head == nullptr){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        (*this).increment_size();
    }

    template<typename T>
    T List<T>::pop_back(){
        T value;
        if(head == nullptr){
            throw std::runtime_error("There are no elements in the List");
        }
        if(head == tail){
            value = head->item;
            delete head;
            head = tail = nullptr;
        }
        else{
            value = tail->item;
            Node* cur = head->next;
            Node* prev = head;
            while(cur != tail){
                prev = cur;
                cur = cur->next;
            }
            delete cur;
            cur = nullptr;
            prev->next = nullptr;
            tail = prev;
        }
        (*this).decrement_size();
        return value;
    }

    template<typename T>
    T List<T>::front(){
        if(head == nullptr){
            throw std::runtime_error("The List is empty");
        }
        return (*this).head->item;
    }

    template<typename T>
    T List<T>::back(){
        if(head == nullptr){
            throw std::runtime_error("The List is empty");
        }
        return (*this).tail->item;
    }

    template<typename T>
    void List<T>::insert(int index, T element){
        if(index < 0 || index > (*this).size()){
            throw std::out_of_range("The index is out of the range");
        }
        if(index == 0){
            (*this).push_front(element);
        }
        else if(index == (*this).size()){
            (*this).push_back(element);
        }
        else{
            Node* temp = new Node(element);
            Node* prev = head;
            for(int i = 0; i < index - 1;i++){
                prev = prev->next;
            }
            Node* Next = prev->next;
            prev->next = temp;
            temp->next = Next;
            (*this).increment_size();
        }
    }

    template<typename T>
    void List<T>::erase(int index){
        if(index < 0 || index >= (*this).size()){
            throw std::runtime_error("You are trying to erase a value at index that does not in the range");
        }
        if(index == 0){
            (*this).pop_front();
        }
        else if(index == (*this).size() - 1){
            (*this).pop_back();
        }
        else{
            Node* prev = head;
            for(int i = 0; i < index - 1;i++){
                prev = prev->next;
            }
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            (*this).decrement_size();
        }
    }

    template<typename T>
    T List<T>::value_n_from_end(int index){
        if(index < 0 || index >= (*this).size()){
            throw std::out_of_range("The index is out of the range");
        }
        int actual_index = (*this).size() - index;
        Node* temp = head;
        for(int i = 0; i < actual_index;i++){
            temp = temp->next;
        }
        return temp->item;
    }

    template<typename T>
    void List<T>::reverse(){
        if(head == nullptr){
            throw std::runtime_error("There are no elements");
        }
        Node* prev = nullptr;
        Node* cur = head;
        Node *next = head->next;
        tail = head;
        while (next != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    template<typename T>
    void List<T>::remove_value(T value){
        if(head == nullptr){
            return;
        }
        Node *cur, *prev;
        if(head->item == value){
            cur = head;
            head = head->next;
            delete cur;
            if((*this).size() == 1){
                tail = nullptr;
            }
        }
        else{
            prev = head;
            cur = head->next;
            while(cur != nullptr && cur->item != value){
                prev = cur;
                cur = cur->next;
            }
            if(cur != nullptr){
                prev->next = cur->next;
                if(cur == tail){
                    tail = prev;
                }
                delete cur;
            }
        }
        (*this).decrement_size();
    }

    template<typename T>
    List<T>::~List(){
        Node* tmep = head;
        while(temp != nullptr){
            Node* Next = temp->next;
            delete temp;
            temp = Next;
        }
        head = tail = temp = nullptr;
    }


} // namespace DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_List_H



// index = 3
//
//  0  1  2  3  4  5
// [] [] [] [] [] []
//          ^
//          |
//
// actual index = size - index;
// actual index = 6 - 3 = 3;