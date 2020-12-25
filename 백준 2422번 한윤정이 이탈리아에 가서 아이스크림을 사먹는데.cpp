#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int s[3], visit[201];
int result;

vector<int>a[10001];

bool check() {
	for (int i = 0; i < 3; i++) {
		int idx = s[i];
		for (int j = 0; j < a[idx].size(); j++) {
			int idy = (i + 1) % 3;
			if (a[idx][j] == s[idy]) {
				return false;
			}
			idy = (i + 2) % 3;
			if (a[idx][j] == s[idy]) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int dep = 0, int start = 1) {
	if (dep == 3) {
		if (check()) {
			result++;
		}
		return;
	}

	for (int i = start; i <= n; i++) {
		s[dep] = i;
		dfs(dep + 1, i + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, w;
		scanf("%d %d", &u, &w);
		a[u].push_back(w);
		a[w].push_back(u);
	}

	dfs();
	printf("%d\n", result);
	return 0;
}