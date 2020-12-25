#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[9][9];

vector<pair<int, int>>v;

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

void dfs(int dep) {
	if (dep == v.size()) {
		//puts("");
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", map[i][j]);
			}
			puts("");
		}
		puts("");
		exit(0);
	}

		for (int j = 1; j < 10; j++) {
			int y = v[dep].first;
			int x = v[dep].second;
			
			if (r_check(y, j) && c_check(x, j) && sq_check(y, x, j)) {
				map[y][x] = j;
				dfs(dep + 1);
				map[y][x] = 0;
			}
		}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	if (v.size() == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", map[i][j]);
			}
			puts("");
		}
		puts("");
	}
	else
		dfs(0);
}