#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[100][100][100];
int cnt;

struct point {
	int x, y, z;
};

queue <point> q;

void bfs(int y, int x, int z) {


}


int main(void) {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	for (int i = 0; i < y; i++) 
		for (int j=0; j<x; j++)
			for (int k = z-1; k >= 0; k--) {
				scanf("%d", &map[i][j][z]);
			}

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			for (int k = 0; k < z; k++) {
				if (map[i][j][k] == 1) {
					cnt = 0;
					bfs(i, j, k);

				}
			}








	return 0;
}
