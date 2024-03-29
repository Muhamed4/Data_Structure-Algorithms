# Problems :

* [ ] [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                pair<int,int> TwoMax(priority_queue<int>&big){
                    int firstMax = big.top();
                    big.pop();
                    int secondMax = big.top();
                    return {firstMax, secondMax};
                }
            public:
                int maxProduct(vector<int>& nums) {
                    priority_queue<int> big;
                    for(auto &it: nums)big.push(it);

                    pair<int,int>twomax = TwoMax(big);
                    return (twomax.first - 1) * (twomax.second - 1);
                }
            };
        
    </details>

---

* [ ] [Delete Greatest Value in Each Row](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int deleteGreatestValue(vector<vector<int>>& grid) {

                    int n = (int)grid.size();
                    int m = (int)grid[0].size();
                    int ans = 0;
                    vector<int>_max(m, 0);
                    for(int i = 0; i < n;i++){
                        priority_queue<int> big;
                        for(int j = 0; j < m;j++){
                            big.push(grid[i][j]);
                        }
                        int idx = m - 1;
                        while(!big.empty()){
                            _max[idx] = max(_max[idx], big.top());
                            --idx;
                            big.pop();
                        }
                    }

                    for(auto &it: _max)ans += it;

                    return ans;
                }
            };
        
    </details>

---


* [ ] [The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
                    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>big;
                    for(int i = 0; i < mat.size();i++){
                        int cnt = 0;
                        for(int j = 0; j < mat[i].size();j++){
                            cnt += mat[i][j];
                        }
                        big.push({cnt, i});
                    }
                    vector<int>ans;
                    while(k--){
                        ans.push_back(big.top().second);
                        big.pop();
                    }
                    return ans;
                }
            };
        
    </details>

---


* [ ] [Take Gifts From the Richest Pile](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                long long pickGifts(vector<int>& gifts, int k) {

                    long long ans = 0;
                    priority_queue<int>big;
                    for(auto &it: gifts)big.push(it);
                    while(!big.empty() && k--){
                        int remove = big.top();
                        big.pop();
                        int x = sqrt(remove);
                        big.push(x);
                    }

                    while(!big.empty()){
                        ans += big.top();
                        big.pop();
                    }

                    return ans;
                }
            };
        
    </details>

---


* [ ] [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int lastStoneWeight(vector<int>& stones) {
                    priority_queue<int>big;
                    for(auto &it: stones)big.push(it);
                    while(big.size() > 1){
                        int y = big.top();
                        big.pop();
                        int x = big.top();
                        big.pop();
                        y -= x;
                        big.push(y);
                    }
                    return big.top();
                }
            };
        
    </details>

---


* [ ] [Find Kth Largest XOR Coordinate Value](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int kthLargestValue(vector<vector<int>>& matrix, int k) {
                    priority_queue<int>big;
                    int m = matrix.size();
                    int n = matrix[0].size();
                    int xor_ = 0;
                    vector<vector<int>>xorPre(m + 2, vector<int>(n + 2));
                    for(int i = 0; i < m;i++){
                        for(int j = 0; j < n;j++){
                            xorPre[i + 1][j + 1] = ((xorPre[i][j + 1] ^ xorPre[i + 1][j]) ^ xorPre[i][j]);
                            xorPre[i + 1][j + 1] ^= matrix[i][j];
                            big.push(xorPre[i + 1][j + 1]);
                        }
                    }
                    while(k > 1 && --k)big.pop();
                    return big.top();
                }
            };
        
    </details>

---


* [ ] [Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maximumScore(int a, int b, int c) {
                    priority_queue<int>big;
                    big.push(a); big.push(b); big.push(c);
                    int ans = 0;
                    while(!big.empty() && big.size() > 1){
                        int aa = big.top();
                        big.pop();
                        int bb = big.top();
                        big.pop();
                        ++ans;
                        --aa; --bb;
                        if(aa)big.push(aa);
                        if(bb)big.push(bb);
                    }

                    return ans;
                }
            };
        
    </details>

---

