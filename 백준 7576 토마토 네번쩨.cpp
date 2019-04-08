#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int m, n, k, cnt;
int map[1000][1000], rem[1000][1000], a[] = { 0, 0, -1, 1 }, b[] = { 1, -1, 0 ,0 };

struct point {
	int y, x;
};

queue <point> q;

void bfs(int y, int x) {
	q.push({ y, x });
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < n && tx < m) {
				if (map[ty][tx] != -1 && map[ty][tx] != 0 &&map[ty][tx] > ) {
					q.push({ ty, tx });
					map[ty][tx] = cnt;
				}
			}
		}
		cnt++;
	}
}

int main(void) {
	int E = 0;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				E = 1;
			break;
		}
	if (E == 0) {
		printf("%d", 0);
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				cnt = 2;
				bfs(i, j);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				printf("%d", -1);
				return 0;
			}
		}
	printf("%d", k);
	return 0;
}