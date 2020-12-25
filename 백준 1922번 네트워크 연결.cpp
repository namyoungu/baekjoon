#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int value;
	int u, v;
};

int parent[1001];
int level[1001];
int n, m;

vector<node> v;

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	if (level[u] > level[v]) swap(u, v);

	parent[u] = v;

	if (level[u] == level[v]) level[v]++;
}

bool same(int u, int v) {
	if (find(u) == find(v)) return true;
	return false;
}

bool cmp(const node &p1, const node &p2) {
	if (p1.value < p2.value) return true;
	else return false;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({c, a, b});
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i < n + 1; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		node t = v[i];
		if (!same(t.u, t.v)) {
			merge(t.u, t.v);
			sum += t.value;
		}
	}
	printf("%d\n", sum);
}