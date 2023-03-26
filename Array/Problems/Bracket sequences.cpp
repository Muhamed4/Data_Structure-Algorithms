#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    string s;cin >> s;
    int n = (int)s.size();
    s += s;
    int ans = 0, l = 1, r = n;
    stack<int>st;
    for(int i = 0 ; i < 2 * n - 1;i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            if(s[st.top()] == '(' && s[i] == ')')st.pop();
            else st.push(i);
        }
        if(i == n - 1){
            if(st.empty())ans++;
        }
        else if(i >= n){
            if(st.empty())ans++;
            else if(st.top() < l)ans++;
            l++, r++;
        }
    }
    cout << ans << '\n';
}