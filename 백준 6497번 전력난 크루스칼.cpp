#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
	int u, v, w;
};

bool cmp(const edge &p1, const edge &p2) {
	return p1.w < p2.w;
}

int n, m;
int parent[200001];
int level[200001];
int a, b, c, total = 0, sum = 0;

vector<edge>v;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	if (level[u] > level[v]) swap(u, v);

	parent[u] = v;

	if (level[u] == level[v]) level[v]++;
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//freopen("dark.in", "r", stdin);
	while (1) {
		cin >> m >> n;
		if (n == 0 && m == 0) break;
		
		for (int i = 0; i < m; i++) {
			parent[i] = i;
			level[i] = 1;
		}

		total = 0;
		
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			v.push_back({ a, b, c });
			total += c;
		}
		
		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++) {
			if (merge(v[i].u, v[i].v)) {
				total -= v[i].w;
			}
		}
		v.clear();
		cout << total << "\n";
	}
	return 0;
}