#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int y, x;
};

int w, h, n, m;
int map[100][100], visit[100][100];
int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
int cnt, result;

queue<point> q;

void bfs(int y, int x) {
	q.push({ y, x });
	visit[y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
			if (map[ty][tx] == 1 && visit[ty][tx] == 0) {
				q.push({ ty, tx });
				visit[ty][tx] = visit[t.y][t.x] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	n = h-1; m = w-1;
	bfs(0, 0);
	printf("%d\n", visit[n][m]);
}