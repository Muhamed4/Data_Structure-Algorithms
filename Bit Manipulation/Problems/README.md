

* [ ] [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int countBits(int n) {
                    int cnt = 0;
                    while(n) {
                        n &= (n - 1);
                        cnt += 1;
                    }
                    return cnt;
                }
            public:
                int minBitFlips(int start, int goal) {
                    int _xor = (start ^ goal);
                    return countBits(_xor);
                }
            };
        
    </details>

---


* [ ] [XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
                    int n = arr.size();
                    int t = queries.size();
                    int _xor = 0;
                    vector<int> _xorPrefix(n), res;
                    for(int i = 0; i < n;i++) {
                        _xor = (_xor ^ arr[i]);
                        _xorPrefix[i] = _xor;
                    }
                    for(int i = 0; i < t;i++) {
                        int left = queries[i][0], right = queries[i][1];
                        int result = (_xorPrefix[right] ^ (left == 0 ? 0 : _xorPrefix[left - 1]));
                        res.push_back(result);
                    }
                    return res;
                }
            };
        
    </details>

---


* [ ] [Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int longestSubarray(vector<int>& nums) {
                    int n = nums.size();
                    int maxLen = 0;
                    int mx = 0, cnt = 0;
                    for(auto &it: nums)
                        mx = max(mx, it);
                    for(int i = 0 ; i < n;i++) {
                        if(nums[i] == mx) cnt += 1;
                        else cnt = 0;
                        maxLen = max(maxLen, cnt);
                    }
                    return maxLen;
                }
            };
        
    </details>

---


* [ ] [Find the Longest Substring Containing Vowels in Even Counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int findTheLongestSubstring(string s) {
                    int n = s.size();
                    int mask = 0, res = 0;
                    unordered_map<int, int> vis;
                    vis[0] = 0;
                    for(int i = 0; i < n;i++) {
                        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                            mask ^= (1 << (s[i] - 'a'));
                        if(vis.count(mask) == false)
                            vis[mask] = i;
                        res = max(res, i - vis[mask] + (mask == 0));
                    }
                    return res;
                }
            };
        
    </details>

---