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

