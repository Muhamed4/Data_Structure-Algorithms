

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