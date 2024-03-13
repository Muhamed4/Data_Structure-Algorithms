#include <bits/stdc++.h>
using namespace std;

#define V 9

vector<vector<int>> adj;
int n, s;


struct node{
    int to, weight;
};


vector<node> edges[V];

void zeroOneBFS(int src){
    int dist[V];
    for(int i = 0; i < V;i++){
        dist[i] = INT_MAX;
    }

    deque<int> bfs;
    bfs.push_back(src);
    dist[src] = 0;

    while(!bfs.empty()){
        int v = bfs.front();
        bfs.pop_front();
        for(auto &child: edges[v]){
            if(dist[child.to] > dist[v] + child.weight){
                dist[child.to] = dist[v] + child.weight;
                if(child.weight == 0)
                    bfs.push_front(child.to);
                else
                    bfs.push_back(child.to);
            }
        }
    }

    for(int i = 0; i < V;i++){
        cout << dist[i] << ' ';
    }
}

void addEdge(int u, int v, int w){
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
}

void Solve2(){
    addEdge(0, 1, 0); 
    addEdge(0, 7, 1); 
    addEdge(1, 7, 1); 
    addEdge(1, 2, 1); 
    addEdge(2, 3, 0); 
    addEdge(2, 5, 0); 
    addEdge(2, 8, 1); 
    addEdge(3, 4, 1); 
    addEdge(3, 5, 1); 
    addEdge(4, 5, 1); 
    addEdge(5, 6, 1); 
    addEdge(6, 7, 1); 
    addEdge(7, 8, 1); 
    int src = 0;//source node 
    zeroOneBFS(src); 
}



void Solve1(){
    int n, edges;
    cin >> n >> edges;
    adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> bfs;
    bfs.push(s);
    vector<bool> used(n);
    vector<int> distance(n), parent(n);
    used[s] = true;
    parent[s] = -1;
    while (!bfs.empty())
    {
        int node = bfs.front();
        bfs.pop();
        for (auto &child : adj[node])
        {
            if (!used[child])
            {
                used[child] = true;
                bfs.push(child);
                distance[child] = distance[node] + 1;
                parent[child] = node;
            }
        }
    }
    int to = 4;
    vector<int> path;

    for (int v = to; v != -1 && used[to]; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for(auto &it: path){
        cout << it << ' ';
    }
    cout << '\n';
}


int main(){
    Solve2();
}