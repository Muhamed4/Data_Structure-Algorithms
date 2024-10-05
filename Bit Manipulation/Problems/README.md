

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


* [ ] [Find a Value of a Mysterious Function Closest to Target](https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void buildBits(int n, vector<vector<int>>& bitPrefix, vector<int> arr) {
                    for(int i = 0; i < n;i++) {
                        int idx = 0;
                        while(arr[i] > 0) {
                            bitPrefix[i][idx] = (arr[i] & 1);
                            arr[i] >>= 1;
                            idx += 1;
                        }
                    }

                    for(int i = 0; i < 30;i++) {
                        for(int j = 1; j < n;j++)
                            bitPrefix[j][i] += bitPrefix[j - 1][i];
                    }
                }

                int getClosestNumLessThanOrEqualTarget(vector<vector<int>>& bitPrefix, int n, int target) {
                    int mnAND = -1E9;
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, res = -1E9;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cur = 0, len = mid - i + 1;
                            for(int j = 0; j < 30;j++) {
                                int sum = bitPrefix[mid][j] - (i == 0 ? 0 : bitPrefix[i - 1][j]);
                                if(len == sum)
                                    cur |= (1 << j);
                            }
                            if(cur <= target) {
                                res = cur;
                                right = mid - 1;
                            }
                            else left = mid + 1;
                        }
                        mnAND = max(mnAND, res);
                    }
                    return mnAND;
                }

                int getClosestNumGreaterThanOrEqualTarget(vector<vector<int>>& bitPrefix, int n, int target) {
                    int mxAND = 1E9;
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, res = 1E9;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cur = 0, len = mid - i + 1;
                            for(int j = 0; j < 30;j++) {
                                int sum = bitPrefix[mid][j] - (i == 0 ? 0 : bitPrefix[i - 1][j]);
                                if(len == sum)
                                    cur |= (1 << j);
                            }
                            if(cur >= target) {
                                res = cur;
                                left = mid + 1;
                            }
                            else right = mid - 1;
                        }
                        mxAND = min(mxAND, res);
                    }
                    return mxAND;
                }
            public:
                int closestToTarget(vector<int>& arr, int target) {
                    int n = arr.size();
                    int mnAND = -1E9, mxAND = 1E9;
                    vector<vector<int>> bitPrefix(n, vector<int>(30));
                    buildBits(n, bitPrefix, arr);
                    int mnValue = getClosestNumLessThanOrEqualTarget(bitPrefix, n, target);
                    int mxValue = getClosestNumGreaterThanOrEqualTarget(bitPrefix, n, target);
                    int closest = min(mxValue - target, target - mnValue);
                    return closest;
                }
            };

            /*

                011 --> 3 
                101 --> 5
                111 --> 7
                1000 --> 8
                1001 --> 9

                when applying AND for (x & y) the number will be less than or equal to the minimum between them

            */
        
    </details>

---