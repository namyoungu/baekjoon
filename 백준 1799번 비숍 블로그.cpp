//https://j2wooooo.tistory.com/80
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
int map[11][11];
int b_res, w_res;
int res = INT_MIN;
int r[33], l[33];


bool check(int y, int x) {
	/*if (map[y][x] == 0 || r[y + x] == 1 || l[y - x + n - 1] == 1) {
		return false;
	}
	return true;*/
	if (map[y][x] == 1 && r[y + x] == 0 && l[y - x + n - 1] == 0) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int y, int x, int cnt) {

	if (x >= n) {
		y++;
		if (x % 2 == 0) x = 1;
		else x = 0;
	}

	if (y >= n) {
		res = max(res, cnt);
		return;
	}


	if (check(y, x)) {
		r[y + x] = 1;
		l[y - x + n - 1] = 1;
		dfs(y, x+2, cnt + 1);
		r[y + x] = 0;
		l[y - x + n - 1] = 0;
	}
	dfs(y, x+2, cnt);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0, 0);
	b_res = res;
	res = INT_MIN;

	dfs(0, 1, 0);
	w_res = res;
	printf("%d\n", w_res + b_res);

	return 0;
}