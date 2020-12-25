//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int parent[200];
//int level[200];
//
//int n, m;
//
//int find(int u) {
//	if (u == parent[u]) {
//		return u;
//	}
//	else {
//		parent[u] = find(parent[u]);
//		return parent[u];
//	}
//}
//
//void merge(int u, int v) {
//	u = find(u);
//	v = find(v);
//
//	if (u == v) return;
//
//	if (level[u] > level[v]) swap(u, v);
//	
//	parent[u] = v;
//
//	if (level[u] == level[v]) level[v]++;
//}
//
//int main() {
//	scanf("%d", &n); scanf("%d", &m);
//
//	for (int i = 0; i < n; i++) {
//		parent[i] = i;
//		level[i] = 1;
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int val;
//			scanf("%d", &val);
//			if (j > i && val == 1) {
//				merge(i, j);
//			}
//		}
//	}
//
//	bool suc = true;
//	int val;
//	scanf("%d", &val);
//	val--;
//
//	int u = find(val);
//	for (int i = 0; i < m-1; i++) {
//		scanf("%d", &val);
//		val--;
//
//		if (u != find(val)) {
//			suc = false;
//			break;
//		}
//	}
//	if(suc) printf("YES\n");
//	else printf("NO\n");
//
//
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[200];
int level[200];
int map[200][200];

int n, m;

vector <int> v;

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	if (level[y] > level[x]) swap(y, x);

	parent[y] = x;

	if (level[x] == level[y]) level[x]++;
}

int main() {
	scanf("%d", &n); scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		k--;
		v.push_back(k);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j <= i) continue;
			if (map[i][j] == 1) {
				merge(i, j);
			}
		}
	}

	bool suc = true;
	int x = find(v[0]);

	for (int i = 1; i < v.size(); i++) {
		int y = find(v[i]);
		if (x != y) {
			suc = false;
			break;
		}
	}
	if (suc) printf("YES\n");
	else printf("NO\n");


	return 0;
}