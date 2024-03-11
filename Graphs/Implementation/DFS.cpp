#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> time_in, time_out; // "times" of entry and exit from the vertex
int dfs_timer = 0;             // timer for determining times

void dfs(int v)
{
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (auto &child : adj[v])
    {
        if (color[child] == 0)
            dfs(child);
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}


bool *used;
vector<int> comp; 
void DFS(int node){
    used[node] = true;
    comp.push_back(node);
    for(auto &child: adj[node]){
        if(used[child] == false)
            DFS(child);
    }
}

void find_comps(int n){
    for(int i = 0; i < n;i++){
        if(used[i] == false){
            comp.clear();
            DFS(i);
            cout << "Component:";
            for(auto &it: comp){
                cout << ' ' << it;
            }
            cout << '\n';
        }
    }
}

void Solve2(){
    int n, m;cin >> n >> m;
    used = new bool[n]{0};
    adj = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_comps(n);
    delete[] used;
}

void Solve1(){
    int n;cin >> n;
    int edges;
    cin >> edges;
    adj = vector<vector<int>>(n, vector<int>());
    time_in = time_out = color = vector<int>(n);
    for (int i = 0; i < edges; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << time_in[i] << ' ' << time_out[i] << endl;
    }
}

int main(){

    Solve2();
    
    return 0;
}