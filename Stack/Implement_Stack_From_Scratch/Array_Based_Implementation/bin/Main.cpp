#include <bits/stdc++.h>
#include "../include/Stack.hpp"
using DSA::Stack;
using namespace std;


int main(){
    Stack<int>st;
    st.push(2);
    st.push(3);
    st.push(6);
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}