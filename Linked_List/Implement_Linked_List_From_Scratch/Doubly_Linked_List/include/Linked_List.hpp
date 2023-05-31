

#ifndef DATA_STRUCTURE_IMPLEMENTATION_List_H
#define DATA_STRUCTURE_IMPLEMENTATION_List_H

#include<stdexcept>

namespace DSA
{
    template<typename T>
    class List{

        private:

            struct Node
            {
                T item;
                Node* next;
                Node* prev;
                Node(T element): item(element), next(nullptr), prev(nullptr) {}
            };

            Node* head;
            Node* tail;
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

        private:

            void increment_size();

            void decrement_size();

            Node* Get_Node_at_index(int index);
            
    };


    template<typename T>
    List<T>::List(): head(nullptr), tail(nullptr), _size(0) {}

    template<typename T>
    void List<T>::increment_size(){
        ++(*this)._size;
    }

    template<typename T>
    void List<T>::decrement_size(){
        --(*this)_size;
    }

    template<typename T>
    Node* List<T>::Get_Node_at_index(int index){
        Node* prev = head;
        // index = 2
        // [] [] [] [] []
        for(int i = 0 ; i < index - 1;i++){
            prev = prev->next;
        }
        return prev;
    }

    template<typename T>
    int List<T>::size() const{
        return (*this)._size;
    }

    template<typename T>
    bool List<T>::empty() const{
        return (*this).head == nullptr; 
    }

    template<typename T>
    T List<T>::value_at(int index) const{
        if(index < 0 || index >= (*this).size()){
            throw std::out_of_range("the index is out of the range");
        }
        Node* temp = head;
        for(int i = 0; i < index;i++){
            temp = temp->next;
        }
        return (*temp).item;
    }

    template<typename T>
    void List<T>::push_front(T element){
        Node* newNode = new Node(element);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
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
            Node* temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            temp = nullptr;
        }
        (*this).decrement_size();
        return value;
    }

    template<typename T>
    void List<T>::push_back(T element){
        Node* newNode = new Node(element);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
            Node* temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = nullptr;
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
        else if(indx == (*this).size()){
            (*this).push_back(element);
        }
        else{
            Node* temp = new Node(element);
            Node* prev = (*this).Get_Node_at_index(index);
            Node* Next = prev->next;
            prev->next = temp;
            temp->prev = prev;
            temp->next = Next;
            Next->prev = temp;
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
            Node* prev = (*this).Get_Node_at_index(index);
            Node* temp = prev->next;
            prev->next = temp->next;
            temp->next->prev =  prev;
            delete temp;
            temp = nullptr;
            (*this).decrement_size();
        }
    }

    template<typename T>
    T List<T>::value_n_from_end(int index){
        if(index < 0 || index >= (*this).size()){
            throw std::out_of_range("The index is out of the range");
        }
        // index = 2
        // [] [] [] [] []
        Node* temp = tail;
        for(int i = 0; i < index - 1;i++){
            temp = temp->prev;
        }
        return (*temp).item;
    }


} // namespace DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_List_H
