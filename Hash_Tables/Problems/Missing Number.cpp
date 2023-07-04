class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int,int>mp;
        for(auto &it: nums)mp[it]++;
        int ans = 0;
        for(int i = 0; i <= n;i++){
            if(mp.count(i) == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};