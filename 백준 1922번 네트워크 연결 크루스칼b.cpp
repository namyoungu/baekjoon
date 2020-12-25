#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int u, v, w;
};

int n, m;
int parent[100001];

vector<point> v;

bool cmp(const point &p1, const point &p2) {
	return p1.w < p2.w;
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	parent[u] = v;
	return true;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({a, b, c});
	}
	sort(v.begin(), v.end(), cmp);

	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		if (merge(v[i].u, v[i].v)) {
			res += v[i].w;
		}
	}
	printf("%d\n", res);
	return 0;
}