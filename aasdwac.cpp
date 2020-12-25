#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m, start;
bool visit[1001];

vector<int>a[1001];
queue<int>q;

void dfs(int node) {
	visit[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (visit[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	memset(visit, false, sizeof(visit));
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (visit[next] == false) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");

	return 0;
}