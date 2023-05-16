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

    private:
        void increment_size();
        void increment_capacity();
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

    template <typename T>
    void Vector<T>::push_back(T item)
    {
        if (this->size() == this->capacity())
        {
            this->increment_capacity();
            T new_data = new T[this->capacity()];
            for (int i = 0; i < this->size(); i++)
            {
                new_data[i] = this->data[i];
            }
            delete[] this->data;
            this->data = new_data;
            new_data = nullptr;
        }
        this->data[this->size()] = item;
        this->increment_size();
    }

    template <typename T>
    void Vector<T>::increment_size()
    {
        ++this->size_data;
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
            T new_data = new T[this->capacity()];
            for (int i = 0; i < this->size(); i++)
            {
                new_data[i] = this->data[i];
            }
            delete[] this->data;
            this->data = new_data;
            new_data = nullptr;
        }
        increment_size();
        for (int i = this->size() - 1; i > index; i++)
        {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = item;
    }

    template <typename T>
    Vector<T>::~Vector()
    {
    }

} // DSA

#endif // DATA_STRUCTURE_IMPLEMENTATION_VECTOR_H
