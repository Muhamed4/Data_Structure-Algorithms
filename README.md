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
        - size : Number of elements.
        - capacity : Number of elements it can hold.
        - empty : Check if the vector is empty.
        - at(index) : return element at index, throw exception if index is out of bounds.
        - push_back(element) : push element at the end of the vector.
        - insert(element, index) : insert item at a given index and shift that index's value and trailing elements to the right (throw exception if index is out of bounds).
        - pop_back() : remove the last element.
        - erase(index) : remove element at a given index and shift all trailing elements to the left (throw exception if index is out of bound).
        - erase(element) : remove all elements that equal this given element and shift all trailing elements to the left.
        - find(element) : Looks for value and returns first index with that value, -1 if not found.
        - front() : return the first element (throw exception if vector is empty).
        - back() : return the last element (throw exception if vector is empty).
- [Data Structure 2](link/to/folder): Brief description of the data structure and its applications.
- ...

## Solved Problems

- [Problem 1](link/to/problem): Description of the problem and the solution implemented.
- [Problem 2](link/to/problem): Description of the problem and the solution implemented.
- ...

## Contributing

If you'd like to contribute or have suggestions for improvements, feel free to open an issue or submit a pull request. Contributions are welcome!

