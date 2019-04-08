#define _CRT_SECURE_NO_WANINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, k, cnt;
int map[50][50], k[2500], a[] = { 0, 0, 1, -1 }, b[] = {1, -1, 0, 0};

struct point {
	int y, x;
};

struct points {
	int y, x, z;
};

queue <point> q;
queue <points> t;

void bfs(int y, int x, int m, int n) {
	map[y][x] = 2;
	q.push({ y, x });
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (tx >= 0 && ty >= 0 && tx < m && ty < n) {
				if (map[ty][tx] == 1) {
					q.push({ ty, tx });
					map[ty][tx] = 2;
				}
			}
		}
	}
}


int main(void) {
	int test_case;
	int p_x[2][2500], p_y[2][2500];

	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d %d", &m, &n, &k);
		t.push({ n, m, k});
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &p_x[z][i], &p_y[z][i]);
		}
	}

	for (int z = 0; z < test_case; z++) {
		for (int i = 0; i < k; i++)
			map[p_y[z][i]][p_x[z][i]] = 1;

		points tmp  = t.front();
		t.pop();

		for (int i = 0; i < tmp.y; i++)
			for (int j = 0; j < tmp.x; j++) {
				if (map[i][j] == 1) {
					cnt = 0;
					bfs(i, j, tmp.y, tmp.x);
					cnt++;
				}
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = 0;



	printf("%d\n", cnt);
	}
	return 0;
}
