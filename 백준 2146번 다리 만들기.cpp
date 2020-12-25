#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;

struct point {
	int y, x;
};

int n;
int map[100][100];
int visit[100][100], sum_visit[100][100];
int len = INT_MAX;
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };

queue<point> q;
queue<point>sum;//¼¶

void sum_bfs() {
	while (!sum.empty()) {
		point t = sum.front();
		sum.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= n) continue;

			if (map[ty][tx] == 0 && sum_visit[ty][tx] == 0) {
				sum.push({ ty, tx });
				sum_visit[ty][tx] = sum_visit[t.y][t.x] + 1;
			}
			else if (map[ty][tx] == 1 && sum_visit[ty][tx] == 0) {
				len = min(len, sum_visit[t.y][t.x]-1);
				return;
			}
		}
	}
}

void bfs(int y, int x) {
	q.push({ y, x });
	visit[y][x] = 1;
	sum.push({ y, x });
	sum_visit[y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= n) continue;
			if (map[ty][tx] == 1 && visit[ty][tx] == 0) {
				q.push({ ty, tx });
				visit[ty][tx] = 1;
				sum.push({ ty, tx });
				sum_visit[ty][tx] = 1;
			}
		}
	}
	sum_bfs();
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j);

				while (!sum.empty()) {
					sum.pop();
				}
				memset(sum_visit, 0, sizeof(sum_visit));
			}
		}
	}
	printf("%d\n", len);
	return 0;
}