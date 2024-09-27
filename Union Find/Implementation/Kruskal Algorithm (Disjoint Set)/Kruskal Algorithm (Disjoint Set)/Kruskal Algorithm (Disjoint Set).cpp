
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int OO = INT_MAX;

struct UnionFind {
	vector<int> rank, parent;
	int forests;
	
	UnionFind(int n) {
		rank = parent = vector<int>(n);
		forests = n;
		for (int i = 0; i < n;i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y] += 1;
	}

	bool union_sets(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if (x != y) {
			link(x, y);
			forests -= 1;
		}
		return x != y;
	}

	bool same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}

	vector<vector<int>> connected_components() {
		int n = parent.size();
		vector<vector<int>> list(n);
		for (int i = 0; i < n;i++)
			list[find_set(i)].push_back(i);
		return list;
	}
};


struct edge {
	int from, to, w;

	edge(int _from, int _to, int _w): from(_from), to(_to), w(_w) {}

	bool operator<(const edge& e) const {
		return w > e.w;
	}
};


pair<int, vector<edge>> MST_Kruskal(vector<edge>& adj, int n) { // O(E logV)
	UnionFind DS(n);
	vector<edge> edges;		// Save MST edges
	int mstCost = 0;
	priority_queue<edge> q;
	for (auto& child : adj)
		q.push(child);
	while (!q.empty()) {
		edge e = q.top();
		q.pop();
		if (DS.union_sets(e.from, e.to) == true) {
			mstCost += e.w;
			edges.push_back(e);
		}
	}

	if (edges.size() != n - 1)
		return make_pair(-OO, vector<edge>());
	return make_pair(mstCost, edges);
}

int main()
{

}
