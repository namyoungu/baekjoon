#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int cnt=1, map[10][10], visit[10][10], a[] = { 0, 0, 1, -1 }, b[] = { 1, -1, 0, 0 };

struct point {
	int y, x;
};

queue <point> q;

void bfs(int y, int x) {
	visit[y][x] = 1;
	
	q.push({ y, x });

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < 10 && tx < 10) {
				if (map[ty][tx] == 0 && visit[ty][tx] == 0) {
					q.push({ ty, tx });
					map[ty][tx] = map[t.y][t.x] + 1;
					visit[ty][tx] = 1;
				}
			}
		}
		cnt++;
	}
}

int main(void) {

	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%d", map[i][j]);
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bfs(i, j);
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("\n");
		printf("\n");
		for (int j = 0; j < 10; j++) {
			printf("%2d ", map[i][j]);
		}
	}

	return 0;
}