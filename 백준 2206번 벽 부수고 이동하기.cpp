#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct point {
	int y, x, s;
};

int w, h;
int map[1000][1000], visit[1000][1000][2];
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };
int res;

queue<point>q;

void vp() {
	printf("visit0\n");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", visit[i][j][0]);
		}
		puts("");
	}
	puts("");

	printf("visit1\n");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", visit[i][j][1]);
		}
		puts("");
	}
	puts("");
}

void bfs(int y, int x) {
	q.push({ y, x, 1});
	visit[y][x][0] = 1;
	visit[y][x][1] = 1;

	while (!q.empty()) {
		int sz = q.size();
		for (int z = 0; z < sz; z++) {
			point t = q.front();
			q.pop();

			if (t.y == h - 1 && t.x == w - 1) {
				printf("%d\n", res+1);
				exit(0);
			}

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];

				if (ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
				if (map[ty][tx] == 0) {
					if (visit[ty][tx][0] == 0 && t.s == 1) {
						q.push({ ty, tx, 1});
						visit[ty][tx][0] = 1;
					}
					if (visit[ty][tx][1] == 0 && t.s == 0) {
						q.push({ ty, tx, 0 });
						visit[ty][tx][1] = 1;
					}
				}
				if (map[ty][tx] == 1) {
					if (visit[ty][tx][1] == 0) {
						if (t.s == 1) {
							q.push({ ty, tx, 0 });
							visit[ty][tx][1] = 1;
						}
					}
				}
			}
		}
		res++;
		vp();
	}
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);

	printf("%d\n", -1);

	return 0;
}