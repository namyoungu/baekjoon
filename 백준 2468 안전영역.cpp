#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100], visit[100][100], a[] = { 0, 0, -1, 1 }, b[] = { 1, -1, 0, 0 };
int n, h=0, M=0, dab = 0 , cnt = 0;

void dfs(int y, int x) {
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + a[i];
		int tx = x + b[i];

		if (ty >= 0 && tx >= 0 && ty < n && tx < n) {
			if (visit[ty][tx] == 0) {
				visit[ty][tx] = 1;
				dfs(ty, tx);
			}
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > M) {
				M = map[i][j];
			}
		}
	}

	for (int z = 0; z < M; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= h) {
					visit[i][j] = -1;
				}
			}
		}
		h++;

		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt > dab) {
			dab = cnt;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}
	}
	
	printf("%d\n", dab);

	return 0;
}