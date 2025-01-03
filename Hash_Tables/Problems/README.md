* [ ] [Two Sum](https://leetcode.com/problems/two-sum/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> twoSum(vector<int>& nums, int target) {
                    int n = nums.size();
                    vector<int> res;
                    unordered_map<int, int> mp;
                    for(int i = 0; i < n;i++){
                        if(mp.count(target - nums[i]) == 1) {
                            res = {mp[target - nums[i]], i};
                            break;
                        }
                        mp[nums[i]] = i;
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                bool isAnagram(string s, string t) {
                    unordered_map<char, int>mp;
                    for(auto &ch: s) mp[ch]++;
                    for(auto &ch: t) {
                        mp[ch]--;
                        if(mp[ch] == 0) mp.erase(ch);
                    }
                    return mp.empty();
                }
            };
        
    </details>

---



* [ ] [Buddy Strings](https://leetcode.com/problems/buddy-strings/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                bool buddyStrings(string s, string goal) {
                    int n = s.size(), m = goal.size();
                    if(n != m) 
                        return false;
                    vector<int> indexs;
                    unordered_map<char, int> frq;
                    bool same = false;
                    int dif = 0;
                    for(int i = 0; i < n;i++) {
                        frq[s[i]]++;
                        if(frq[s[i]] > 1) same = true;
                        if(s[i] != goal[i]) {
                            ++dif;
                            indexs.push_back(i);
                        }
                    }
                    if(dif != 2 && dif != 0) return false;
                    else if(dif == 0 && same == true) return true;
                    else if(dif == 0) return false;
                    swap(s[indexs[0]], s[indexs[1]]);
                    return s == goal;
                }
            };
        
    </details>

---



* [ ] [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                bool uniqueOccurrences(vector<int>& arr) {
                    unordered_map<int,int>mp;
                    int frq[1002]{0};
                    for(auto &it: arr)mp[it]++;
                    for(auto &it: mp){
                        if(frq[it.second] >= 1)return false;
                        frq[it.second]++;
                    }
                    return true;
                }
            };
        
    </details>

---




* [ ] [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
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
        
    </details>

---




* [ ] [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                bool containsNearbyDuplicate(vector<int>& nums, int k) {
                    int n = nums.size();
                    unordered_map<int, int> hash;
                    for(int i = 0; i < n;i++) {
                        if(hash.count(nums[i]) && (i - hash[nums[i]]) <= k) return true;
                        hash[nums[i]] = i;
                    }
                    return false;
                }
            };
        
    </details>

---



* [ ] [Missing Number](https://leetcode.com/problems/missing-number/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
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
        
    </details>

---



* [ ] [Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<vector<string>> groupAnagrams(vector<string>& strs) {
                    vector<vector<string>> res;
                    unordered_map<string, vector<string>> mp;
                    for(auto &str: strs) {
                        string cop = str;
                        sort(cop.begin(), cop.end());
                        mp[cop].push_back(str);
                    }
                    for(auto &it: mp) res.push_back(it.second);
                    return res;
                }
            };
        
    </details>

---



* [ ] [Hand of Straights](https://leetcode.com/problems/hand-of-straights/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
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
        
    </details>

---




* [ ] [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int findDuplicate(vector<int>& nums) {
                    unordered_map<int,int>mp;
                    for(auto &it: nums)mp[it]++;
                    int ans = 0;
                    for(auto &it: mp){
                        if(it.second >= 2){
                            ans = it.first;
                            break;
                        }
                    }
                    return ans;
                }
            };
        
    </details>

---




* [ ] [Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void assign(unordered_map<int, string>& hash, set<int>&st) {
                    hash[1] = "I";
                    hash[5] = "V";
                    hash[10] = "X";
                    hash[50] = "L";
                    hash[100] = "C";
                    hash[500] = "D";
                    hash[1000] = "M";
                    hash[4] = "IV";
                    hash[9] = "IX";
                    hash[40] = "XL";
                    hash[90] = "XC";
                    hash[400] = "CD";
                    hash[900] = "CM";
                    st = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
                }
            public:
                string intToRoman(int num) {
                    unordered_map<int, string> hash;
                    set<int>st;
                    string res = "";
                    assign(hash, st);
                    while(num) {
                        auto it = st.upper_bound(num);
                        int n = *prev(it);
                        res += hash[n];
                        num -= n;
                    }
                    return res;
                }
            };
            
    </details>

---




* [ ] [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void backTrack(int idx, int& n, string digits, string cur, vector<string>& res, unordered_map<char, vector<char>>&mp) {
                    if(idx == n) {
                        if(!cur.empty()) res.push_back(cur);
                        return;
                    }
                    for(auto& ch: mp[digits[idx]]) {
                        backTrack(idx + 1, n, digits, cur + ch, res, mp);
                    }
                }
                void assign(unordered_map<char, vector<char>>&mp) {
                    char cur = '2', idx = 'a';
                    while((cur - '0') < 10) {
                        mp[cur] = {idx, char(idx + 1), char(idx + 2)};
                        idx += 3;
                        if((cur - '0') == 7 || (cur - '0') == 9) mp[cur].push_back(idx++);
                        ++cur;
                    }
                }
            public:
                vector<string> letterCombinations(string digits) {
                    int n = digits.size();
                    vector<string> res;
                    unordered_map<char, vector<char>> mp;
                    assign(mp);
                    backTrack(0, n, digits, "", res, mp);
                    return res;
                }
            };
        
    </details>

---



* [ ] [Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int mod = 1e9 + 7;
                int fpow(int n, int x) {
                    if(x == 0) return 1;
                    if(x == 1) return n;
                    int ans = fpow(n, x / 2) % mod;
                    ans = 1ll*(ans % mod) * (ans % mod);
                    if(x & 1) ans = 1ll*(ans % mod) * (n % mod);
                    return ans % mod;
                }
                int hashable(vector<int>& v) {
                    int n = v.size();
                    int hashed = 0;
                    for(int i = 0; i < n;i++) {
                        hashed = (hashed % mod) + (1ll*v[i] * (fpow(10, i) % mod));
                        hashed %= mod;
                    }
                    return hashed % mod;
                }
            public:
                int equalPairs(vector<vector<int>>& grid) {
                    int n = grid.size();
                    int m = grid[0].size();
                    int res = 0;
                    unordered_map<int, int> hash;
                    for(int i = 0; i < n;i++) {
                        int hashed = hashable(grid[i]);
                        hash[hashed] += 1;
                    }
                    for(int i = 0; i < m;i++) {
                        vector<int> col;
                        for(int j = 0; j < n;j++)
                            col.push_back(grid[j][i]);
                        int hashed = hashable(col);
                        if(hash.count(hashed) == true)
                            res += hash[hashed];
                    }
                    return res;
                }
            };
        
    </details>

---




* [ ] [Clone Graph](https://leetcode.com/problems/clone-graph/)
    * <details>
        <summary> Solution </summary>

        ```c++
            /*
            // Definition for a Node.
            class Node {
            public:
                int val;
                vector<Node*> neighbors;
                Node() {
                    val = 0;
                    neighbors = vector<Node*>();
                }
                Node(int _val) {
                    val = _val;
                    neighbors = vector<Node*>();
                }
                Node(int _val, vector<Node*> _neighbors) {
                    val = _val;
                    neighbors = _neighbors;
                }
            };
            */

            class Solution {
                Node* dfs(Node* node, unordered_map<Node*, Node*>& clone) {
                    if(node == nullptr) return nullptr;
                    Node* root = new Node(node->val);
                    clone[node] = root;
                    for(auto &child: node->neighbors) {
                        if(clone.count(child) == false)
                            dfs(child, clone);
                    }
                    for(auto &child: node->neighbors)
                        root->neighbors.push_back(clone[child]);
                    return root;
                }
            public:
                Node* cloneGraph(Node* node) {
                    unordered_map<Node*, Node*> clone;
                    return dfs(node, clone);
                }
            };
        
    </details>

---




* [ ] [Longest Sub-Array with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?page=1&sortBy=submissions)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int lenOfLongestSubarr(vector<int>& arr, int k) {
                    // code here
                    int n = arr.size(), sum = 0, res = 0;
                    unordered_map<int, int> index;
                    index[0] = -1;
                    for(int i = 0; i < n;i++) {
                        sum += arr[i];
                        int diff = sum - k;
                        if(index.count(diff) == true)
                            res = max(res, i - index[diff]);
                        if(index.count(sum) == false)
                            index[sum] = i;
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maxCount(vector<int>& banned, int n, int maxSum) {
                    int res = 0, sum = 0;
                    unordered_map<int, bool> vis;
                    for(auto &ban: banned)
                        vis[ban] = true;
                    for(int i = 1; i <= n;i++) {
                        if(vis.count(i) == false && sum + i <= maxSum) {
                            sum += i;
                            res += 1;
                        }
                    }
                    return res;
                }
            };
        
    </details>

---