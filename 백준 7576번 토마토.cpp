#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, map[1000][1000], visit[1000][1000], a[] = { 0, 0, 1, -1 }, b[] = { 1, -1, 0, 0 };

struct point {
	int y, x;
};

queue <point> q;

void bfs() {
	while (!q.empty()) {
		point t = q.front();
		q.pop();
		visit[t.y][t.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < n && tx < m) {
				if (map[ty][tx] == 0 && visit[ty][tx] == 0) {
					map[ty][tx] = map[t.y][t.x] + 1;
					visit[ty][tx] = 1;
					q.push({ ty, tx });
				}
			}
		}
	}
}

int main(void) {
	int firstfull = 0;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (firstfull == 0 && map[i][j] == 0) {
				firstfull = 1;
			}
		}
	}

	if(firstfull == 0) {
		printf("%d\n", 0);
		return 0;
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				q.push({ i, j });
			}

			if (firstfull == 0 && map[i][j] == 0) {
				firstfull = 1;
			}
		}
	}
	bfs();

	int unfull = 0, M = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > M) {
				M = map[i][j];
			}

			if (map[i][j] == 0 && unfull == 0) {
				unfull = 1;
			}			
		}
	}

	if (unfull == 1) {
		printf("%d\n", -1);
	}

	else {
		printf("%d", M-1);
	}
	return 0;
}