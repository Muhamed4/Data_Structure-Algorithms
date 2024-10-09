* [ ] [BFS of graph](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
            public:
                // Function to return Breadth First Traversal of given graph.
                vector<int> bfsOfGraph(int V, vector<int> adj[]) {
                    // Code here
                    vector<int>ans, vis(V);
                    queue<int>bfs;
                    bfs.push(0);
                    vis[0] = 1;
                    while(!bfs.empty()){
                        int node = bfs.front();
                        bfs.pop();
                        ans.push_back(node);
                        for(auto &child: adj[node]){
                            if(vis[child] == 0){
                                vis[child] = 1;
                                bfs.push(child);
                            }
                        }
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int tc;
                cin >> tc;
                while (tc--) {
                    int V, E;
                    cin >> V >>

                        E;

                    vector<int> adj[V];

                    for (int i = 0; i < E; i++) {
                        int u, v;
                        cin >> u >> v;
                        adj[u].push_back(v);
                        // 		adj[v].push_back(u);
                    }
                    // string s1;
                    // cin>>s1;
                    Solution obj;
                    vector<int> ans = obj.bfsOfGraph(V, adj);
                    for (int i = 0; i < ans.size(); i++) {
                        cout << ans[i] << " ";
                    }
                    cout << endl;
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [DFS of Graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
            public:
                // Function to return a list containing the DFS traversal of the graph.
                void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ans){
                    vis[node] = 1;
                    ans.push_back(node);
                    for(auto &child: adj[node]){
                        if(!vis[child]){
                            dfs(child, adj, vis, ans);
                        }
                    }
                }
                vector<int> dfsOfGraph(int V, vector<int> adj[]) {
                    // Code here
                    vector<int>vis(V), ans;
                    dfs(0, adj, vis, ans);
                    return ans;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int tc;
                cin >> tc;
                while (tc--) {
                    int V, E;
                    cin >> V >> E;

                    vector<int> adj[V];

                    for (int i = 0; i < E; i++) {
                        int u, v;
                        cin >> u >> v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                    // string s1;
                    // cin>>s1;
                    Solution obj;
                    vector<int> ans = obj.dfsOfGraph(V, adj);
                    for (int i = 0; i < ans.size(); i++) {
                        cout << ans[i] << " ";
                    }
                    cout << endl;
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Detect cycle in an undirected graph](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
            public:
                // Function to detect cycle in an undirected graph.
                bool dfs(int node, int parent, vector<int>adj[], vector<int>&vis){
                    vis[node] = 1;
                    bool flag = false;
                    for(auto &child: adj[node]){
                        if(vis[child] && child != parent)
                            return true;
                        if(!vis[child])
                            flag |= dfs(child, node, adj, vis);
                    }
                    return flag;
                }
                
                bool isCycle(int V, vector<int> adj[]) {
                    // Code here
                    vector<int>vis(V);
                    bool cycle = false;
                    for(int i = 0; i < V;i++){
                        if(!vis[i]){
                            cycle |= dfs(i, -1, adj, vis);
                        }
                    }
                    return cycle;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int tc;
                cin >> tc;
                while (tc--) {
                    int V, E;
                    cin >> V >> E;
                    vector<int> adj[V];
                    for (int i = 0; i < E; i++) {
                        int u, v;
                        cin >> u >> v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                    Solution obj;
                    bool ans = obj.isCycle(V, adj);
                    if (ans)
                        cout << "1\n";
                    else
                        cout << "0\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Find the number of islands](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
                int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
                int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

                bool isValid(int i, int j, int n, int m){
                    return (i >= 0 && i < n && j >= 0 && j < m);
                }

                void dfs(int x, int y, int n, int m, vector<vector<char>>&grid, vector<vector<bool>>&vis){
                    
                    if(!isValid(x, y, n, m) || vis[x][y] || grid[x][y] == '0')
                        return;
                        
                    vis[x][y] = 1;
                    for(int i = 0; i < 8;i++){
                        int xx = x + dx[i];
                        int yy = y + dy[i];
                        dfs(xx, yy, n, m, grid, vis);
                    }
                    
                }
            public:
                // Function to find the number of islands.
                int numIslands(vector<vector<char>>& grid) {
                    // Code here
                    int n = grid.size();
                    int m = grid[0].size();
                    vector<vector<bool>>vis(n, vector<bool>(m));
                    int comp = 0;
                    for(int i = 0; i < n;i++){
                        for(int j = 0; j < m;j++){
                            if(!vis[i][j] && grid[i][j] == '1'){
                                dfs(i, j, n, m, grid, vis);
                                ++comp;
                            }
                        }
                    }
                    return comp;
                }
            };

            //{ Driver Code Starts.
            int main() {
                int tc;
                cin >> tc;
                while (tc--) {
                    int n, m;
                    cin >> n >> m;
                    vector<vector<char>> grid(n, vector<char>(m, '#'));
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            cin >> grid[i][j];
                        }
                    }
                    Solution obj;
                    int ans = obj.numIslands(grid);
                    cout << ans << '\n';
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Shortest Source to Destination Path](https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            // Initial Template for C++

            #include <bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            // User function Template for C++

            class Solution {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                
                bool isValid(int x, int y, int n, int m){
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
            public:
                int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
                    // code here
                    vector<vector<int>>distance(N, vector<int>(M, -1));
                    vector<vector<bool>>vis(N, vector<bool>(M));
                    // distance[x][y] = distance[node][node] + 1;
                    queue<pair<int,int>>bfs;
                    if(A[0][0]){
                        bfs.push({0 , 0});
                        vis[0][0] = 1;
                        distance[0][0] = 0;
                    }
                    while(!bfs.empty()){
                        pair<int,int>node = bfs.front();
                        bfs.pop();
                        for(int i = 0; i < 4;i++){
                            int newPosX = node.first + dx[i];
                            int newPosY = node.second + dy[i];
                            if(isValid(newPosX, newPosY, N, M) && !vis[newPosX][newPosY] && A[newPosX][newPosY]){
                                vis[newPosX][newPosY] = 1;
                                bfs.push({newPosX, newPosY});
                                distance[newPosX][newPosY] = distance[node.first][node.second] + 1;
                            }
                        }
                    }
                    return distance[X][Y];
                }
            };

            //{ Driver Code Starts.
            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int N, M, x, y;
                    cin >> N >> M;
                    vector<vector<int>> v(N, vector<int>(M));
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < M; j++) cin >> v[i][j];
                    cin >> x >> y;
                    Solution ob;
                    cout << ob.shortestDistance(N, M, v, x, y) << "\n";
                }
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Flood fill Algorithm](https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                
                bool isValid(int x, int y, int n, int m){
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                
                void floodFill(int x, int y, int& n, int& m, vector<vector<bool>>&vis, vector<vector<int>>&image, int original, int& newColor){
                    if(!isValid(x, y, n, m) || vis[x][y] || image[x][y] != original)
                        return;
                    vis[x][y] = 1;
                    image[x][y] = newColor;
                    for(int i = 0; i < 4;i++){
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        floodFill(newX, newY, n, m, vis, image, original, newColor);
                    }
                }
            public:
                vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
                    // Code here 
                    int n = image.size();
                    int m = image[0].size();
                    vector<vector<bool>>vis(n, vector<bool>(m));
                    floodFill(sr, sc, n, m, vis, image, image[sr][sc], newColor);
                    return image;
                }
            };

            //{ Driver Code Starts.
            int main(){
                int tc;
                cin >> tc;
                while(tc--){
                    int n, m;
                    cin >> n >> m;
                    vector<vector<int>>image(n, vector<int>(m,0));
                    for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++)
                            cin >> image[i][j];
                    }
                    int sr, sc, newColor;
                    cin >> sr >> sc >> newColor;
                    Solution obj;
                    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
                    for(auto i: ans){
                        for(auto j: i)
                            cout << j << " ";
                        cout << "\n";
                    }
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Steps by Knight](https://www.geeksforgeeks.org/problems/steps-by-knight5927/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include<bits/stdc++.h>
            using namespace std;

            // } Driver Code Ends
            class Solution 
            {
                int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
                int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
                
                bool isValid(int x, int y, int n){
                    return (x >= 1 && x <= n && y >= 1 && y <= n);
                }
                
                public:
                //Function to find out minimum steps Knight needs to reach target position.
                int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
                {
                    // Code here
                    int srcX = KnightPos[0], srcY = KnightPos[1];
                    int targX = TargetPos[0], targY = TargetPos[1];
                    vector<vector<bool>>vis(N + 1, vector<bool>(N + 1));
                    vector<vector<int>>distance(N + 1, vector<int>(N + 1, -1));
                    queue<pair<int,int>> bfs;
                    bfs.push({srcX, srcY});
                    vis[srcX][srcY] = 1;
                    distance[srcX][srcY] = 0;
                    while(!bfs.empty()){
                        pair<int,int> node = bfs.front();
                        bfs.pop();
                        if(node.first == targX && node.second == targY)
                            break;
                        for(int i = 0; i < 8;i++){
                            int newX = node.first + dx[i];
                            int newY = node.second + dy[i];
                            if(isValid(newX, newY, N) && !vis[newX][newY]){
                                vis[newX][newY] = 1;
                                distance[newX][newY] = distance[node.first][node.second] + 1;
                                bfs.push({newX, newY});
                            }
                        }
                    }
                    return distance[targX][targY];
                }
            };

            //{ Driver Code Starts.
            int main(){
                int tc;
                cin >> tc;
                while(tc--){
                    vector<int>KnightPos(2);
                    vector<int>TargetPos(2);
                    int N;
                    cin >> N;
                    cin >> KnightPos[0] >> KnightPos[1];
                    cin >> TargetPos[0] >> TargetPos[1];
                    Solution obj;
                    int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
                    cout << ans <<"\n";
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---


* [ ] [Number of Provinces](https://www.geeksforgeeks.org/problems/number-of-provinces/1?page=1&category=DFS,BFS&sortBy=submissions) 
    * <details>
        <summary> Solution </summary>

        ```c++
            //{ Driver Code Starts
            #include <bits/stdc++.h>
            using namespace std;


            // } Driver Code Ends
            //User function Template for C++

            class Solution {
                void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
                    vis[node] = 1;
                    int sz = adj[node].size();
                    for(int i = 0; i < sz;i++){
                        if(adj[node][i] && !vis[i]){
                            dfs(i, vis, adj);
                        }
                    }
                }
            public:
                int numProvinces(vector<vector<int>>& adj, int V) {
                    // code here
                    int ans = 0;
                    vector<int>vis(V);
                    for(int i = 0;i < V;i++){
                        if(!vis[i]){
                            dfs(i, vis, adj);
                            ++ans;
                        }
                    }
                    return ans;
                }
            };

            //{ Driver Code Starts.

            int main() {
                int t;
                cin >> t;
                while (t--) {
                    int V,x;
                    cin>>V;
                    
                    vector<vector<int>> adj;
                    
                    for(int i=0; i<V; i++)
                    {
                        vector<int> temp;
                        for(int j=0; j<V; j++)
                        {
                            cin>>x;
                            temp.push_back(x);
                        }
                        adj.push_back(temp);
                    }
                    

                    Solution ob;
                    cout << ob.numProvinces(adj,V) << endl;
                }
                return 0;
            }
            // } Driver Code Ends
        
    </details>

---



* [ ] [Build a Matrix With Conditions](https://leetcode.com/problems/build-a-matrix-with-conditions/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                bool CheckCycle(int node, vector<char>& vis, vector<vector<int>>& adj) {
                    bool flag = true;
                    vis[node] = 1;
                    for(auto &child: adj[node]) {
                        if(vis[child] == 0) {
                            flag &= CheckCycle(child, vis, adj);
                        }
                        else if(vis[child] == 1)
                            return false;
                    }
                    vis[node] = 2;
                    return flag;
                }
                
                void buildGraph(vector<vector<int>>& conditions, vector<vector<int>>& adj) {
                    for(auto &edge: conditions) {
                        int x = edge[0], y = edge[1];
                        adj[x].push_back(y);
                    }
                }

                bool CheckCycle(vector<vector<int>>& adj, int k) {
                    vector<char> vis(k + 1);
                    bool flag = true;
                    for(int i = 1; i <= k;i++) {
                        if(vis[i] == 0) {
                            flag &= CheckCycle(i, vis, adj);
                            if(flag == false)
                                break;
                        }
                    }
                    return flag;
                }

                void dfs(int node, vector<bool>& vis, vector<int>& ans, vector<vector<int>>& adj) {
                    vis[node] = true;
                    for(auto &child: adj[node]) {
                        if(vis[child] == false)
                            dfs(child, vis, ans, adj);
                    }
                    ans.push_back(node);
                }

                vector<int> TopologicalSort(vector<vector<int>>& adj, int k) {
                    vector<bool> vis(k + 1);
                    vector<int> ans;
                    for(int i = 1; i <= k;i++) {
                        if(vis[i] == false) {
                            dfs(i, vis, ans, adj);
                        }
                    }
                    reverse(ans.begin(), ans.end());
                    return ans;
                }
            public:
                vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
                    int n = rowConditions.size();
                    int m = colConditions.size();
                    vector<vector<int>> rowAdj(k + 1), colAdj(k + 1), result(k, vector<int>(k));
                    buildGraph(rowConditions, rowAdj);
                    buildGraph(colConditions, colAdj);
                    bool cycle = (CheckCycle(rowAdj, k) & CheckCycle(colAdj, k));
                    if(cycle == false)
                        return {};
                    vector<int> rowOrder = TopologicalSort(rowAdj, k);
                    vector<int> colOrder = TopologicalSort(colAdj, k);
                    for(int i = 0; i < k;++i) {
                        for(int j = 0; j < k;++j) {
                            if(rowOrder[i] == colOrder[j]) {
                                result[i][j] = rowOrder[i];
                            }
                        }
                    }
                    return result;
                }
            };
        
    </details>

---




* [ ] [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                double BFS(int n, int st, int ed, vector<vector<pair<int, double>>>& adj) {
                    queue<pair<int, double>> bfs;
                    vector<double> dist(n, 0.00000);
                    bfs.push({st, 1.00000});
                    while(!bfs.empty()) {
                        auto node = bfs.front();
                        bfs.pop();
                        if(node.first == ed)
                            continue;
                        for(auto &child: adj[node.first]) {
                            if(dist[child.first] < node.second * child.second) {
                                dist[child.first] = node.second * child.second;
                                bfs.push({child.first, dist[child.first]});
                            }
                        }
                    }
                    return dist[ed];
                }
            public:
                double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
                    int m = edges.size();
                    vector<vector<pair<int, double>>> adj(n);
                    for(int i = 0; i < m;++i) {
                        int x = edges[i][0], y = edges[i][1];
                        double z = succProb[i];
                        adj[x].push_back({y, z});
                        adj[y].push_back({x, z});
                    }
                    return BFS(n, start_node, end_node, adj);
                }
            };
        
    </details>

---




* [ ] [Count Sub Islands](https://leetcode.com/problems/count-sub-islands/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                bool isValid(int x, int y, int n, int m) {
                    return (x >= 0 && x < n && y >= 0 && y < m);
                }
                bool DFS(int x, int y, int n, int m, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
                    if(!isValid(x, y, n, m) || grid2[x][y] == 0)
                        return true;
                    if( grid1[x][y] == 0 )
                        return false;
                    bool ret = true;
                    grid2[x][y] = 0; // instead of using extra space for visiting the cell, mark it with zero :)
                    for(int i = 0; i < 4;i++) {
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        ret &= DFS(newX, newY, n, m, grid1, grid2);
                    }
                    return ret;
                }
            public:
                int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
                    int n = grid1.size();
                    int m = grid1[0].size();
                    int totalIslands = 0;
                    for(int i = 0; i < n;++i) {
                        for(int j = 0; j < m;++j) {
                            if(grid1[i][j] == 1 && grid2[i][j] == 1) {
                                bool ret = DFS(i, j, n, m, grid1, grid2);
                                totalIslands += ret;
                            }
                        }
                    }
                    return totalIslands;
                }
            };
        
    </details>

---




* [ ] [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int DFS(int x, int y, unordered_map<int, vector<int>>& rows, 
                        unordered_map<int, vector<int>>& columns, 
                        map<pair<int, int>, bool>& vis) {
                    if(vis[{x, y}] == true)
                        return 0;
                    vis[{x, y}] = true;
                    int ret = 1;
                    for(auto &child: rows[x]) 
                        ret += DFS(x, child, rows, columns, vis);
                    for(auto &child: columns[y])
                        ret += DFS(child, y, rows, columns, vis);
                    return ret;
                }
            public:
                int removeStones(vector<vector<int>>& stones) {
                    int n = stones.size();
                    unordered_map<int, vector<int>> rows, columns;
                    map<pair<int, int>, bool> vis;
                    int maxStones = 0;
                    for(int i = 0; i < n;i++) {
                        int x = stones[i][0], y = stones[i][1];
                        rows[x].push_back(y);
                        columns[y].push_back(x);
                    }
                    for(int i = 0; i < n;i++) {
                        int cnt = DFS(stones[i][0], stones[i][1], rows, columns, vis);
                        if(cnt > 0)
                            maxStones += (cnt - 1);
                    }
                    return maxStones;
                }
            };
        
    </details>

---



* [ ] [Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/description/) 
    * <details>
        <summary> Solution </summary>

        ```c++
            class Solution {
                int dx[4] = {0, 1, 0, -1};
                int dy[4] = {1, 0, -1, 0};
                bool isValid(int i, int j, int n, int m) {
                    return (i >= 0 && i < n && j >= 0 && j < m);
                }

                bool dfs(int i, int j, int n, int m, vector<vector<bool>>& grid, vector<vector<int>>& dp) {
                    if(isValid(i, j, n, m) == false || grid[i][j] == true) return false;
                    if(i == n - 1) return true;
                    int& ret = dp[i][j];
                    if(~ret) return ret;
                    ret = false;
                    for(int k = 0; k < 4;k++) {
                        int newI = i + dx[k];
                        int newJ = j + dy[k];
                        ret |= dfs(newI, newJ, n, m, grid, dp);
                    }
                    return ret;
                }
            public:
                int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
                    int n = cells.size();
                    vector<vector<bool>> grid(row, vector<bool>(col, false));
                    int left = 0, right = n - 1, res = -1;
                    while(left <= right) {
                        int mid = left + (right - left) / 2;
                        for(int i = 0; i <= mid;i++)
                            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
                        bool canReach = false;
                        vector<vector<int>> dp(row, vector<int>(col, -1));
                        for(int i = 0; i < col;i++)
                            canReach |= dfs(0, i, row, col, grid, dp);
                        if(mid == 2) cout << canReach << endl;
                        if(canReach == true) {
                            res = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                        for(int i = 0; i <= mid;i++)
                            grid[cells[i][0] - 1][cells[i][1] - 1] = false;
                    }
                    return res + 1;
                }
            };
        
    </details>

---