

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


const int mod = 1e9 + 7;
// NCR 
ll nCr(ll n, ll r){
	ll ans = 1;
	ll div = 1; // r! 
	for (ll i = r + 1; i <= n; i++){
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}
// NPR 
ll NpR(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= mod;
	}
	return ans;
}



// Fast Power 
ll power(ll x, ll k)
{
	ll ret = 1;
	while (k){
		if (k & 1) ret = (ret*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret;
} 
int md(int val, int md){
	return (val%md + md) % md;
}
 
 // (a / b) % mod = (a% mod) * (b%mod) ^ mod - 2
 
// Calulate Mod Inv 
ll inv(ll a, ll m){
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
		return 0;
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
		x1 += m0;
	return x1;
}
 
 
// Modular inverse of the given number modulo m
 
int modInverse(int a, int m) {
	return power(a, m - 2);
}





ll Extended_Euclidean(ll a , ll b , ll &x , ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1 , y1;
    ll d = Extended_Euclidean(b , a % b , x1 , y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

// Returns the Bezout's coefficients of the smallest positive linear combination of a and b
// using the extended Euclidean algorithm.
// (i.e. GCD(a, b) = s.a + t.b).
// O(GCD(a, b)) = O(log(n))
pair<int, int> extendedEuclid(int a, int b) {
	if (b == 0) {
		return{ 1, 0 };
	}
 
	pair<int, int> p = extendedEuclid(b, a % b);
 
	int s = p.first;
	int t = p.second;
 
	return{ t, s - t * (a / b) };
}



const int N = 1e6;
bool prime[N];
// sieve check all primes numbers from 1 to N  O(Nlog N)
void  sieve_v1(){
	for (int i = 0; i < N; i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 2; i < N; i++){
		if (prime[i]){
			for (int j = i * 2; j < N; j += i){
				prime[j] = 0;
			}
		}
	}
}
//very fast less than Nlog N
void  sieve_v2(){
	for (int i = 0; i < N; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 4; i < N; i += 2){
		prime[i] = 0;
	}
	for (int i = 3; i * i < N; i += 2){
		if (prime[i]){
			for (int j = i * i; j < N; j += i + i){
				prime[j] = 0;
			}
		}
	}
}
// Generates all the prime divisors of the numbers from 1 to n.
vector<int> primeDivs[N];
void generatePrimeDivisors(int n) {
	for (int i = 2; i <= n; ++i) {
		if (primeDivs[i].size()) continue;
 
		for (int j = i; j <= n; j += i) {
			primeDivs[j].push_back(i);
		}
	}
}
 
 
// Generates all the divisors of the numbers from 1 to n.
vector<int> divs[N];
void generateDivisors(int n) {
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; j += i)
			divs[j].push_back(i);
	}
}
// function to calculate all the prime factors and 
// count of every prime factor
void factorize(long long n){
	int count = 0;
	while (!(n % 2)) {
		n >>= 1;
		count++;
	}
	if (count)
		cout << 2 << "  " << count << endl;
	for (long long i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++; n = n / i;
		}
		if (count)
			cout << i << "  " << count << endl;
	}
	if (n > 2)
		cout << n << "  " << 1 << endl;
}
// Calculate Prime factors faster 
void Prime_Factors_Faster(int n){
	vector<int>primes;
	sieve_v2();
	for (int i = 2; i < N; i++){
		if (prime[i]){
			primes.push_back(i);
		}
	}
	// if number is prime
	if (prime[n]){
		cout << n << " " << 1 << endl;
		return;
	}
	int idx = 0;
	while (idx < primes.size() && primes[idx] * primes[idx] <= n){
		int cnt = 0;
		while (n % primes[idx] == 0){
			n /= primes[idx];
			cnt++;
		}
		if (cnt) cout << primes[idx] << " " << cnt << endl;
		idx++;
	}
	if (n>1){
		cout << n << " " << 1 << endl;
	}
}
 
//// number of divisors 
//a = p^e1 * p ^ e2 * p^ e3  ,,, = product of all ( ei + 1)
 
 
int factN_PrimePower(int n, int p){
	int pow = 0;
	for (int i = 0; i <= n; i *= p){
		pow += n / i;
	}
	return pow;
}
 
ll get_sum_div(ll x){
	ll ans = 0;
	for (ll left = 1, right; left <= x; left = right + 1){
		right = x / (x / left);
		ans += (x / left)*(left + right)*(right - left + 1) / 2;
	}
	return ans;
}

// BitMasks

#define ll long long
 
bool getBit(ll num, int idx) {
	return ((num >> idx) & 1);
}
 
ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
 
ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}
 
ll leastBit(ll num) {
	return (num & -num);
}
 
//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
	return (num & mod - 1);
}
 
bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}
 
int turnOnLastZero(int S) {
	return S | S + 1;
}
 
int turnOffLastBit(int S) {
	return S & S - 1;
}
 
int turnOnLastConsecutiveZeroes(int S) {
	return S | S - 1;
}
 
int turnOffLastConsecutiveBits(int S) {
	return S & S + 1;
}
 
vector<int> genAllSubmask(int mask) {
	vector<int> v;
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		v.push_back(subMask);
		if (subMask == 0)
			break;
	}
	return v;
}
 
// for run __builtin_popcount in visual studio
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif


// Mod Inverse :
ll fact[N];
ll fpow(ll n, ll x) {
    if (x == 0) {
        return 1;
    }
    if (x == 1) {
        return n % mod;
    }
    ll ans = fpow(n, x / 2) % mod;
    ans = (ans % mod) * (ans % mod) % mod;
    if (x & 1) {
        ans = (ans % mod) * (n % mod) % mod;
    }
    return ans;
}
ll nCr(ll n, ll r) {
    ll res1 = fpow(fact[r], mod - 2);
    ll res2 = fpow(fact[n - r], mod - 2);
    ll res3 = fact[n];
    ll ans = (((res1 % mod) * (res2 % mod) % mod) * (res3 % mod) % mod);
    return ans;
}
fact[0] = 1;
for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
}

// Search for connected components in a graph

int n;
vector<int> g[MAXN] ;
bool used[MAXN] ;
vector<int> comp ;

void dfs(int v) {
    used[v] = true ;
    comp.push_back(v);
    for (size_t i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 0; i < n ; ++i)
        used [i] = false;
    for (int i = 0; i < n ; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (size_t j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl ;
        }
}


//BFS

vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}

if (!used[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}



// topological_sort

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}




// 0-1 BFS (Shortest Path in a Binary Weight Graph)

// C++ program to implement single source
// shortest path for a Binary Graph
#include<bits/stdc++.h>
using namespace std;

/* no.of vertices */
#define V 9

// a structure to represent edges
struct node
{
	// two variable one denote the node
	// and other the weight
	int to, weight;
};

// vector to store edges
vector <node> edges[V];

// Prints shortest distance from given source to
// every other vertex
void zeroOneBFS(int src)
{
	// Initialize distances from given source
	int dist[V];
	for (int i=0; i<V; i++)
		dist[i] = INT_MAX;

	// double ende queue to do BFS.
	deque <int> Q;
	dist[src] = 0;
	Q.push_back(src);

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop_front();

		for (int i=0; i<edges[v].size(); i++)
		{
			// checking for the optimal distance
			if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight)
			{
				dist[edges[v][i].to] = dist[v] + edges[v][i].weight;

				// Put 0 weight edges to front and 1 weight
				// edges to back so that vertices are processed
				// in increasing order of weights.
				if (edges[v][i].weight == 0)
					Q.push_front(edges[v][i].to);
				else
					Q.push_back(edges[v][i].to);
			}
		}
	}

	// printing the shortest distances
	for (int i=0; i<V; i++)
		cout << dist[i] << " ";
}

void addEdge(int u, int v, int wt)
{
edges[u].push_back({v, wt});
edges[v].push_back({u, wt});
}

// Driver function
int main()
{
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
	return 0;
}






const int OO = 1e9;

struct edge{
    int from , to , w;
    edge(int from , int to , int w): from(from) , to(to) , w(w) {}

    bool operator < (const edge & e)const {
        return w > e.w;
    }
};

int Dijkstra(vector<vector<edge>>list , int src , int dest = -1){
    int n = list.size();
    vector<int>dist(n , OO) , prev(n , -1);
    dist[src] = 0;
    priority_queue<edge>q;
    q.push(edge(-1 , src , 0));
    while(!q.empty()){
        edge e = q.top();
        q.pop();
        if(e.w > dist[e.to])skip;
        prev[e.to] = e.from;
        for(int i = 0 ; i < list[e.to].size();i++){
            edge ne = list[e.to][i];
            if(dist[ne.to] > dist[ne.from] + ne.w){
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                q.push(ne);
            }
        }
    }
    return dest == -1 ? -1 : dist[dest];
}







int Dijkstra(vector<vector<pair<int,int>>>adj, int src , int dis){
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>shortest_path;
    const int N = 10004;
    const int OO = 1e9;
    bool vis[N];
    memset(vis , false , sizeof(vis));
    vector<int>dist(N , OO);
    shortest_path.push({0 , src});
    dist[src] = 0;
    while(!shortest_path.empty()){
        pair<int,int>node = shortest_path.top();
        shortest_path.pop();
        vis[node.second] = 1;
        for(int i = 0 ; i < adj[node.second].size();i++){
            if(!vis[adj[node.second][i].first] && dist[adj[node.second][i].first] > adj[node.second][i].second + dist[node.second]){
                dist[adj[node.second][i].first] = adj[node.second][i].second + dist[node.second];
                shortest_path.push({dist[adj[node.second][i].first] , adj[node.second][i].first});
            }
        }
    }
    return dist[dis];
}

//Floyed Warshall
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}







const int N = 1000006;


struct edge{
    int from , to , w;
    edge(int from , int to , int w): from(from) , to(to) , w(w) {}

    bool operator < (const edge & e)const {
        return w > e.w;
    }
};
int parent[N];
int GroupSize[N];
struct DSU{
    DSU(){
        for(int i = 0 ; i < N;i++){
            parent[i] = i;
            GroupSize[i] = 1;
        }
    }
    int FindLeader(int i){
        if(parent[i] == i) return i;
        return parent[i] = FindLeader(parent[i]);
    }
    bool SameGroup(int x , int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    void MergeGroups(int x , int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2) return;

        if(GroupSize[leader1] > GroupSize[leader2]){
            parent[leader2] = leader1;
            GroupSize[leader1] += GroupSize[leader2];
        }
        else{
            parent[leader1] = leader2;
            GroupSize[leader2] += GroupSize[leader1];
        }
    }
	int GetSize(int x){
		int leader = FindLeader(x);
		return GroupSize[leader];
	}
};


const int N = 120;
int parent[N] , GroupSize[N] , n , m;
int FindLeader(int u){
    if(parent[u] == u)return u;
    return parent[u] = FindLeader(parent[u]);
}
void Merge(int u , int v){
    int Leader1 = FindLeader(u);
    int Leader2 = FindLeader(v);
    if(Leader1 == Leader2)return ;
    if(GroupSize[Leader1] > GroupSize[Leader2]){
        parent[Leader2] = Leader1;
        GroupSize[Leader1] += GroupSize[Leader2];
    }
    else{
        parent[Leader1] = Leader2;
        GroupSize[Leader2] += GroupSize[Leader1];
    }
}
bool SameGroup(int u , int v){
    return FindLeader(u) == FindLeader(v);
}
struct edge{
    int from , to , w;
    edge(int from , int to , int w): from(from) , to(to) , w(w) {}

    bool operator < (const edge & e)const {
        return w > e.w;
    }
};
vector<edge>adj;
pair<int,vector<edge>>MST_Kruskal(vector<edge>adj2){
    priority_queue<edge>q;
    vector<edge> edges;
    int mstCost = 0;
    for(auto child : adj2){
        q.push(child);
    }
    while(!q.empty()){
        edge e = q.top();q.pop();
        if(!SameGroup(e.from , e.to)){
            Merge(e.from , e.to);
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if(edges.size() != n - 1){
        return make_pair(-1 , edges);
    }
    else{
        return make_pair(mstCost , edges);
    }
}
void Ini(){
    for(int i = 0 ; i < N;i++){
        parent[i] = i;
        GroupSize[i] = 1;
    }
}


// Find MST  value & edges. adjMax is initialized by OO
pair<int,vector<edge>>PRIM_MST1(vector<vector<int>>adjMax){ // o(n ^ 2)
    int CurNode = 0 , n = adjMax.size() , mini;
    int mind , mstCost = 0
    vector<int> vis(n , 0) , prev(n);
    vector<int>dist(n , OO); // dist[i] : Minimum value to connect i to current built tree
    vector<edge>edges; // save MST edges
    for(int k = 0 ; k < n ;k++){
        vis[CurNode] = 1 ,mind = OO , mini = -1;
        for(int i = 1; i <= n;i++){
            if(!vis[i]){
                if(adjMax[CurNode][i] < dist[i]) // Update if i can reach tree with a new Minimum value
                    dist[i] = adjMax[CurNode][i] , prev[i] = CurNode;
                
                if(dist[i] < mind) mind = dis[i] , min = i; // Select minimum EDGE  value
            }
        }
        if(mini == -1)break; // check if graph is disconnected
        // Update edges and cost of mst
        edges.push_back(edge(prev[mini] , mini , adjMax[prev[mini][mini]]));
        CurNode = mini , mstCost += dist[CurNode];
    }
    if(edges.size() != n-1){
        return make_pair(OO , vector<edge>());
    }
    return make_pair(mstCost , edges);
}





// Find MST  value & edges.
pair<int,vector<edge>>PRIM_MST2(vector<vector<edge>>adjlist){//o(E logV)
    int n = adjlist.size() , mstCost = 0;
    vector<int>vis(n , 0);
    vector<edge>edges; // Save MST edges
    priority_queue<edge>q; // priority_queue to sort edges
    q.push(edge(-1 , 0 , 0));
    while(!q.empty()){
        edge e = q.top();
        q.pop();
        if(vis[e.to])continue;
        vis[e.to] = 1;
        mstCost += e.w;
        if(e.to){
            edges.push_back(e); // remove min element & update cost / list
        }
        for(auto child : adjlist[e.to]){
            edge ne = child;
            if(!vis[ne.to]){
                q.push(ne);
            }
        }
    }
    if(edges.size() != n-1){
        return make_pair(-OO , vector<edge>());
    }
    return make_pair(mstCost , edges);
}

// formula to calculate the sum of square numbers in range [1,n]
// 1^2 + 2^2 + 3^2 + 4^2 + 5^2 = (n * (n + 1 ) * (2 * n + 1) / 6) --> n = 5






// HASHING 

const int MAX_CHAR = 26;

struct Trie{
    Trie *child[MAX_CHAR];
    bool isLeaf;
    Trie(){
        isLeaf = false;
        memset(child, 0, sizeof child);
    }

    void insert(char *str){
        if(*str == '\0'){
            isLeaf = true;
        }
        else{
            int cur = *str - 'a';
            if(child[cur] == 0){
                child[cur] = new Trie();
            }
            child[cur]->insert(str + 1);
        }
    }

    bool WordExist(char* str){
        if(*str == '\0'){
            return isLeaf;
        }
        int cur = *str - 'a';
        if(child[cur] == 0){
            return false; // such path don't exist
        }
        return child[cur]->WordExist(str + 1);
    }

    bool PrefixExist(char* str){
        if(*str == '\0'){
            return true;
        }
        int cur = *str - 'a';
        if(child[cur] == 0){
            return false; // such path don't exist
        }
        return child[cur]->PrefixExist(str + 1);
    }
};





// kadane's algorithm 2D
int kadane2D(vector<vector<int>>&A){
    int n = A.size() , m = A[0].size();
    int max_sum = -oo , cur_sum = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ;j++){
            cur_sum += A[i][j];
            if(cur_sum < 0){
                cur_sum = 0;
            }
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}





int n;cin >> n;
vector<vector<int>>v(n + 1 , vector<int>(n + 1));
for(int i = 1; i <= n;i++){
    for(int j = 1; j <= n;j++){
        cin >> v[i][j];
    }
}
int ans = -1e9;
for(int i = 1; i <= n;i++){
    vector<int>res(n + 1);
    for(int j = i; j <= n;j++){
        for(int k = 1; k <= n;k++){
            res[k] += v[k][j];
        }
        vector<int>cnt(n + 1);
        for(int k = 1; k <= n;k++){
            cnt[k] = max(res[k] , res[k] + cnt[k - 1]);
        }
        int fin = *max_element(all(cnt));
        ans = max(ans , fin);
    }
}






// Segment Tree 

struct Segment_Tree_MIN {
    vector<int> tree , a;
    Segment_Tree(int n){
        tree.assign(4 * n, 0);
        a.assign(n + 1, 0);
    }

    void build(int p , int s , int e){
        if(s == e){
            tree[p] = a[s];
        }
        build(p * 2 , s , (s + e) / 2);
        build(p * 2 + 1 , (s + e) / 2 + 1 , e);
        tree[p] = min(tree[p * 2] , tree[p * 2 + 1]);
    }

    void update(int p , int s , int e , int idx , int val){
        if(s == e){
            tree[p] = val;
            a[s] = val;
            return;
        }
        if(idx <= (s + e) / 2){
            update(p * 2 , s , (s + e) / 2 , idx , val);
        }
        else{
            update(p * 2 + 1 , (s + e) / 2 + 1 , e , idx , val);
        }
        tree[p] = min(tree[p * 2] , tree[p * 2 + 1]);
    }

    int get(int p , int s , int e , int l , int r){
        if(s >= l && e <= r){
            return tree[p];
        }
        if(s > r || e < l){
            return INT_MAX;
        }
        return min(get(p * 2 , s , (s + e) / 2 , l , r) , get(p * 2 + 1 , (s + e) / 2 + 1 , e , l , r));
    }
};


// segment tree lazy propagation

ll seg[400005] , lazy[400005];
int l , r , val;
void check(int n , int s , int e){
    seg[n] += (e - s + 1) * lazy[n];
    if(s != e){
        lazy[2 * n] += lazy[n];
        lazy[2 * n + 1] += lazy[n];
    }
    lazy[n] = 0;
}

void update(int n , int s , int e){
    check(n , s , e);
    if(s > r || e < l)return;
    if(s >= l && e <= r){
        lazy[n] = val;
        check(n , s , e);
        return;
    }
    update(2 * n , s , (s + e) / 2);
    update(2 * n + 1 , (s + e) / 2 + 1 , e);
    seg[n] = seg[2 * n] + seg[2 * n + 1];
}

ll get(int n , int s , int e){
    check(n , s , e);
    if(s > r || e < l)return 0;
    if(s >= l && e <= r)return seg[n];
    return get(2 * n , s , (s + e) / 2) + get(2 * n + 1 , (s + e) / 2 + 1 , e);
}
void solve(){
    int n , q;cin >> n >> q;
    for(int i = 0 ; i <= 4 * n;i++){
        seg[i] = lazy[i] = 0;
    }
    while(q--){
        int type;cin >> type >> l >> r;
        if(!type) {
            cin >> val;
            update(1 , 1 , n);
        }
        else cout << get(1 , 1, n) << endl;
    }
}




// Matrix chain multiplication 
// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
 
// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k)
                     + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);
}



// Checking a graph for acyclicity and finding a cycle in o(n) --> directed graph

int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}





// Check whether a graph is bipartite

int n;
vector<vector<int>> adj;

vector<int> side(n, -1);
bool is_bipartite = true;
queue<int> q;
for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
        q.push(st);
        side[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    is_bipartite &= side[u] != side[v];
                }
            }
        }
    }
}

cout << (is_bipartite ? "YES" : "NO") << endl;







// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;






// Queries of nCr%p in O(1) time complexity

// C++ program to answer queries
// of nCr in O(1) time.
#include <bits/stdc++.h>
#define ll long long
const int N = 1000001;
using namespace std;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
	factorialNumInverse[0] = factorialNumInverse[1] = 1;

	// precompute inverse of natural numbers
	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
	fact[0] = 1;

	// precompute factorials
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factorialNumInverse[R])
			% p * factorialNumInverse[N - R])
			% p;
	return ans;
}

// Driver Code
int main()
{
	// Calling functions to precompute the
	// required arrays which will be required
	// to answer every query in O(1)
	ll p = 1000000007;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);

	// 1st query
	ll N = 15;
	ll R = 4;
	cout << Binomial(N, R, p) << endl;

	// 2nd query
	N = 20;
	R = 3;
	cout << Binomial(N, R, p) << endl;

	return 0;
}



// Knuth - Morris - Pratt (KMP)

vector<int> computePrefix(string pat){
    int m = pat.size();
    vector<int>longestPrefix(m);
    for(int i = 1, k = 0; i < m;i++){
        //as long as we can't add one more character in k, get best next prefix in p
        while(k > 0 && pat[k] != pat[i]){
            k = longestPrefix[k - 1];
        }
        if(pat[k] == pat[i])longestPrefix[i] = ++k;
        else longestPrefix[i] = k;
    }
    return longestPrefix;
}

bool KMP(string str , string pat){
    int n = str.size();
    int m = pat.size();
    vector<int>longestPrefix = computePrefix(pat);
    bool found = 0;
    for(int i = 1 , k = 0; i < n;i++){
        //as long as we can't add one more character in k, get best next prefix in p
        while(k > 0 && pat[k] != str[i]){
            k = longestPrefix[k - 1];
        }
        //if we match character in the pattern, move in pattern
        if(pat[k] == str[i])k++;
        //if we matched, print it and let's find one more matching
        if(k == m){
            if(i != n - 1)return 1;
            k = longestPrefix[k - 1]; // fail to next best suffix
        }
    }
    return 0;
}

void solve(){
    string str; cin >> str;
	auto g = computePrefix(str);
    int sz = g.back();
    string pat = str.substr(0 , sz);
    cout << pat << endl;
    while(sz > 0){
        if(KMP(str , pat)){
            cout << pat << endl;
            return;
        }
        g = computePrefix(pat);
        sz = g.back();
        pat = str.substr(0 , sz);
    }
    cout << "Just a legend" << endl;
}






// Point in Polygon

typedef complex<double> point;
#define EPS 1e-9 
#define OO 1e9 
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r)*exp(point(0, (t))))
#define angle(v)  (atan2((v).Y, (v).X))
#define length(v)  ((double)hypot((v).Y, (v).X))
#define lengthSqr(v)  (dot(v, v))
#define dot(a, b)  ((conj(a) * (b)).real())
#define cross(a, b)  ((conj(a) * (b)).imag())
#define rotate(v, t)  (polar(v, t))
#define rotateabout(v, t, a) (rotate(vec(a, v), t) + (a))
#define reflect(p, m)  ((conj((p) / (m))) * (m))
#define normalize(p)  ((p) / length(p))
#define same(a, b) (lengthSqr(vec(a, b)) < EPS)
#define mid(a, b) (((a) + (b)) / point(2, 0)) 
#define sz(s) (int)s.size()
#define colliner pointOnLine
#define perp(a) (point(-(a).Y, (a).X))
    
enum STATE
{
    IN,
    OUT,
    BOUNDRY
};
bool pointOnLine(const point &a, const point &b, const point &p)
{
    // degenerate case: line is a point
    return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}
bool pointOnRay(const point &a, const point &b, const point &p)
{
    // IMP NOTE: a,b,p must be collinear
    return dot(vec(a, p), vec(a, b)) > -EPS;
}
bool pointOnSegment(const point &a, const point &b, const point &p)
{
    // el satr da momken y3mel precision error
    if (!colliner(a, b, p))
        return 0;
    return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}
bool intersect(const point &a, const point &b,
                const point &p, const point &q, point &ret)
{
    // handle degenerate cases (2 parallel lines, 2 identical lines, line is 1 point
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    if (fabs(d1 - d2) > EPS)
        return 1;
    return 0;
}
STATE pointInPolygon(const vector<point> &p, const point &pnt)
{
    point p2 = pnt + point(1, 0);
    int cnt = 0;
    for (int i = 0; i < sz(p); i++)
    {
        int j = (i + 1) % sz(p);
        if (pointOnSegment(p[i], p[j], pnt))
            return BOUNDRY;
        point r;
        if (!intersect(pnt, p2, p[i], p[j], r))
            continue;
        if (!pointOnRay(pnt, p2, r))
            continue;
        if (same(r, p[i]) || same(r, p[j]))
            if (fabs(r.Y - min(p[i].Y, p[j].Y)) < EPS)
                continue;
        if (!pointOnSegment(p[i], p[j], r))
            continue;
        cnt++;
    }
    return cnt & 1 ? IN : OUT;
}



// Tarjan SCC

const int N = 10004;
vector<vector<int>>adj;
int dfn[N] , low_link[N] , in_stack[N] , comp[N], dnf , n , m , q , yes[N] , othdfn;
stack<int>st;
vector<vector<int>>scc;
void dfs(int node , int par){
    dfn[node] = low_link[node] = ++dnf , in_stack[node] = 1;
    st.push(node);
    for(auto child : adj[node]){
        if(!dfn[child]){
            dfs(child , node);
            low_link[node] = min(low_link[node] , low_link[child]);
        }
        else if(in_stack[child] && child != par){
            low_link[node] = min(low_link[node] , dfn[child]);
        }
    }
    if(low_link[node] == dfn[node]){
        scc.push_back(vector<int>());
        while(!st.empty()){
            int x = st.top();st.pop();
            in_stack[x] = 0;
            scc.back().push_back(x);
            comp[x] = scc.size() - 1;
            if(x == node)break;
        }
    }
}
void sol(int node){
    if(yes[node])return;
    yes[node] = othdfn;
    for(auto child : adj[node]){
        if(comp[child] != comp[node])sol(child);
    }
}

void solve(){
    while(cin >> n >> m >> q && n && m && q){
        memset(dfn , 0 , sizeof(dfn));
        memset(low_link , 0 , sizeof(low_link));
        memset(in_stack , 0 , sizeof(in_stack));
        memset(yes , 0 , sizeof(yes));
        adj.clear(); adj.resize(n + 10); scc.clear(); dnf = othdfn = 0;
        for(int i = 0 ; i < m;i++){
            int u , v;cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n;i++){
            if(!dfn[i])dfs(i , -1);
        }
        for(int i = 1; i <= n;i++){
            if(!yes[i]){
                ++othdfn;
                sol(i);
            }
        }
        while(q--){
            int src , des;cin >> src >> des;
            cout << (yes[src] == yes[des] ? "Y" : "N") << endl;
        }
        cout << "-\n";
    }
}