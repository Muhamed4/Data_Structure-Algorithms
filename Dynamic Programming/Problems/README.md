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