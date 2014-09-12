#include "std.h"
#include <unordered_set>
class Solution {
public:
	const static int maxn = 11111;
	const static int maxm = 21111;
	const static int INF = 0x3f3f3f3f;
	struct EdgeNode {
		int to;
		int next;
	}edges[maxm];
	int head[maxn], edge;
	bool vis[maxn];
	queue<int>que;
	int dis[maxn];
	int N;
	void init() {
		edge = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v) {
		edges[edge].to = v, edges[edge].next = head[u], head[u] = edge++;
	}
	bool spfa(int s){
		int u;
		for (int i = 0; i <= N; i++) dis[i] = INF;
		memset(vis, 0, sizeof(vis));
		while (!que.empty()) que.pop();
		que.push(s);
		vis[s] = true;
		dis[s] = 0;
		while (!que.empty()){
			u = que.front();
			que.pop();
			vis[u] = false;
			for (int i = head[u]; i != -1; i = edges[i].next){
				int v = edges[i].to;
				if (dis[v] == INF || dis[v]>dis[u] + 1){
					dis[v] = dis[u] + 1;
					if (!vis[v]){
						vis[v] = true;
						que.push(v);
					}
				}
			}
		}
		return true;
	}
	bool check(const string &u, const string &v) {
		int n = u.size();
		int m = v.size();
		if (n != m) return false;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (u[i] != v[i]) cnt++;
		}
		return cnt == 1;
	}
	vector<string> a;
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		init();
		for (auto it = dict.begin(); it != dict.end(); it++) a.push_back(*it);
		int n = dict.size();
		N = n + 1;
		
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == start) s = i;
		}
		int e = n + 1;
		for (int i = 0; i < n; i++) {
			if (a[i] == end) e = i;
		}

		int i, j;
		i = 1;
		for (auto it = dict.begin(); it != dict.end(); it++) {
			if (s == 0 && check(start, *it)) {
				addedge(s, i);
				addedge(i, s);
			}
			if (e == n + 1 && check(*it, end)) {
				addedge(i, e);
				addedge(e, i);
			}
			i++;
		}

		i = 1;
		for (auto it = dict.begin(); it != dict.end(); it++) {
			j = 1;
			for (auto it2 = dict.begin(); it2 != dict.end(); it2++) {
				if (it != it2) {
					if (check(*it, *it2)) {
						addedge(i, j);
						addedge(j, i);
					}
				}
				j++;
			}
			i++;
		}
		spfa(s);
		return dis[e];
	}
};