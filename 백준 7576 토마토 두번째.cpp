#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1000][1000], visit[1000][1000], storage[1000000], cnt = 0;
int a[] = { 0, 0, 1, -1 }, b[] = { 1, -1, 0, 0 };
int m, n, k = 0;

struct point {
	int y, x;
};

queue <point> q;

void bfs(int y, int x) {
	visit[y][x] = 1;
	q.push({y, x});
	
	k = 2;
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty >= 0 && tx >= 0 && ty < n && tx < m) {
				if (map[ty][tx] && visit[ty][tx] == 0) {
					q.push({ ty, tx });
					visit[ty][tx] = 1;
					map[ty][tx] = k;
				}
			}
		}
		k++;
	}
}

int main(void) {
	int M=0, E = 0;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				E = 1;
				break;
			}
		}
		
	if (E == 0)
		return 0;

	for(int i=0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j);

				for (int c = 0; c < n; c++)
					for (int d = 0; d < m; d++)
						visit[c][d] = 0;
			}
		}

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				printf("%d", -1);
				break;
			}
			else {
				if (map[i][j] > M)
					M = map[i][j];
			}
		}
	printf("%d", M-1);

	return 0;
}