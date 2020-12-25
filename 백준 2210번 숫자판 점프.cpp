#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int num[1000000] = {0, };
int map[5][5];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int tnum[7],res;

void dfs(int y, int x, int dep) {
	tnum[dep] = map[y][x];

	if (dep == 5) {
		int t = 0;
		for (int i = 0; i < 6; i++) {
			t += pow(10, i) * tnum[i];
		}
		
		if (num[t] == 0) {
			num[t] += 1;
			res++;
			
		}
		return;
	}

	//tnum[dep] = map[y][x];

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < 0 || tx < 0 || ty >= 5 || tx >= 5) continue;
		dfs(ty, tx, dep + 1);
	}

}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0);
		}
	}
	printf("%d\n", res);
	return 0;
}