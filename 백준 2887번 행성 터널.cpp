#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

struct point {
	int x, y, z;
};

int n;
int parent[100001];

vector<point> v;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	u = v;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({a, b, c});
	}

	for (int i = 0; i < n; i++) {
		int t = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			t = min(abs(v[i].x - v[j].x), abs(v[i].y - v[j].y), abs(v[i].z - v[j].z));
		}

	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	return 0;
}