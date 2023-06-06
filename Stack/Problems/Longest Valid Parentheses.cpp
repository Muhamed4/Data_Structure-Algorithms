class Solution {
    stack<int>st;
    string t = "";
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        for(int i = 0; i < n;i++){
            if(st.empty()){
                st.push(i);
                t += '#';
            }
            else{
                if(s[i] == '('){
                    t += '#';
                    st.push(i);
                }
                else {
                    if(s[st.top()] == '('){
                        t[st.top()] = '(';
                        t += ')';
                        st.pop();
                    }
                    else{
                        t += '#';
                        st.push(i);
                    }
                }
            }
        }
        int ans = 0, cnt = 0;
        for(int i = 0; i < n;i++){
            if(t[i] != '#')++cnt;
            else{
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

// )()())
// # () () #