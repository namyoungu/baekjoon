#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w, h, cnt, res;
char map[20][20];
int visit[20][20];
int used[26];
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };

void dfs(int y, int x, int c) {
	visit[y][x] = 1;
	used[c - 'A'] = 1;
	cnt++;
	res = max(res, cnt);
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		char c = map[ty][tx];

		if (ty < 0 || tx < 0 || ty >= h || tx >= w || visit[ty][tx] == 1) continue;
		if (used[c - 'A'] == 0) {
			dfs(ty, tx, c);
		}
	}
	visit[y][x] = 0;
	used[c - 'A'] = 0;
	cnt--;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", map[i]);
	}
	dfs(0, 0, map[0][0]);
	printf("%d\n", res);
	return 0;
}