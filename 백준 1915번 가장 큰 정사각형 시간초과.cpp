#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int w, h;
int map[1000][1000];
int result = 0, max_cnt;

bool cal(int y, int x) {
	/*int cnt = 1;
	int ty = y;
	int tx = x;*/

	//if (y + max_cnt > h || x + max_cnt > w) return false;
	for (int i = y; i < y + max_cnt; i++) {
		for (int j = x; j < x + max_cnt; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

int solve() {
	max_cnt = max(h, w);

	while (1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i + max_cnt > h || j + max_cnt > w) continue;
				if (map[i][j] == 1) {
					if (cal(i, j)) {
						return max_cnt * max_cnt;
					}
				}
			}
		}
		max_cnt--;
	}
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	result = solve();
	printf("%d\n", result);
	return 0;
}