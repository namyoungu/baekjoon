#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int map[9][9];
int tmap[9][9];
int visit[10][10];
int cnt[9];

bool r_check(int r, int x) {
	for (int i = 0; i < 9; i++) {
		if (map[r][i] == x) return false;
	}
	return true;
}

bool c_check(int c, int x) {
	for (int i = 0; i < 9; i++) {
		if (map[i][c] == x) return false;
	}
	return true;
}

bool sq_check(int r, int c, int x) {
	int rls = (r / 3) * 3;
	int cls = (c / 3) * 3;

	for (int i = rls; i < rls + 3; i++) {
		for (int j = cls; j < cls + 3; j++) {
			if (map[i][j] == x) return false;
		}
	}
	return true;
}

void dfs(int dep, int r) {
	if (dep == cnt[r]) {
		for (int i = 0; i < 9; i++) {
			tmap[r][i] = map[r][i];
		}
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (map[r][i] != 0) continue;
		for (int j = 1; j <=9; j++) {
			if (visit[r][j] == 1) continue;
			if (r_check(r, j) && c_check(i, j) && sq_check(r, i, j)) {
				map[r][i] = j;
				visit[r][j] = 1;
				dfs(dep + 1, r);
				map[r][i] = 0;
				visit[r][j] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) cnt[i]++;
		}
	}

	for (int i = 0; i < 9; i++) {
		dfs(0, i);
	}

	//puts("");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", tmap[i][j]);
		}
		puts("");
	}
	puts("");
}