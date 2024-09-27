
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