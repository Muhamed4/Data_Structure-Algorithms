class Solution {
    vector<string>res;
    void solve(int idx, vector<string>&ans, string cnt){
        if(idx == (int)ans.size()){
            if(cnt.size())res.push_back(cnt);
            return;
        }
        for(auto &it: ans[idx]){
            cnt += it;
            solve(idx + 1, ans, cnt);
            cnt.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>st;
        st[2] = "abc";st[3] = "def";st[4] = "ghi"; st[5] = "jkl";
        st[6] = "mno";st[7] = "pqrs";st[8] = "tuv";st[9] = "wxyz";
        vector<string>ans;
        for(int i = 0 ; i < digits.size();i++){
            ans.push_back(st[digits[i] - '0']);
        }
        solve(0, ans, string());
        return res;
    }
};