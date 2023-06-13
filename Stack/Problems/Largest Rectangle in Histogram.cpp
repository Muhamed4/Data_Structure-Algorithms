class Solution {
    void fun1(vector<int>&v, vector<int>&left, int n){
        stack<int>st;
        for(int i = 0; i < n;i++){
            if(st.empty()){
                st.push(i);
                left[i] = 0;
                continue;
            }
            while(!st.empty() && v[i] <= v[st.top()])st.pop();
            if(st.empty())left[i] = 0;
            else left[i] = st.top() + 1;
            st.push(i);
        }
    }

    void fun2(vector<int>&v, vector<int>&right, int n){
        stack<int>st;
        for(int i = n - 1; i >= 0;i--){
            if(st.empty()){
                st.push(i);
                right[i] = n;
                continue;
            }
            while(!st.empty() && v[i] <= v[st.top()])st.pop();
            if(st.empty())right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& v) {
        int n = (int)v.size();
        vector<int>left(n), right(n);
        fun1(v, left, n);
        fun2(v, right, n);
        int ans = 0;
        for(int  i = 0 ;i < n;i++){
            ans = max(ans, (right[i] - left[i]) * v[i]);
        }
        return ans;
    }
};