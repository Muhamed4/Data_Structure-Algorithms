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



void dfs(int node, vector<bool>&vis, vector<vector<int>>&adj, vector<int>&ans){
    vis[node] = 1;
    for(auto &child: adj[node]){
        if(!vis[child]){
            dfs(child, vis, adj, ans);
        }
    }
    ans.push_back(node);
}

vector<int> topological_sort(int n, vector<vector<int>>&adj){
    vector<bool>vis(n);
    vector<int> ans;
    for(int i = 0; i < n;i++){
        if(!vis[i]){
            dfs(i, vis, adj, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


void Solve3(){
    int n,m;cin >> n >> m;
    vector<vector<int>>adj(n, vector<int>());
    for(int i = 0; i < m;i++){
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = topological_sort(n, adj);
    for(auto &it: ans){
        cout << it << ' ';
    }
    cout << '\n';
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

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

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

    // Solve3();

    Node* head = new Node(2);
    head->left = new Node(4);
    head->right = new Node(5);

    Node* test = new Node(10);

    Node* temp = head;
    temp->left = test;
    cout << head->left->val;

    
    return 0;
}