class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it: nums){
            int x = ++mp[it];
            if(x >= 2)return true;
        }
        return false;
    }
};