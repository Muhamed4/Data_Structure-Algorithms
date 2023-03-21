#include<bits/stdc++.h>
using namespace std;

void Pointers_and_Dynamic_Memory(){
    // Memory can be divided into 4 segments
    int *p = (int*)malloc(sizeof(int)); // malloc it return a void pointer
    // cout << p << endl;
    free(p);
    p = (int*)malloc(20 * sizeof(int)); // It will reserve a 20 elements in the heap
    for(int i = 0 ; i < 20;i++){
        //*(p + i) = i + 1;
        p[i] = i + 1;
    }
    // for(int i = 0 ; i < 20;i++){
    //     cout << *(p + i) << ' ';
    // }
    // cout << '\n';
    // If malloc is not able to find any free block of memory is not able to allocate some memory on the heap, it returns null
    int *ptr = new int(10);
    *ptr = 11;
    delete ptr;
    // cout << *ptr << endl;
    ptr = new int[20];
    for(int i = 0 ; i < 20;i++){
        *(ptr + i) = i + 1;
        ptr[i] = i + 1;
    }
    for(int i = 0 ; i < 20;i++){
        cout << *(ptr + i) << ' ';
        // cout << p[i] << ' ';
    }
    cout << endl;
    delete[] ptr;
}

void Malloc_Calloc_Realloc_Free(){
    // They allocate a block of memory on the heap
    // malloc 
    // calloc
    // realloc
    // deallocate block of memory
    // free
    int n = 5;//cin >> n;
    bool *ptr = (bool*)malloc(n);
    //cout << sizeof(size_t) << endl;
    //ptr = (int*)5;
    *ptr = 5;
    // for(int i = 0; i < 5;i++){
    //     cout << *(ptr + i) << endl;
    // }
    // calloc: it returns a void pointer , it takes two argumnet, the first argument is the number of elements of a prticular data type, the second argumnet is the size of the data type.
    int *p = (int*)calloc(3, sizeof(int)); // if we don't provide it with a value, the default value will be zero

    // realloc: if we have a block of memory, dynamically allocated block of memory and we want to change the size of this block of memory, then we can use realloc
    // It takes two argumnet, the first argument is the starting addressing of the existing address, the second argument is the new size of the block.

    //cin >> n;
    //int* pt = (int*)malloc(n * sizeof(int));
    //int *pt = new int[n];
    //cout << sizeof(bool) << endl;
    bool *pt = (bool*)calloc(n, sizeof(int));
    char* c = (char*)pt;
    for(int i = 0 ; i < n;i++){
        // pt[i] = i + 1; 
        c[i] = i + 1;
        // They both have a size of 1 byte but when the compiler dereference the pointer, they are different.
    }
    free(c);
    c = nullptr; // It is a good practice to use it, otherwise i can access the address memory even after i deleted it. 
    //*c = 6;
    for(int i = 0 ; i < 20 /** sizeof(int)*/;i++){
        //cout << (int)*(c + i) << ' ';
    }
    bool* b = new bool(1);
    b[1] = 1;
    // cout << *(b + 0) << endl;
    // cout << *(b + 9) << endl;
    // cout << sizeof(size_t) << endl;

    int *A = (int*)malloc(n * sizeof(int));
    for(int i = 0 ; i < n;i++){
        A[i] = (i + 1);
    }
    int *B = (int*)realloc(A, 10); // equivalent to free(A).
    // if we want to reallocate larger size then if there a consecutive elements for the other values it will be added next to the previous elements, otherwise it will find a new block with the new size and copied the previous valuse to the new block and deallocated the previous block.
    cout << A << endl;
    cout << B << endl;
    free(A);
    //free(B);

    int *C = (int*)realloc(nullptr, n * sizeof(int)); // equivalent to malloc, it creates new block without copied anything.
    cout << C << endl;
}

int main(){

    // Pointers_and_Dynamic_Memory();

    // Malloc_Calloc_Realloc_Free();

    return 0;
}