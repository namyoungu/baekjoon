#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1000][1000], visit[1000][1000], a[] = { 1, -1, 0, 0 }, b[] = { 0, 0, 1, -1 };

struct point {
	int y, x;
};

queue <point> q;

void bfs(int y, int x) {
	visit[y][x] = 1;
	q.push({ y, x });
	while (!q.empty()) {
		map[y][x] += 1;
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < y && tx < x && map[ty][tx] == 0 && visit[ty][tx] == 0) {
				q.push({ ty, tx });
				visit[ty][tx] = 1;
			}
		}
	}
}


int main(void) {
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<y; i++)
		for (int j = 0; j < x; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j);

			}

		}


	


	return 0;
}