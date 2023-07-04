class Solution {
public:
    vector<int> twoSum(vector<int>& v, int n) {
        unordered_map<int,int>ump;
        vector<int>ans;
        int _size = (int)v.size();
        for(int i = 0; i < _size;i++){
            int x = n - v[i];
            if(ump.count(x)){
                // ans = {ump[x], i};
                ans.push_back(ump[x]);
                ans.push_back(i);
                return ans;
            }
            ump[v[i]] = i;
        }
        return ans;
    }
};