class Solution {

    void comp1(vector<int>&height, vector<int>&left, stack<int>&st1, int n){
        st1.push(height[0]);
        for(int i = 1; i < n;i++){
            if(height[i] > st1.top()){
                st1.pop();
                st1.push(height[i]);
            }
            left[i] = st1.top();
        }
    }

    void comp2(vector<int>&height, vector<int>&right, stack<int>&st2, int n){
        st2.push(height[n - 1]);
        for(int i = n - 2;i >= 0;i--){
            if(height[i] > st2.top()){
                st2.pop();
                st2.push(height[i]);
            }
            right[i] = st2.top();
        }
    }
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if(n <= 2)return 0;
        stack<int>st1, st2;
        vector<int>left(n), right(n);
        
        comp1(height, left, st1, n);
        comp2(height, right, st2, n);
        
        int ans = 0;
        for(int i = 1; i < n - 1;i++){
            ans += abs(height[i] - min(left[i], right[i]));
        }
        return ans;
    }
};