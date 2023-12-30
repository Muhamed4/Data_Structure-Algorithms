# Data Structures and Algorithms

This repository serves as a collection of my studies in data structures and algorithms. Each folder corresponds to a specific topic, containing both theoretical explanations and practical implementations.

## Table of Contents

1. [Introduction](#introduction)
2. [Folder Structure](#folder-structure)
3. [Implemented Data Structures](#implemented-data-structures)
4. [Solved Problems](#solved-problems)
5. [Contributing](#contributing)

## Introduction

In this repository, I've documented my journey of learning data structures and algorithms. My goal is to provide clear explanations, implementations, and real-world problem-solving examples.

## Folder Structure

- Each folder represents a distinct data structure or algorithm.
- Inside each folder, you'll find:
  - `implementation`: Source code with explanations for the implementation of the data structure or algorithm.
  - `problems`: Solutions to problems related to the respective data structure or algorithm, often sourced from platforms like LeetCode.

## Implemented Data Structures

- [vector](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Array/Implement_Vector_From_Scratch/include/Vector.hpp) : Implementing a generic vector data structure using dynamic allocation of array and it's support these functionality
    - `implementation`:
        - size() : Number of elements.
        - capacity() : Number of elements it can hold.
        - empty() : Check if the vector is empty.
        - at(index) : return element at index, throw exception if index is out of bounds.
        - push_back(element) : push element at the end of the vector.
        - insert(element, index) : insert item at a given index and shift that index's value and trailing elements to the right (throw exception if index is out of bounds).
        - pop_back() : remove the last element.
        - erase(index) : remove element at a given index and shift all trailing elements to the left (throw exception if index is out of bound).
        - erase(element) : remove all elements that equal this given element and shift all trailing elements to the left.
        - find(element) : Looks for value and returns first index with that value, -1 if not found.
        - front() : return the first element (throw exception if vector is empty).
        - back() : return the last element (throw exception if vector is empty).
- [Singly Linked List](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Linked_List/Implement_Linked_List_From_Scratch/Singly_Linked_List/include/Linked_List.hpp): Implementation of a generic singly linked list using pointers and dynamic allocation.

- [Doubly Linked List](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Linked_List/Implement_Linked_List_From_Scratch/Doubly_Linked_List/include/Linked_List.hpp): Implementation of a generic doubly linked list using pointers and dynamic allocation.
    - Two Data structure support the same functionality but different implementations.
    - `implementation`:
        -  size() : returns number of data elements in list.
        -  empty() - check if the linked list is empty or not (returns bool).
        -  valueAt(index) : return the value of the nth item (0 based index).
        -  push_front(element) : Adding element to the front of the list.
        -  pop_front() : Removing element from the front of the list.
        -  push_back() : Adding element to the back of the list.
        -  pop_back() : Removing element from the back of the list.
        -  front() : return the first element of the list.
        -  back() : return the last element of the list.
        -  insert(index, element) : Reach the given index at the list and insert the given element with considering the links between the pointers and fix them.
        -  erase(index) : Remove element from the list at the given index.
        -  valueNfromEnd(n) : returns the value of the node at nth position from the end of the list.
        -  reverse() : Reversing the whole list.
        erase(element) : Remove the first element in the list with this value.
        -  getValue(index) : Get the value from the node at this index.

## Solved Problems

- [Problem 1](link/to/problem): Description of the problem and the solution implemented.
- [Problem 2](link/to/problem): Description of the problem and the solution implemented.
- ...

## Contributing

If you'd like to contribute or have suggestions for improvements, feel free to open an issue or submit a pull request. Contributions are welcome!

