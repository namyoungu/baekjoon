#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int y, x;
};

int w, h;
int map[50][50], visit[50][50];
int cnt;
int dy[8] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dx[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };

queue<point>q;

void bfs(int y, int x) {
	q.push({ y, x });
	visit[y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
			if (visit[ty][tx] == 0 && map[ty][tx] == 1) {
				q.push({ ty, tx });
				visit[ty][tx] = 1;
			}
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			return 0;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visit[i][j] = 0;
			}
		}
	}
	return 0;
}