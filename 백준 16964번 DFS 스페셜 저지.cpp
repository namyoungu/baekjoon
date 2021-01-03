#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000

int n;
int idx = 0;
int order[MAX+1];
int dfs_order[MAX+1];
bool visit[MAX+1];
bool res = true;
vector<int> e[MAX+1];

bool cmp(int a, int b) {
	return dfs_order[a] < dfs_order[b];
}

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> order[i];
		order[i]--;
		dfs_order[order[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		sort(e[i].begin(), e[i].end(), cmp);
	}
}

void dfs(int now) {
	for (int i = 0; i < e[now].size(); i++) {
		int next = e[now][i];
		if (visit[next]) continue;
		if (next != order[++idx]) {
			res = false;
			return;
		}

		visit[next] = true;
		dfs(next);
	}
}

void solve() {
	visit[0] = true;
	dfs(0);

	if (res) cout << 1 << '\n';
	else cout << 0 << '\n';
}

int main() {
	input();
	solve();

	return 0;
}