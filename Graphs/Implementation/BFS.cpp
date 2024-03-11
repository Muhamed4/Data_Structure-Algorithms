#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, s;
int main()
{
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

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << distance[i] << endl;
    // }
}