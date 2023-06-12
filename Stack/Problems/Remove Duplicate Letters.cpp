class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        map<char,int>mp, vis;
        stack<char>st;
        for(auto &it: s)mp[it]++;
        for(auto &it: s){
            while(!st.empty() && it < st.top() && mp[st.top()] > 0 && vis[it] == 0){
                vis[st.top()]--;
                st.pop();
            }
            if(vis[it] == 0){
                st.push(it);
                vis[it]++;
            }
            mp[it]--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};