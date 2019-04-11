#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int map[1000][1000], visit[1000][1000], px[20000], py[20000];
int n, m;


void dfs(int y, int x) {
	visit[y][x] = 1;

	


	for (int i = 1; i < n-y-1; i++) {
		int tx = y;
		int ty = 0;
	}


}




int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &px[i], &py[i]);
	}

	for (int i = 0; i < m; i++) {
		map[px[m]][py[m]] = 1;
	}

	dfs(0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
			}
		}
	}






	return 0;
}

