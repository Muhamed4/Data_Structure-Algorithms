class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums2.size();
        stack<int>st;
        vector<int>right(n), ans;
        for(int i = n - 1; i >= 0;i--){
            if(st.empty()){
                st.push(i);
                right[i] = -1;
            }
            else{
                while(!st.empty() && nums2[i]  >= nums2[st.top()]){
                    st.pop();
                }
                if(st.empty()) right[i] = -1;
                else right[i] = st.top();
                st.push(i);
            }
        }
        map<int,int>mp;
        for(int i = n - 1; i >= 0;i--){
            mp[nums2[i]] = ((right[i] == -1) ? -1 : nums2[right[i]]);
        }
        for(auto &it: nums1){
            if(mp.count(it) == 0){
                ans.push_back(-1);
            }
            else ans.push_back(mp[it]);
        }
        return ans;
    }
};