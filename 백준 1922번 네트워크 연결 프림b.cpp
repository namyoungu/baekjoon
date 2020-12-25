#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;

vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int visit[1001];

void prim() {
	int res = 0;
	int start = 1;

	visit[start] = 1;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i].first;
		int nextval = v[start][i].second;

		q.push(make_pair(nextval, next));
	}

	while (!q.empty()) {
		int now = q.top().second;
		int nowval = q.top().first;
		q.pop();

		if (visit[now] == 1) continue;
		visit[now] = 1;
		res += nowval;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextval = v[now][i].second;

			q.push(make_pair(nextval, next));
		}
	}

	printf("%d\n", res);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	prim();

	return 0;
}