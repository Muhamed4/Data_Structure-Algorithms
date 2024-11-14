

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



* [ ] [Minimize XOR](https://leetcode.com/problems/minimize-xor/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int countBits(int n) {
                    int cnt = 0;
                    while(n > 0) {
                        n &= (n - 1);
                        cnt += 1;
                    }
                    return cnt;
                }
            public:
                int minimizeXor(int num1, int num2) {
                    int cnt = countBits(num2), res = 0;
                    for(int i = 31; i >= 0 && cnt > 0;i--) {
                        int bit = (num1 >> i) & 1;
                        if(bit & 1) {
                            res |= (1 << i);
                            cnt -= 1;
                        }
                    }
                    for(int i = 0; i <= 31 && cnt > 0;i++) {
                        int bit = (res >> i) & 1;
                        if(!(bit & 1)) {
                            res |= (1 << i);
                            cnt -= 1;
                        }
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maximumXOR(vector<int>& nums) {
                    int n = nums.size(), totalXor = 0;
                    for(auto &it: nums) totalXor ^= it;
                    for(int i = 0; i < n;i++) {
                        int rem = totalXor ^ nums[i];
                        rem |= (rem ^ nums[i]);
                        totalXor = max(totalXor, rem);
                    }
                    return totalXor;
                }
            };
        
    </details>

---



* [ ] [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct Trie {
                Trie* children[2];
                Trie() {
                    children[0] = children[1] = nullptr;
                }
            };
            class Solution {
                void insert(Trie* root, int n) {
                    for(int i = 31; i >= 0;i--) {
                        bool bit = (n >> i) & 1;
                        if(root->children[bit] == nullptr)
                            root->children[bit] = new Trie();
                        root = root->children[bit];
                    }
                }

                int getMaxXor(Trie* root, int n) {
                    int res = 0;
                    bool flag = true;
                    for(int i = 31; i >= 0;i--) {
                        bool bit = (n >> i) & 1;
                        if(root->children[!bit] != nullptr) {
                            res |= (1 << i);
                            root = root->children[!bit];
                        }
                        else if(root->children[bit] != nullptr) root = root->children[bit];
                        else {
                            flag = false;
                            break;
                        }
                    }
                    return flag == false ? -1 : res;
                }
            public:
                vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
                    int n = nums.size(), m = queries.size();
                    Trie* root = new Trie();
                    vector<int> result;
                    map<pair<int, int>, int> hash;
                    vector<pair<int, int>> sortedQueries;
                    for(auto &query: queries)
                        sortedQueries.push_back({query[1], query[0]});
                    sort(nums.begin(), nums.end());
                    sort(sortedQueries.begin(), sortedQueries.end());
                    for(int i = 0, idx = 0; i < m;i++) {
                        auto [m, x] = sortedQueries[i];
                        while(idx < n && nums[idx] <= m) {
                            insert(root, nums[idx]);
                            idx += 1;
                        }
                        int ans = getMaxXor(root, x);
                        hash[{x, m}] = ans;
                    }
                    for(auto &query: queries)
                        result.push_back(hash[{query[0], query[1]}]);
                    return result;
                }
            };
        
    </details>

---




* [ ] [Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int largestCombination(vector<int>& candidates) {
                    int res = 0;
                    unordered_map<int, int> frqBits;
                    for(auto&bit: candidates) {
                        for(int i = 31; i >= 0;i--)
                            frqBits[i] += ((bit >> i) & 1);
                    }
                    for(int i = 31; i >= 0;i--)
                        res = max(res, frqBits[i]);
                    return res;
                }
            };
        
    </details>

---



* [ ] [Maximum XOR for Each Query](https://leetcode.com/problems/maximum-xor-for-each-query/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
                    int n = nums.size();
                    int maxBit = (1 << maximumBit) - 1, _xor = 0;
                    vector<int> result;
                    for(auto &it: nums)
                        _xor ^= it;
                    for(int i = 0; i < n;i++) {
                        result.push_back(_xor ^ maxBit);
                        _xor ^= nums[n - i - 1];
                    }
                    return result;
                }
            };
        
    </details>

---




* [ ] [Shortest Subarray With OR at Least K II](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int minimumSubarrayLength(vector<int>& nums, int k) {
                    int n = nums.size(), res = INT_MAX;
                    vector<vector<int>> arrBit(n, vector<int>(32));
                    for(int i = 0; i < n;i++) {
                        for(int j = 31; j >= 0;j--) {
                            bool bit = (nums[i] >> j) & 1;
                            arrBit[i][j] += bit;
                            if(i != 0)
                                arrBit[i][j] += arrBit[i - 1][j];
                        }
                    }
                    for(int i = 0; i < n;i++) {
                        int left = i, right = n - 1, cur = -1;
                        while(left <= right) {
                            int mid = left + (right - left) / 2;
                            int cnt = 0;
                            for(int j = 31; j >= 0;j--) {
                                bool bit = arrBit[mid][j] - (i != 0 ? arrBit[i - 1][j] : 0);
                                cnt |= (bit == true ? (1 << j) : 0);
                            }
                            if(cnt >= k) {
                                cur = mid;
                                right = mid - 1;
                            }
                            else left = mid + 1;
                        }
                        if(cur != -1)
                            res = min(res, cur - i + 1);
                    }
                    return res == INT_MAX ? -1 : res;
                }
            };
        
    </details>

---