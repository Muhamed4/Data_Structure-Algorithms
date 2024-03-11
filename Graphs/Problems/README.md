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

