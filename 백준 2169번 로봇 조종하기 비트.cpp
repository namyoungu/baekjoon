#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int INF = 1000000;
int n, m;
int map[1001][1001], cache[1001][1001][3];
bool visit[1001][1001];
int dy[3] = { 1, 0, 0 };
int dx[3] = { 0, 1, -1 };

int dfs(int y, int x, int dir) {
	//±âÀú»ç·Ê
	if (y == n - 1 && x == m - 1) return map[y][x];

	int &res = cache[y][x][dir];
	if (res != -INF) return res;

	for (int i = 0; i < 3; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < 0 || ty >= n || tx < 0 || tx >= m || visit[ty][tx]) continue;

		visit[ty][tx] = true;
		res = max(res, dfs(ty, tx, i) + map[y][x]);
		visit[ty][tx] = false;
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			cache[i][j][0] = cache[i][j][1] = cache[i][j][2] = -INF;
		}
	}

	visit[0][0] = true;
	cout << dfs(0, 0, 0) << '\n';

	return 0;
}