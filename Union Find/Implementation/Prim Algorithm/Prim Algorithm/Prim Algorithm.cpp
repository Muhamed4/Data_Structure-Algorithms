
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;


const int OO = INT_MAX;

struct edge {
	int from, to, w;
	edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}
	bool operator<(const edge& e) const {
		return w > e.w;
	}
};

pair<int, vector<edge>> PRIM_MST1(vector<vector<int>>& adjMax) { // O(n^2)
	int curNode = 0, n = adjMax.size(), mini;
	int mind, mstCost = 0;
	vector<int> vis(n), prev(n);
	vector<int> dist(n, OO);
	vector<edge> edges;
	for (int k = 0; k < n - 1;k++) {
		vis[curNode] = 1;
		mind = OO;
		mini = -1;
		for (int i = 0; i < n;i++) {
			if (vis[i] == 0) {
				if (adjMax[curNode][i] < dist[i])
					dist[i] = adjMax[curNode][i], prev[i] = curNode;
				if (dist[i] < mind)
					mind = dist[i], mini = i;
			}
		}
		if (mini == -1) break;
		edges.push_back(edge(prev[mini], mini, adjMax[prev[mini]][mini]));
		curNode = mini;
		mstCost += dist[curNode];
	}
	if (edges.size() != n - 1) return make_pair(OO, vector<edge>());
	return make_pair(mstCost, edges);
}

pair<int, vector<edge>> PRIM_MST2(vector<vector<edge>>& adjList) { // O(E logV)
	int n = adjList.size();
	int mstCost = 0;
	vector<bool> vis(n, false);
	vector<edge> edges;
	priority_queue<edge> q;
	q.push(edge(-1, 0, 0));
	while (!q.empty()) {
		edge e = q.top();
		q.pop();
		if (vis[e.to] == true) continue;
		vis[e.to] = true;
		mstCost += e.w;
		if (e.to != 0)
			edges.push_back(e);
		for (auto& child : adjList[e.to]) {
			if (vis[child.to] == false)
				q.push(child);
		}
	}
	if (edges.size() != n - 1)
		return make_pair(OO, vector<edge>());
	return make_pair(mstCost, edges);
}



int main()
{

}

