#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;


int n, map[501][501];
int cache[501][501];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x) {
	int &res = cache[y][x];
	if (res != -1) {
		return res;
	}

	res = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
		if (map[y][x] >= map[ty][tx]) continue;

		res = max(res, dfs(ty, tx) + 1);
	}
	return res;
}


int main() {
	memset(cache, -1, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cache[i][j] == -1) {
				cache[i][j] = dfs(i, j);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, cache[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}