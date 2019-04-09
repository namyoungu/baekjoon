#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int y, x;
};

queue <point> q;

char map[51][51];
int m, n, M, visit[50][50], a[] = { 0, 0, 1, -1 }, b[] = { 1, -1, 0, 0 };

void bfs(int y, int x) {
	q.push({ y, x });

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < n && tx < m) {
				if (map[ty][tx] == 'L' && visit[ty][tx] == 0) {
					q.push({ ty, tx });
					visit[ty][tx] = visit[t.y][t.x] + 1;
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	

	M = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				visit[i][j] = 1;
				bfs(i, j);

				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						if (visit[k][l] > M) {
							M = visit[k][l] - 1;
						}
						visit[k][l] = 0;
					}
				}
			}
		}
	}
	printf("%d\n", M);
	return 0;
}