//dfs
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt;
int map[25][25], visit[25][25];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

vector<int> v;

bool range_check(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	return false;
}

bool Is_empty(int y, int x) {
	if (map[y][x] == 0) {
		return false;
	}
	return true;
}

bool Is_visit(int y, int x) {
	if (visit[y][x] == 0) return true;
	return false;
}

void dfs(int y, int x) {
	visit[y][x] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (range_check(ty, tx) && Is_empty(ty, tx) && Is_visit(ty, tx)) {
			dfs(ty, tx);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}