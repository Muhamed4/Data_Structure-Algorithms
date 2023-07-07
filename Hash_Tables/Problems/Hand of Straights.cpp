class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int)hand.size();
        if(n % groupSize != 0)return false;

        unordered_map<int,int>mp;
        set<int>st;
        for(auto &it: hand){
            mp[it]++;
            st.insert(it);
        }
        
        bool flag = true;
        for(auto &it: st){
            while(mp[it]){
                for(int i = it; i < it + groupSize;i++){
                    if(mp[i] == 0){
                        flag = false;
                        break;
                    }
                    mp[i]--;
                }
                if(!flag)break;
            }
            if(!flag)break;
        }
        return flag;
    }
};