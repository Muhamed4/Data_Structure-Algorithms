class Solution {
    const int mod = 1000000007;

    long long fpow(long long n, long long x) {
    if (x == 0) {
        return 1;
    }
    if (x == 1) {
        return n % mod;
    }
    long long ans = fpow(n, x / 2) % mod;
    ans = (ans % mod) * (ans % mod) % mod;
    if (x & 1) {
        ans = (ans % mod) * (n % mod) % mod;
    }
    return ans;
}
    long long Rabin_Karp(string s){
        long long ans = 0;
        for(int i = 0; i < s.size();i++){
            ans = (ans % mod) + (((s[i] - 'a' + 1) * (fpow(26, i) % mod)) % mod);
            ans %= mod;
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long,vector<string>>mp;
        for(auto &it: strs){
            string t = it;
            sort(t.begin(), t.end());
            long long hashIndex = Rabin_Karp(t);
            mp[hashIndex].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto &it: mp){
            ans.push_back(vector<string>());
            for(auto &itt: it.second){
                ans.back().push_back(itt);
            }
        }
        return ans;
    }
};

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa