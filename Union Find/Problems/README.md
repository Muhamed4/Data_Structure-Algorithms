
* [ ] [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=problem-list-v2&envId=union-find) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct UnionFind {
                unordered_map<int, int> rank, parent;

                int find_set(int x) {
                    if(x == parent[x])
                        return x;
                    return parent[x] = find_set(parent[x]);
                }

                void link(int x, int y) {
                    if(rank[x] > rank[y]) swap(x, y);
                    parent[x] = y;
                    if(rank[x] == rank[y]) rank[y] += 1;
                }

                void union_sets(int x, int y) {
                    x = find_set(x);
                    y = find_set(y);
                    if(x != y)
                        link(x, y);
                }
            };
            class Solution {
            public:
                int longestConsecutive(vector<int>& nums) {
                    int res = 0;
                    UnionFind DS;
                    unordered_map<int, int> count;
                    unordered_map<int, bool> vis;
                    for(auto &it: nums) {
                        if(DS.parent.count(it) == false) {
                            DS.parent[it] = it;
                            DS.rank[it] = 1;
                        }
                        if(DS.parent.count(it - 1) != false)
                            DS.union_sets(it, it - 1);
                        if(DS.parent.count(it + 1) != false)
                            DS.union_sets(it, it + 1);
                    }
                    for(auto &it: nums) {
                        if(vis.count(it) == false) {
                            count[DS.find_set(it)] += 1;
                            vis[it] = true;
                        }
                        res = max(res, count[DS.parent[it]]);
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Number of Islands](https://leetcode.com/problems/number-of-islands/description/?envType=problem-list-v2&envId=union-find) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct UnionFind {
                vector<int> parent, rank;
                UnionFind(int n) {
                    parent = vector<int>(n);
                    rank = vector<int>(n, 1);
                    for(int i = 0; i < n;i++)
                        parent[i] = i;
                }

                int findParent(int node) {
                    if(parent[node] == node)
                        return node;
                    return parent[node] = findParent(parent[node]);
                }

                void link(int x, int y) {
                    // if(rank[x] > rank[y]) 
                    //     swap(x, y);
                    parent[y] = x;
                    if(rank[x] == rank[y])
                        rank[y] += 1;
                }

                void unionSets(int x, int y) {
                    int parentX = findParent(x);
                    int parentY = findParent(y);
                    if(parentX != parentY)
                        link(parentX, parentY);
                }
            };
            class Solution {
                int dx[4] = {-1, 0, 0, 1};
                int dy[4] = {0, -1, 1, 0};
                bool isValid(int x, int y, int n, int m) {
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
            public:
                int numIslands(vector<vector<char>>& grid) {
                    int n = grid.size();
                    int m = grid[0].size();
                    int res = 0;
                    UnionFind DSU(n * m);
                    unordered_map<int, bool> vis;
                    for(int i = 0; i < n;i++) {
                        for(int j = 0; j < m;j++) {
                            if(grid[i][j] == '0') continue;
                            for(int k = 0; k < 4;k++) {
                                int newI = dx[k] + i;
                                int newJ = dy[k] + j;
                                if(isValid(newI, newJ, n, m) && grid[newI][newJ] != '0')
                                    DSU.unionSets(i * m + j, newI * m + newJ);
                            }
                        }
                    }
                    for(int i = 0; i < n;i++) {
                        for(int j = 0; j < m;j++) {
                            int parent = DSU.findParent(i * m + j);
                            if(vis.count(parent) == false && grid[i][j] == '1') {
                                res += 1;
                                vis[parent] = true;
                            }
                        }
                    }
                    return res;
                }
            };
        
    </details>

---



* [ ] [Number of Provinces](https://leetcode.com/problems/number-of-provinces/description/?envType=problem-list-v2&envId=union-find) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct UnionFind {
                int forests;
                vector<int> parent, rank;
                UnionFind(int n) {
                    forests = n;
                    parent = rank = vector<int>(n);
                    for(int i = 0; i < n;i++) {
                        rank[i] = 1;
                        parent[i] = i;
                    }
                }

                int findParent(int x) {
                    if(x == parent[x]) return x;
                    return parent[x] = findParent(parent[x]);
                }

                void link(int x, int y) {
                    if(rank[x] > rank[y]) swap(x, y);
                    parent[x] = y;
                    if(rank[x] == rank[y]) rank[y] += 1;
                }

                void unionSet(int x, int y) {
                    int parentX = findParent(x);
                    int parentY = findParent(y);
                    if(parentX != parentY) {
                        forests -= 1;
                        link(parentX, parentY);
                    }
                }
            };
            class Solution {
            public:
                int findCircleNum(vector<vector<int>>& isConnected) {
                    int n = isConnected.size();
                    UnionFind DSU(n);
                    for(int i = 0; i < n;i++) {
                        for(int j = 0; j < n;j++) {
                            if(isConnected[i][j] == 1)
                                DSU.unionSet(i, j);
                        }
                    }
                    return DSU.forests;
                }
            };
        
    </details>

---




* [ ] [Redundant Connection](https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=union-find) 
    * <details>
        <summary> Solution </summary>

        ```c++
            struct UnionFind {
                vector<int> parent, rank;
                UnionFind(int n) {
                    parent = rank = vector<int>(n);
                    for(int i = 0; i < n;i++) {
                        rank[i] = 1;
                        parent[i] = i;
                    }
                }

                int findParent(int x) {
                    if(x == parent[x]) return x;
                    return parent[x] = findParent(parent[x]);
                }

                void link(int x, int y) {
                    if(rank[x] > rank[y]) swap(x, y);
                    parent[x] = y;
                    if(rank[x] == rank[y]) rank[y] += 1;
                }

                void unionSet(int x, int y) {
                    int parentX = findParent(x);
                    int parentY = findParent(y);
                    if(parentX != parentY)
                        link(parentX, parentY);
                }
            };
            class Solution {
            public:
                vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                    int n = edges.size();
                    vector<int> res;
                    UnionFind DSU(n + 1);
                    for(auto &edge: edges) {
                        int parentX = DSU.findParent(edge[0]);
                        int parentY = DSU.findParent(edge[1]);
                        if(parentX == parentY) {
                            res = edge;
                            break;
                        }
                        DSU.unionSet(parentX, parentY);
                    }
                    return res;
                }
            };
        
    </details>

---