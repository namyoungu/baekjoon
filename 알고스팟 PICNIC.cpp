#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int test;
int n, m;
bool rel[11][11];
bool visited[11];
int res;

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		rel[a][b] = true;
		rel[b][a] = true;
	}
}

void init() {
	memset(rel, false, sizeof(rel));

	for (int i = 0; i < 11; i++) {
		visited[i] = false;
	}

	res = 0;
}

bool isRel(int a, int b) {
	if (rel[a][b] && rel[b][a]) return true;
	return false;
}

void makeRel(int dep, int start) {
	if (dep == n / 2) {
		res++;
		return;
	}
	if (visited[start]) {
		makeRel(dep, start + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isRel(i, start)) continue;
		if (visited[i] || visited[start]) continue;

		visited[i] = visited[start] = true;
		makeRel(dep + 1, start+1);
		visited[i] = visited[start] = false;
	}
}

int main() {
	cin >> test;
	while (test--) {
		init();
		input();
		makeRel(0, 0);
		cout << res << '\n';
	}

	return 0;
}
 