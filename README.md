# Data Structures and Algorithms

This repository serves as a collection of my studies in data structures and algorithms. Each folder corresponds to a specific topic, containing both theoretical explanations and practical implementations.

## Table of Contents

1. [Introduction](#introduction)
2. [Folder Structure](#folder-structure)
3. [Implemented Data Structures](#implemented-data-structures)
4. [Solved Problems](#solved-problems)
5. [Materials](#materials)
6. [Competitive Programming](#competitive-programming)
7. [Contributing](#contributing)

## Introduction

In this repository, I've documented my journey of learning data structures and algorithms. My goal is to provide clear explanations, implementations, and real-world problem-solving examples.

## Folder Structure

- Each folder represents a distinct data structure or algorithm.
- Inside each folder, you'll find:
  - `implementation`: Source code with explanations for the implementation of the data structure or algorithm.
  - `problems`: Solutions to problems related to the respective data structure or algorithm, often sourced from platforms like LeetCode.
  - `materials`: Educational resources, references, and learning materials related to the specific data structure or algorithm.

## Implemented Data Structures

- [Vector](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Array/Implement_Vector_From_Scratch/include/Vector.hpp) : Implementing a generic vector data structure using dynamic allocation of array and it's support these functionality
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

- [Hash Table (Chaining Method)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Hash_Tables/Implement_Hash_Table/include/HashMapChain.hpp): Implementation of a generic hash table with key and value using chaining method.

- [Hash Table (Open Addressing Method)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Hash_Tables/Implement_Hash_Table/include/HashMap_OpenAddressing.hpp): Implementation of a generic hash table with key and value using open addressing method.
    - Two Data Structure support the same functionality but different implementations.
    - `implementation`:
        - add(key, value) : Add the key and value to the hash table.
        - exist(key) : Check if this key exists in the hash table.
        - get(key) : Get the value of the key.
        - remove(key) : Remove this key from the hash table.

- [Binary Search Tree](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Trees/Binary_Tree/Implement_Tree/include/Binary_Search_Tree.hpp): Implementation of a generic Binary Search Tree.
    - `implementation`:
        - insert(element) : Insert new element into tree.
        - count(element) : Count the number of items equal to this element in the tree.
        - clear() : Clear all the tree.
        - find(element) : return true if the element exists in the tree otherwise return false.
        - getHeight() : Return the height of the tree.
        - getMin() : Return the minimum number of items in the tree.
        - getMax() : Return the maximum number of items in the tree.
        - isBinarySearchTree() : Check if this is a binary search tree or not.
        - erase(element) : delete all the items equal to this element.
        - print() : Print the tree in any ordered (Pre-Order, In-Order, Post-Order).

- [Binary Heap](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Trees/Heap_PriorityQueue_BinaryHeap/Implement_Binary_Heap/include/Binary_Heap.hpp): Implementation of a generic Binary Heap, Trying to simulate Priority_Queue and it's finctionality using vector as the container for the Priority_Queue and making the comparator as a generic type so you can use any comparator you want according to your usage and satisfies the heap property.
    - `implementation`:
        - empty() : Check if the Priority_Queue is empty or not.
        - size() : Return the size of the Priority_Queue.
        - push(element) : Push element to the Priority_Queue.
        - pop() : Pop the root element from the Priority_Queue.
        - top() : Return the root element of the Priority_Queue.

- [Stack (Array Based Implementation)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Stack/Implement_Stack_From_Scratch/Array_Based_Implementation/include/Stack.hpp): Implementation of a generic stack (Array Based Implementation) using dynamic allocation of array.

- [Stack (Linked List Based Implementation)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Stack/Implement_Stack_From_Scratch/Array_Based_Implementation/include/Stack.hpp): Implementation of a generic stack (Linked List Based Implementation) using pointers dynamic allocation.
    - Two Data Structure support the same functionality but different implementations.
    - `implementation`:
        - size() : returns number of data elements in stack.
        - empty() : Check if the stack is empty or not.
        - push(element) : Addint element at the top of the stack.
        - pop() : pop the top element of the stack.
        - top() : return the top element of the stack.

- [Queue (Circular Array Base Implementation)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Queue/Implement_Queue_From_Scratch/Queue_With_Circular_Array/include/Queue.hpp): Implementation of a generic Queue (Circular Array) using a fixed size array.

- [Queue (Linked List Base Implementation)](https://github.com/Muhamed4/Data_Structure-Algorithms/blob/master/Queue/Implement_Queue_From_Scratch/Queue_With_Circular_Array/include/Queue.hpp): Implementation of a generic Queue (Linked List Base Implementation) using pointers and dynamic allocation.

    - Two Data Structure support the same functionality but different implementations.
    - `implementation`:
        - size() : return the number of elements in the queue.
        - empty() : check if the queue is empty or not.
        - full() : check if the queue is full or not.
        - enqueue() : adds item at end of available storage.
        - dequeue() : remove least recently added item from the queue.
        - front() : return the first element from the queue.
        - back() : return the last element from the queue.
## Solved Problems

> This section includes solutions to various algorithmic problems sourced from platforms like `LeetCode` and `HackerEarth`. Each problem is accompanied by the implemented solution. These solutions demonstrate practical applications of the data structures and algorithms discussed in this repository.

- [Array & Vector](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Array/Problems)

- [Linked Lists](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Linked_List/Problems)

- [Hash Table](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Hash_Tables/Problems)

- [Binary Tree](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Trees/Binary_Tree/Problems)

- [Binary Heap](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Trees/Heap_PriorityQueue_BinaryHeap/Problems)

- [Stack](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Stack/Problems)

- [Queue](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Queue/Problems)

## Materials
> This section contains educational materials and resources that have been instrumental in my study of data structures and algorithms.

- [Array & Vector](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Array)

- [Linked List](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Linked_List)

- [Hash Table](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Hash_Tables)

- [Binary Tree](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Trees/Binary_Tree)

- [Binary Heap](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Trees/Heap_PriorityQueue_BinaryHeap)

- [Stack](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Stack)

- [Queue](https://github.com/Muhamed4/Data_Structure-Algorithms/tree/master/Queue)


## Competitive Programming

> This is not just my journey with data structure, algorithms and problem solving, I had a long journey with `competitive programming`, which i will explain it in the following section below.

Welcome to the `Competitive Programming` section of this repository! Competitive programming is a fascinating domain that combines problem-solving skills with programming prowess. In this section, I'll share insights into my journey in competitive programming, highlighting achievements and experiences gained along the way.

### Introduction

`Competitive programming` involves solving algorithmic challenges and computational problems within a specified time frame. It's not just about writing code; it's about crafting efficient solutions under time constraints. Whether you're a seasoned competitor or just starting, the world of competitive programming offers a unique opportunity to hone your skills, learn new techniques, and engage with a vibrant community of like-minded individuals.

### My Achievements

Over the journey of my `competitive programming`, I've had the privilege of achieving milestones and gaining valuable experiences. Here are some notable achievements:

- I have participated in [ICPC](https://en.wikipedia.org/wiki/International_Collegiate_Programming_Contest) competitions several times, you can find my ICPC profile here [Muhamed Morsi](https://icpc.global/ICPCID/TI7G73Z1791O), where I proudly showcase my achievements and journey in the `International Collegiate Programming Contest` (ICPC).
    - > What is [ICPC](https://en.wikipedia.org/wiki/International_Collegiate_Programming_Contest) ?
        - `The International Collegiate Programming Contest (ICPC)` is a premier global programming competition where university students from around the world engage in solving algorithmic challenges. It provides a platform to showcase problem-solving skills, teamwork, and programming proficiency. The thrill of tackling diverse problem sets and the invaluable lessons learned during these competitions significantly contribute to the growth of participants as programmers.

- I have reached the `Specialist`(Almost `Expert`) rank on [Codeforces](https://codeforces.com/), a testament to my dedication, perseverance, and love for algorithmic problem-solving.
With a track record of participation in over `135 online contests on Codeforces`, I've successfully tackled and conquered more than `+2500 problems`, spanning various difficulty levels and employing a diverse range of data structures and algorithms. You can explore my Codeforces profile here [Muhamed_Morsi](https://codeforces.com/profile/Muhamed_Morsi), where the journey from a novice to a Specialist unfolds.
    - > What is [Codeforces](https://codeforces.com/) ? 
        - `Codeforces` stands as a premier online competitive programming platform, hosting regular contests that challenge programmers worldwide.

#### All platforms I practice problems on : 
- [LeetCode](https://leetcode.com/Muhamed_Morsi/)
- [Codeforces](https://codeforces.com/profile/Muhamed_Morsi)
- [Hacker Earth](https://www.hackerearth.com/@Muhamed_Morsi)
- [Hacker Rank](https://www.hackerrank.com/profile/mohamedmorsi722)
    


## Contributing

If you'd like to contribute, have suggestions for improvements or find any wrongs in the implementations of data structures feel free to open an issue or submit a pull request. Contributions are welcome!

