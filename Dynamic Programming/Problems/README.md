* [ ] [Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void Populate(int node, int parent, vector<int>& nodeCount,
                            vector<int>& result, vector<vector<int>>& adj) {
                    nodeCount[node] = 1;
                    for (auto& child : adj[node]) {
                        if (child == parent) continue;
                        Populate(child, node, nodeCount, result, adj);
                        nodeCount[node] += nodeCount[child];
                        result[node] += result[child] + nodeCount[child];
                    }
                }

                void dfs(int node, int parent, int& n, vector<int>& nodeCount, vector<int>& result,
                        vector<vector<int>>& adj) {
                    if(parent != -1) {
                        result[node] = result[parent] + (n - nodeCount[node]) - nodeCount[node];
                    }
                    for(auto &child: adj[node]) {
                        if(child != parent) {
                            dfs(child, node, n, nodeCount, result, adj);
                        }
                    }
                }

            public:
                vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
                    vector<int> nodeCount(n), result(n);
                    vector<vector<int>> adj(n);
                    for (auto& edge : edges) {
                        int u = edge[0], v = edge[1];
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                    Populate(0, -1, nodeCount, result, adj);
                    dfs(0, -1, n, nodeCount, result, adj);
                    return result;
                }
            };

    </details>

---



* [ ] [Unique Paths](https://leetcode.com/problems/unique-paths/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[101][101];
                bool isValid(int i, int j, int n, int m) {
                    return (i >= 0 && i < n && j >= 0 && j < m);
                }
                // Memoization
                int Paths(int i, int j, int n, int m) {
                    if(!isValid(i, j, n, m)) return 0;
                    if(i == n - 1 && j == m - 1) return 1;
                    int &ret = dp[i][j];
                    if(~ret) return ret;
                    ret = Paths(i + 1, j, n, m);
                    ret += Paths(i, j + 1, n, m);
                    return ret;
                }
            public:
                int uniquePaths(int m, int n) {
                    // Iterative dp
                    dp[m - 1][n - 1] = 1;
                    for(int i = m - 1; i >= 0;i--) {
                        for(int j = n - 1; j >= 0;j--) {
                            if(isValid(i + 1, j, m, n)) dp[i][j] += dp[i + 1][j];
                            if(isValid(i, j + 1, m, n)) dp[i][j] += dp[i][j + 1];
                        }
                    }
                    return dp[0][0];
                }
            };

    </details>

---



* [ ] [Decode Ways](https://leetcode.com/problems/decode-ways/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[101];
                int DecodeWays(int idx, int& n, string& str) {
                    if(idx == n)
                        return 1;
                    int& ret = dp[idx];
                    if(~ret)
                        return ret;
                    ret = 0;
                    if(str[idx] != '0') 
                        ret = DecodeWays(idx + 1, n, str);
                    if(idx + 1 < n && str[idx] != '0' && str[idx] < '3'){
                        if((str[idx] == '2' && str[idx + 1] <= '6') || str[idx] == '1') {
                            ret += DecodeWays(idx + 2, n, str);
                        }
                    }
                    return ret;
                }
            public:
                int numDecodings(string s) {
                    int n = s.size();
                    memset(dp, -1, sizeof(dp));
                    return DecodeWays(0, n, s);
                }
            };

    </details>

---



* [ ] [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[20][20];
                int BST(int left, int right) {
                    if(left == right) return 1;
                    int &ret = dp[left][right];
                    if(~ret) return ret;
                    ret = 0;
                    for(int i = left; i <= right;i++) {
                        if(i == left) ret += BST(left + 1, right);
                        else if(i == right) ret += BST(left, right - 1);
                        else ret += (BST(left, i - 1) * BST(i + 1, right));
                    }
                    return ret;
                }
            public:
                int numTrees(int n) {
                    memset(dp, -1, sizeof(dp));
                    return BST(1, n);
                }
            };

    </details>

---



* [ ] [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<vector<int>> generate(int numRows) {
                    vector<vector<int>> pascal(numRows);
                    for(int i = 0; i < numRows; i++) {
                        pascal[i] = vector<int>(i + 1);
                        pascal[i][0] = pascal[i][i] = 1;
                    }
                    for(int i = 1; i < numRows;i++) {
                        for(int j = 1; j < pascal[i].size() - 1;j++) {
                            pascal[i][j] += pascal[i - 1][j - 1] + pascal[i - 1][j];
                        }
                    }
                    return pascal;
                }
            };

    </details>

---



* [ ] [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                vector<int> getRow(int rowIndex) {
                    vector<int> res(rowIndex + 1, 1);
                    for(int i = 1; i < rowIndex;i++) {
                        for(int j = i; j > 0;j--) {
                            res[j] += res[j - 1];
                        }
                    }
                    return res;
                }
            };

    </details>

---




* [ ] [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                void getAllPal(string& s, vector<vector<bool>>& pal, int& n) {
                    for(int i = 0; i < n;i++) {
                        int left = i, right = i;
                        while(left >= 0 && right < n && s[left] == s[right]) {
                            pal[left][right] = true;
                            left -= 1;
                            right += 1;
                        }
                    }
                    for(int i = 0; i < n - 1;i++) {
                        int left = i, right = i + 1;
                        while(left >= 0 && right < n && s[left] == s[right]) {
                            pal[left][right] = true;
                            left -= 1;
                            right += 1;
                        }
                    }
                }
                // Memoization
                int minPal(int idx, int& n, vector<vector<bool>>& pal, vector<int>& dp) {
                    if(idx == n)
                        return 0;
                    int& ret = dp[idx];
                    if(~ret)
                        return ret;
                    ret = 1e9;
                    for(int i = idx; i < n;i++) {
                        if(pal[idx][i]) ret = min(ret, minPal(i + 1, n, pal, dp) + 1);
                    }
                    return ret;
                }
            public:
                int minCut(string s) {
                    int n = s.size();
                    vector<int> dp(n, 1e9);
                    vector<vector<bool>> pal(n, vector<bool>(n));
                    getAllPal(s, pal, n);
                    // Iterative
                    for(int i = 0; i < n;i++) {
                        for(int j = i; j >= 0;j--) {
                            if(pal[j][i]) dp[i] = min(dp[i], (j == 0 ? 0 : dp[j - 1]) + 1);
                        }
                    }
                    return dp[n - 1] - 1;
                }
            };

    </details>

---




* [ ] [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
            public:
                int maxProduct(vector<int>& nums) {
                    int n = nums.size();
                    int maxProduct = INT_MIN;
                    int mn = 1, mx = 1;
                    for(int i = 0; i < n;i++) {
                        if(nums[i] == 0) {
                            maxProduct = max(maxProduct, nums[i]);
                            mn = mx = 1;
                        }
                        else {
                            int temp = mn * nums[i];
                            mn = min({mn * nums[i], mx * nums[i], nums[i]});
                            mx = max({temp, mx * nums[i], nums[i]});
                            maxProduct = max(maxProduct, mx);
                        }
                    }
                    return maxProduct;
                }
            };

    </details>

---




* [ ] [House Robber II](https://leetcode.com/problems/house-robber-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int Robber(int idx, int n, vector<int>& v, vector<int>& dp) {
                    if(idx >= n)
                        return 0;
                    int& ret = dp[idx];
                    if(~ret)
                        return ret;
                    ret = Robber(idx + 1, n, v, dp);
                    ret = max(ret, Robber(idx + 2, n, v, dp) + v[idx]);
                    return ret;
                }
            public:
                int rob(vector<int>& nums) {
                    int n = nums.size();
                    vector<int> dp1(n, -1), dp2(n, -1);
                    if(n == 1) return nums[0];
                    return max(Robber(0, n - 1, nums, dp1), Robber(1, n, nums, dp2));
                }
            };

    </details>

---




* [ ] [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[5005][2];
                int BestTime(int idx, bool action, int& n, vector<int>& prices) {
                    if(idx >= n)
                        return 0;
                    int &ret = dp[idx][action];
                    if(~ret)
                        return ret;
                    ret = BestTime(idx + 1, action, n, prices);
                    if(action == false)
                        ret = max(ret, BestTime(idx + 1, true, n, prices) - prices[idx]);
                    else
                        ret = max(ret, BestTime(idx + 2, false, n, prices) + prices[idx]);
                    return ret;
                }
            public:
                int maxProfit(vector<int>& prices) {
                    int n = prices.size();
                    memset(dp, -1, sizeof(dp));
                    return BestTime(0, false, n, prices);
                }
            };

    </details>

---



* [ ] [Interleaving String](https://leetcode.com/problems/interleaving-string/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[101][101];
                bool isPossible(int i, int j, string& s1, string& s2, string& s3) {
                    if(i == s1.size() && j == s2.size() && (i + j) == s3.size())
                        return true;
                    int &ret = dp[i][j];
                    if(~ret)
                        return ret;
                    ret = 0;
                    int idx = i + j;
                    if(i < s1.size() && s1[i] == s3[idx]) ret |= isPossible(i + 1, j, s1, s2, s3);
                    if(j < s2.size() && s2[j] == s3[idx]) ret |= isPossible(i, j + 1, s1, s2, s3);
                    return ret;
                }
            public:
                bool isInterleave(string s1, string s2, string s3) {
                    memset(dp, -1, sizeof(dp));
                    return isPossible(0, 0, s1, s2, s3);
                }
            };

    </details>

---




* [ ] [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[100001][101][2];
                int maxProfit(int idx, int&n, int rem, bool sell, vector<int>& prices) {
                    if(idx == n || rem == 0)
                        return 0;
                    int &ret = dp[idx][rem][sell];
                    if(~ret)
                        return ret;
                    ret = maxProfit(idx + 1, n, rem, sell, prices);
                    if(sell == false)
                        ret = max(ret, maxProfit(idx + 1, n, rem, true, prices) - prices[idx]);
                    else 
                        ret = max(ret, maxProfit(idx + 1, n, rem - 1, false, prices) + prices[idx]);
                    return ret;
                }
            public:
                int maxProfit(vector<int>& prices) {
                    int n = prices.size();
                    memset(dp, -1, sizeof(dp));
                    return maxProfit(0, n, 2, false, prices);
                }
            };

    </details>

---




* [ ] [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[1001][101][2];
                int maxProfit(int idx, int&n, int rem, bool sell, vector<int>& prices) {
                    if(idx == n || rem == 0)
                        return 0;
                    int &ret = dp[idx][rem][sell];
                    if(~ret)
                        return ret;
                    ret = maxProfit(idx + 1, n, rem, sell, prices);
                    if(sell == false)
                        ret = max(ret, maxProfit(idx + 1, n, rem, true, prices) - prices[idx]);
                    else 
                        ret = max(ret, maxProfit(idx + 1, n, rem - 1, false, prices) + prices[idx]);
                    return ret;
                }
            public:
                int maxProfit(int k, vector<int>& prices) {
                    int n = prices.size();
                    memset(dp, -1, sizeof(dp));
                    return maxProfit(0, n, k, false, prices);
                }
            };

    </details>

---




* [ ] [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[1001][1001];
                int minSteps(int idx, int copy, int n) {
                    if(idx >= n)
                        return idx == n ? 0 : 1e8;
                    int &ret = dp[idx][copy];
                    if(~ret)
                        return ret;
                    if(copy == 0)
                        ret = minSteps(idx + 1, 1, n) + 2;
                    else {
                        ret = minSteps(idx + copy, copy, n) + 1;
                        ret = min(ret, minSteps(idx + idx, idx, n) + 2);
                    }
                    return ret;
                }
            public:
                int minSteps(int n) {
                    memset(dp, -1, sizeof(dp));
                    return minSteps(1, 0, n);
                }
            };

    </details>

---




* [ ] [Stone Game II](https://leetcode.com/problems/stone-game-ii/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[101][101][2];
                int maxStones(int idx, int m, int n, bool flag, vector<int>& piles) {
                    if(idx >= n)
                        return 0;
                    int &ret = dp[idx][m][flag];
                    if(~ret)
                        return ret;
                    int sum = 0;
                    ret = (flag == 1 ? INT_MAX : 0);
                    for(int i = 0; i < 2 * m;++i) {
                        if(idx + i >= n)
                            break;
                        sum += piles[idx + i];
                        if(flag == 0)
                            ret = max(ret, maxStones(idx + i + 1, max(i + 1, m), n, flag ^ 1, piles) + sum);
                        else
                            ret = min(ret, maxStones(idx + i + 1, max(i + 1, m), n, flag ^ 1, piles));
                    }
                    return ret;
                }
            public:
                int stoneGameII(vector<int>& piles) {
                    int n = piles.size();
                    memset(dp, -1, sizeof(dp));
                    return maxStones(0, 1, n, 0, piles);
                }
            };

    </details>

---




* [ ] [Shortest Common Supersequence ](https://leetcode.com/problems/shortest-common-supersequence/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[1001][1001];
                int shortestStr(int i, int j, int& n, int& m, string& s, string& t) {
                    if(i == n && j == m)
                        return 0;
                    if(i == n || j == m)
                        return (n - i) + (m - j);
                    int& ret = dp[i][j];
                    if(~ret)
                        return ret;
                    ret = shortestStr(i + 1, j + 1, n, m, s, t) + (s[i] == t[j] ? 1 : 2);
                    ret = min(ret, shortestStr(i + 1, j, n, m, s, t) + 1);
                    ret = min(ret, shortestStr(i, j + 1, n, m, s, t) + 1);
                    return ret;
                }
                
                void buildStr(int i, int j, int& n, int& m, string& s, string& t, string& res) {
                    if(i == n && j == m)
                        return;
                    if(i == n || j == m) {
                        for(int k = i; k < n;++k)
                            res += s[k];
                        for(int k = j; k < m;++k)
                            res += t[k];
                        return;
                    }
                    int ret = shortestStr(i, j, n, m, s, t);
                    int choice1 = shortestStr(i + 1, j + 1, n, m, s, t) + (s[i] == t[j] ? 1 : 2);
                    int choice2 = shortestStr(i + 1, j, n, m, s, t) + 1;
                    if(ret == choice1) {
                        // res += (s[i] == t[j] ? s[i] : s[i] + t[j]);
                        if(s[i] == t[j]) res += s[i];
                        else {
                            res += s[i];
                            res += t[j];
                        }
                        return buildStr(i + 1, j + 1, n, m, s, t, res);
                    }
                    else if(ret == choice2) {
                        res += s[i];
                        return buildStr(i + 1, j, n, m, s, t, res);
                    }
                    else {
                        res += t[j];
                        return buildStr(i, j + 1, n, m, s, t, res);
                    }
                }
            public:
                string shortestCommonSupersequence(string str1, string str2) {
                    int n = str1.size();
                    int m = str2.size();
                    string res = "";
                    memset(dp, -1, sizeof(dp));
                    // cout << shortestStr(0, 0, n, m, str1, str2) << endl;
                    buildStr(0, 0, n, m, str1, str2, res);
                    return res;
                }
            };

            /*
            "bbbaaaba"
            "bbababbb"
            */

    </details>

---



* [ ] [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            struct Trie {
                Trie* children[26];
                bool isEndOfWord;
                Trie() {
                    isEndOfWord = false;
                    for(int i = 0; i < 26;i++)
                        children[i] = nullptr;
                }
            };
            class Solution {
                int dp[55];
                void insert(Trie* root, string& str) {
                    int n = str.size();
                    for(int i = 0; i < n;i++) {
                        if(root->children[str[i] - 'a'] == nullptr) {
                            root->children[str[i] - 'a'] = new Trie();
                        }
                        root = root->children[str[i] - 'a'];
                    }
                    root->isEndOfWord = true;
                }
                int extraChar(int idx, int n, string& str, Trie* root) {
                    if(idx == n) return 0;
                    int &ret = dp[idx];
                    if(~ret) return ret;
                    ret = extraChar(idx + 1, n, str, root) + 1;
                    Trie* cur = root;
                    for(int i = idx; i < n;i++) {
                        if(cur->children[str[i] - 'a'] == nullptr)
                            break;
                        cur = cur->children[str[i] - 'a'];
                        if(cur->isEndOfWord)
                            ret = min(ret, extraChar(i + 1, n, str, root));
                    }
                    return ret;
                }
            public:
                int minExtraChar(string s, vector<string>& dictionary) {
                    int n = s.size();
                    int m = dictionary.size();
                    Trie* root = new Trie();
                    for(auto &str: dictionary)
                        insert(root, str);
                    memset(dp, -1, sizeof(dp));
                    return extraChar(0, n, s, root);
                }
            };
        
    </details>

---




* [ ] [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[50005][2];
                int solve(int idx, bool take, int n, int fee, vector<int>& prices) {
                    if(idx == n) return take == false ? 0 : -1E9;
                    int& ret = dp[idx][take];
                    if(~ret) return ret;
                    ret = solve(idx + 1, take, n, fee, prices);
                    if(take == false) ret = max(ret, solve(idx + 1, take ^ 1, n, fee, prices) - prices[idx] - fee);
                    else ret = max(ret, solve(idx + 1, take ^ 1, n, fee, prices) + prices[idx]);
                    return ret;
                }
            public:
                int maxProfit(vector<int>& prices, int fee) {
                    int n = prices.size();
                    memset(dp, -1, sizeof(dp));
                    return solve(0, false, n, fee, prices);
                }
            };
        
    </details>

---



* [ ] [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[1001][1001];
                int solve(int i, int j, int n, int m, string& s, string& t) {
                    if(i == n || j == m) return 0;
                    int& ret = dp[i][j];
                    if(~ret) return ret;
                    if(s[i] == t[j]) return ret = solve(i + 1, j + 1, n, m, s, t) + 1;
                    ret = max(solve(i + 1, j, n, m, s, t), solve(i, j + 1, n, m, s, t));
                    return ret;
                }
            public:
                int longestCommonSubsequence(string text1, string text2) {
                    int n = text1.size();
                    int m = text2.size();
                    memset(dp, -1, sizeof(dp));
                    return solve(0, 0, n, m, text1, text2);
                }
            };
                
        
    </details>

---


* [ ] [Restore The Array](https://leetcode.com/problems/restore-the-array/description/)
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dp[100005], mod = 1000000007;
                int cntArray(int idx, int n, int k, string& s) {
                    if(idx == n) return 1;
                    if((s[idx] - '0') == 0) return 0;
                    int& ret = dp[idx];
                    if(~ret) return ret;
                    ret = 0;
                    long long num = 0;
                    while(num <= k && idx < n) {
                        num *= 10;
                        num += (s[idx] - '0');
                        idx += 1;
                        if(num <= k) 
                            ret = (ret % mod) + (cntArray(idx, n, k, s) % mod);
                    }
                    return ret;
                }
            public:
                int numberOfArrays(string s, int k) {
                    int n = s.size();
                    memset(dp, -1, sizeof(dp));
                    return cntArray(0, n, k, s) % mod;
                }
            };
        
    </details>

---