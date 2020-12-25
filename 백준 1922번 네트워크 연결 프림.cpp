#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int visit[1001];

typedef pair<int, int> pii;

//vector <pii> v[1001];
vector <pair<int, int> > v[1001];

void prim(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	visit[start] = 1;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i].first;
		int nextVal = v[start][i].second;

		q.push(make_pair(nextVal, next));
	}

	int res = 0;
	while (!q.empty()) {
		int now = q.top().second;
		int nowVal = q.top().first;
		q.pop();

		if (visit[now] == 1) continue;

		visit[now] = 1;
		res += nowVal;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			q.push(make_pair(nextCost, next));
		}
	}
	printf("%d\n", res);
}

int main() {
	scanf("%d %d", &n, &m);
	int from, to, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &w);
		v[from].push_back(make_pair(to, w));
		v[to].push_back(make_pair(from, w));
	}
	
	prim(1);
	return 0;
}