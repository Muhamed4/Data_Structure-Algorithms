//
// Created by muhamed on 12/05/23.
//

#ifndef DATA_STRUCTURE_IMPLEMENTATION_VECTOR_H
#define DATA_STRUCTURE_IMPLEMENTATION_VECTOR_H

#include <stdexcept>

namespace DSA
{

    template <typename T>
    class Vector
    {
    private:
        int size_data;
        int capacity_data;
        T *data;
        int current_item;

    public:
        Vector();
        Vector(int _size);
        ~Vector();
        int size() const;
        int capacity() const;
        bool empty() const;
        T at(int index) const;
        void push_back(T item);
        void insert(int index, T item);
        void pop_back();
        void Delete(int index);
        void remove(T item);
        void find(T item);

    private:
        void increment_size();
        void decrement_size();
        void increment_capacity();
        void Modify_data();
        void resize();
    };

    template <typename T>
    Vector<T>::Vector()
    {
        this->size_data = 0;
        this->capacity_data = 0;
        this->current_item = -1;
        this->data = new T[this->capacity_data];
    }

    template <typename T>
    Vector<T>::Vector(int _size)
    {
        this->size_data = _size;
        this->capacity_data = _size;
        this->current_item = -1;
        this->data = new T[this->capacity_data];
    }

    template <typename T>
    int Vector<T>::size() const
    {
        return this->size_data;
    }

    template <typename T>
    int Vector<T>::capacity() const
    {
        return this->capacity_data;
    }

    template <typename T>
    bool Vector<T>::empty() const
    {
        return this->size() > 0;
    }

    template <typename T>
    T Vector<T>::at(int index) const
    {
        if (index < 0 || index >= this->size())
        {
            throw std::out_of_range("Vector::_M_range_check: __n (which is " + std::to_string(index) + " >= this->size() (which is " +
                                    std::to_string(this->size()) + ")");
        }
        return this->data[index];
    }

    template<typename T>
    void Vector<T>::Modify_data(){
        T new_data = new T[this->capacity()];
        for (int i = 0; i < this->size(); i++)
        {
            new_data[i] = this->data[i];
        }
        delete[] this->data;
        this->data = new_data;
        new_data = nullptr;
    }    

    template <typename T>
    void Vector<T>::push_back(T item)
    {
        if (this->size() == this->capacity())
        {
            this->increment_capacity();
            // Modify the data_elements
            this->Modify_data();
        }
        this->data[this->size()] = item;
        this->increment_size();
    }

    template <typename T>
    void Vector<T>::increment_size()
    {
        ++this->size_data;
    }
    
    template<typename T>
    void Vector<T>::decrement_size(){
        --this->size_data;
    }

    template <typename T>
    void Vector<T>::increment_capacity()
    {
        if (this->capacity_data == 0)
        {
            this->capacity_data = 1;
        }
        else
        {
            this->capacity_data = this->capacity_data * 2;
        }
    }

    template<typename T>
    void Vector<T>::resize(){
        int ratio = this->capacity() / this->size();
        if(ratio >= 4){
            this->capacity_data = (this->capacity_data + 1) / 2;
            this->Modify_data();
        }
    }

    template <typename T>
    void Vector<T>::insert(int index, T item)
    {
        if (index < 0 || index > this->size())
        {
            throw std::out_of_range("this index is not allowed, it is out of range of the vector");
        }
        if (this->size() == this->capacity())
        {
            this->increment_capacity();
            this->Modify_data();
        }
        increment_size();
        for (int i = this->size() - 1; i > index; i++)
        {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = item;
    }

    template<typename T>
    void Vector<T>::pop_back(){ // o(1)
        if(this->size() == 0){
            throw runtime_error("there is no elements in vector to pop!");
        }
        this->data[this->size() - 1] = 0;
        decrement_size();
        this->resize();
    }

    template<typename T>
    void Vector<T>::Delete(int index){ // o(n)
        if(index < 0 || index >= this->size()){
            throw out_of_range("Index is out of the range!");
        }
        for(int i = index; i < this->size() - 2;i++){
            // Shifting all trailing elements to the left
            this->data[i] = this->data[i + 1];
        }
        // Decrease the size of the Vector after deleting the element !
        this->decrement_size();
        this->resize();
    }

    template<typename T>
    void Vector<T>::remove(T item){ // o(n)
        int index = 0;
        while(index < this->size()){
            if(this->data[index] == item){
                // Call function Delete(index): so it will erase the element at the position (index)
                this->Delete(index);
            }
            else ++index;
        }
    }

    template<typename T>
    void Vector<T>::find(T item){ // o(n)
        // the first index of the match item otherwise it will be (-1) !
        int first_index = -1;
        for(int i = 0; i < this->size();i++){
            if(this->data[i] == item){
                first_index = i;
                break;
            }
        }
        return first_index;
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] this->data;
        this->data = nullptr;
    }

} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_VECTOR_H
