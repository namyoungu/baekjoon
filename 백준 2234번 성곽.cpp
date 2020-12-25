#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct point {
	int y, x;
};

struct point2 {
	int d[4];
};

int tt = 0;
int h, w;
int map[50][50], visit[50][50];
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
int room_cnt, maxroom = 0, plusroom;

queue <point> q;
point2 wall_map[50][50];

void set_dir() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int tmp = map[i][j];
			
			if (tmp / 8 == 1) {
				tmp -= 8;
				wall_map[i][j].d[0]++;
			}
			if (tmp / 4 == 1) {
				tmp -= 4;
				wall_map[i][j].d[1]++;
			}
			if (tmp / 2 == 1) {
				tmp -= 2;
				wall_map[i][j].d[2]++;
			}
			if (tmp == 1) {
				tmp -= 1;
				wall_map[i][j].d[3]++;
			}
		}
	}
	return;
}

int bfs(int y, int x) {
	q.push({y, x});
	visit[y][x] = 1;
	int troom_wide = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();
		
		point2 tdir = wall_map[t.y][t.x];
		for (int i = 0; i < 4; i++) {
			if (tdir.d[i] == 1) continue;

			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
			if (visit[ty][tx] != 0) continue;

			q.push({ty, tx});
			visit[ty][tx] = 1;
			troom_wide++;
		}
	}
	return troom_wide;
}

void solve() {
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visit[i][j] == 1) continue;
			for (int k = 0; k < 4; k++) {
				if (wall_map[i][j].d[k] == 1) {
					wall_map[i][j].d[k] = 0;
					plusroom = max(plusroom, bfs(i, j));
					wall_map[i][j].d[k] = 1;
					memset(visit, 0, sizeof(visit));
				}
			}
		}
	}
	return;
}

int main(void) {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	set_dir();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visit[i][j] == 0) {
				maxroom = max(maxroom, bfs(i, j));
				room_cnt++;
			}
		}
	}

	solve();

	printf("%d %d %d\n", room_cnt, maxroom, plusroom);
	return 0;
}