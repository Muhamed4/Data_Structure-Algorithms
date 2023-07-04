class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int frq[1002]{0};
        for(auto &it: arr){
            mp[it]++;
        }
        for(auto &it: mp){
            if(frq[it.second] >= 1)return false;
            frq[it.second]++;
        }
        return true;
    }
};