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
        // Parameterless (default) constructor
        Vector();
        // parameterized constructor (takes the size of the Vector)
        Vector(int _size);
        // Destructor to delete the dynamic allocation array (data)
        ~Vector();
        // member function to return the size of the Vector
        int size() const;
        // member function to return the capacity of the Vector
        int capacity() const;
        // member function to check if the Vector empty or not
        bool empty() const;
        // member function to return item at given index, blows up if index out of bounds
        T& at(int index);
        // To push element of type T at the end of the Vector
        void push_back(T item);
        // To insert element of type T at index (index)
        void insert(int index, T item);
        // To Remove the last element of Vector
        void pop_back();
        // To delete item at index, shifting all trailing elements left
        void Delete(int index);
        // To looks for value and removes index holding it (even if in multiple places)
        void remove(T item);
        // To looks for value and returns first index with that value, -1 if not found
        int find(T item);

        // Operator Overloading

        // Make operator overloading to (=) and make Deep copy cause there is pointer and to not make the data to be deleted twice 
        Vector<T>& operator=(const Vector<T>& oth);
        
        // Make operator overloading to ([]) to access the elements and modifying the content of these positions
        T& operator[](int index);

    private:
        // Increment the size of the Vector
        void increment_size();
        // Decrement the size of the Vector
        void decrement_size();
        // Increment the capacity to double if the size of the Vector equal the capacity the Vector
        void increment_capacity();
        // If the size of the Vector equal the capacity of the Vector so make new dynamic allocation array and increase the capacity of the array and put the value into the new array and delete the old one and make the pointer (this->data) points at the new array
        void Modify_data();
        // resize(new_capacity) 
        // when you reach capacity, resize to double the size
        // when popping an item, if size is 1/4 of capacity, resize to half
        void resize();
    };

    // Implementation of all member functions :

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
    T& Vector<T>::at(int index)
    {
        if (index < 0 || index >= this->size())
        {
            throw std::out_of_range("Vector::_M_range_check: __n (which is " + std::to_string(index) + " >= this->size() (which is " +
                                    std::to_string(this->size()) + ")");
        }
        return (*this)[index];
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
            throw std::runtime_error("there is no elements in vector to pop!");
        }
        this->data[this->size() - 1] = 0;
        decrement_size();
        this->resize();
    }

    template<typename T>
    void Vector<T>::Delete(int index){ // o(n)
        if(index < 0 || index >= this->size()){
            throw std::out_of_range("Index is out of the range!");
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
    int Vector<T>::find(T item){ // o(n)
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


    // Make operator overloading to (=) and make Deep copy cause there is pointer and to not make the data to be deleted twice :(
    template<typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& oth){
        this->size_data = oth.size_data;
        this->capacity_data = oth.capacity_data;
        this->data = new T[this->capacity_data];
        for(int i = 0; i < this->size();i++){
            this->data[i] = oth.data[i];
        }
        return *this;
    }

    // Make operator overloading to ([]) to access the elements and modifying the content of these positions

    template<typename T>
    T& Vector<T>::operator[](int index){
        if(index < -1 || index >= this->size()){
            throw std::out_of_range("The index is out of the range of this Vector");
        }
        return this->data[index];
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] this->data;
        this->data = nullptr;
    }

} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_VECTOR_H
