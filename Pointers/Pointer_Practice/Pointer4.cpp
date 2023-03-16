#include<bits/stdc++.h>
using namespace std;

void Pointers_and_2D_Dimensional_Arrays(){
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int *p = b; // Compilation error
    // The type of a pointer matters not when you have to read the address. It matters when you derefrence or when you perform pointer arithmetic.
    int (*p)[3] = b; // Will return a pointer to 1-D array of 3 integers
    // cout << p << endl;
    // cout << b << endl;
    // cout << &b[0] << endl;
    // cout << *b << endl;
    // cout << p << endl;
    // cout << **b << endl;
    // cout << b[0] << endl;
    // cout << &b[0][0] << endl;
    // cout << b << endl;
    // cout << *b << endl;
    // cout << *(b + 1) << ' ' << &b[1] << ' ' << b[1] << endl;
    int a[] = {1, 2, 3};
    int *ptr = a;
    int (*ptr2)[3] = &a;
    // cout << *&a[0] << endl;
    // // cout << &a[0][0] << endl;
    // cout << ptr2 << ' ' << *ptr2 << ' ' << &a << endl;
    // cout << **ptr2 << ' ' << *ptr2[0] << ' ' << ptr2[0][0] << endl;
    // b[i][j] = *(b[i] + j) = *(*(b + i) + j);
    cout << (b[1] + 1) << endl;
    cout << &b[1][1] << endl;
    cout << b[1] << ' ' << *(b + 1) << ' ' << &b[0][1] << endl;
    cout << ((b + 1) + 2) << endl;
}

void Receive_1D(int *ptr, int size){
    for(int i = 0 ; i < size;i++){
        cout << *(ptr + i) << ' ';
    }
    cout << endl;
}

void Receive_2D(int (*ptr)[3], int size){
    for(int i = 0;i < size;i++){
        for(int j = 0 ; j < 3;j++){
            cout << *(*(ptr + i) + j) << ' ';
        }
        cout << endl;
    }
}

void Receive_3D(int (*ptr)[2][2], int size){
    for(int i = 0 ;i < size;i++){
        for(int j = 0 ; j < 2;j++){
            for(int k = 0 ; k < 2;k++){
                cout << *(*(*(ptr + i) + j) + k) << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Receive_3D1(int ***ptr, int size1, int size2, int size3){
    for(int i = 0 ; i < size1 * size2 * size3;i++){
        cout << ***ptr << ' ';
        **ptr++;
    }
    cout << endl;
}

void Pointers_and_Multi_Dimensional_Arrays(){
    int a[] = {1, 2, 3};
    int B[2][3] = {{1, 2, 3}, {6, 7, 8}};
    int (*ptr)[3] = B; // Declaring a pointer to 1-D array to 3 integers
    int (*p)[3] = &B[0];
    p++;
    // cout << *p[0] << endl;
    // cout << p << ' ' << B[0] << endl;
    // cout << &B[0] << endl;

    int c[3][2][2] = {{{1, 2} , {4, 5}}, {{7, 9}, {9, 2}}, {{2, 3}, {1, 2}}};
    //cout << *c << ' ' << c[0] << ' ' << ' ' << &c[0][0] << endl;
    // c[i][j][k] = *(c[i][j] + k) = *(*(c[i] + j) + k) = *(*(*(c + i) + j) + k)
    // Receive_1D(a, 3);
    // Receive_2D(B, 2);
    // Receive_3D(c, 3);
    // Receive_3D1(***c, 3, 2, 2); // This is wrong
}

int main(){

    // Pointers_and_2D_Dimensional_Arrays();

    // Pointers_and_Multi_Dimensional_Arrays();



    return 0;
}