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