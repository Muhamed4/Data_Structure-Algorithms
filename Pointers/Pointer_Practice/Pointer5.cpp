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
    for(int i = 0; i < 5;i++){
        cout << *(ptr + i) << endl;
    }
}

int main(){

    // Pointers_and_Dynamic_Memory();

    Malloc_Calloc_Realloc_Free();

    return 0;
}