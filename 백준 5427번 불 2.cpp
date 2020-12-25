#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int test_case, w, h, result, k, v[1000][1000], a[] = { 1, -1, 0, 0 }, b[] = { 0, 0, 1, -1 }, vv[1000][1000];
char map[1001][1001];

void Burn(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int t_y = y + a[i];
		int t_x = x + b[i];

		if (t_x>=0 && t_x<h && t_y>=0 && t_y<w) {
			if (v[t_y][t_x] >= 0) {
				v[t_y][t_x] = -1;
			}
		}
	}
}

void Run(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int t_y = y + a[i];
		int t_x = x + b[i];

		if (t_x >= 0 && t_x < h && t_y >= 0 && t_y < w) {
			if (v[t_y][t_x] == 0) {
				v[t_y][t_x] = v[y][x]+1;
				k = 1;

				if (t_x==0 && t_y<w) {
					result = v[t_y][t_x];
				}

				else if (t_x==h-1 && t_y<w) {
					result = v[t_y][t_x];
				}

				else if (t_x<h && t_y == 0) {
					result = v[t_y][t_x];
				}

				else if (t_x<h && t_y==w-1) {
					result = v[t_y][t_x];
				}
			}
		}
	}
}

int main(void) {
	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", map[i]);

			while (1) {
				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						if (map[i][j] == '*') {
							v[i][j] = -1;
							vv[i][j] = 1;
						}
						else if (map[i][j] == '#') {
							v[i][j] = -2;
							vv[i][j] = 1;
						}
					}
				}

				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						if (v[i][j] == -1) {
							Burn(i, j);
						}
					}
				}

				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						if (vv[i][j] == 0 && v[i][j] >= 0) {
							Run(i, j);
						}
					}
				}

				if (result > 0) {
					printf("%d\n", result);
					result = 0;
					break;
				}
			}
		}
	}
	return 0;
}