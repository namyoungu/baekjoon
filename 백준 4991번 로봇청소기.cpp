#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>
#include <limits.h>
using namespace std;

struct point {
	int y, x;
};

int w, h;
int total;
int map[20][20], dvisit[11];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int res = INT_MAX;
int dist[11][11];
point node[11];

vector<int>v;

void INIT() {
	total = 1;
	res = INT_MAX;
	memset(dvisit, 0, sizeof(dvisit));
}

void dfs(int dep = 0, int start = 0, int sum = 0) {
	if (dep == total - 1) {
		res = min(res, sum);
		//system("pause");
		return;
	}

	for (int i = 1; i < total; i++) {
		if (dvisit[i] == 1) continue;
		if (dist[start][i] == 0) continue;
		dvisit[i] = 1;
		sum += dist[start][i];
		dfs(dep + 1, i, sum);
		sum -= dist[start][i];
		dvisit[i] = 0;
	}
}

int bfs(int sy, int sx, int ey, int ex) {
	queue<point>q;
	int visit[20][20] = { 0, };
	int cnt = 0;
	q.push({ sy, sx });
	visit[sy][sx] = 1;

	while (!q.empty()) {
		int sz = q.size();
		for (int z = 0; z < sz; z++) {
			point t = q.front();
			q.pop();

			if (t.y == ey && t.x == ex) {
				return cnt;
			}

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];

				if (ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
				if (visit[ty][tx] != 0) continue;
				if (map[ty][tx] != 1) {
					q.push({ ty, tx });
					visit[ty][tx] = 1;
				}
			}
		}
		cnt++;
	}
	return 0;
}

int main(void) {
	while (1) {
		INIT();
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) return 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char t;
				scanf(" %c", &t);
				if (t == '.') {
					map[i][j] = 0;
				}
				else if (t == '*') {
					map[i][j] = 2;
					node[total++] = { i, j };
				}
				else if (t == 'x') {
					map[i][j] = 1;
				}
				else {
					map[i][j] = 0;
					node[0] = { i, j };
				}
			}
		}

		int idx = 0;
		for (int i = 0; i < total; i++) {
			for (int j = 0; j < total; j++) {
				if (j > i) {
					dist[i][j] = bfs(node[i].y, node[i].x, node[j].y, node[j].x);
				}
			}
		}
		for (int i = 0; i < total; i++) {
			for (int j = 0; j < total; j++) {
				if (j <= i) {
					dist[i][j] = dist[j][i];
				}
			}
		}
		/*puts("");
		for (int i = 0; i < total; i++) {
			for (int j = 0; j < total; j++) {
				printf("%d ", dist[i][j]);
			}
			puts("");
		}*/
		//system("pause");
		dfs();
		if (res == INT_MAX) {
			printf("-1\n");
		}
		else {
			printf("%d\n", res);
		}
	}

	return 0;
}