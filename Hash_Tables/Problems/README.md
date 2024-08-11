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