#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

struct point {
	int z, y, x;
};

int l, r, c;
char map[31][31][31];
int visit[31][31][31];
int dy[] = { 0, 0, 1, -1, 0, 0};
int dx[] = { 1, -1, 0, 0, 0, 0};
int dz[] = { 0, 0, 0, 0, 1, -1 };
point S, E;

queue<point> q;

bool check(int z, int y, int x) {
	if (z < 0 || y < 0 || x < 0 || z >= l || y >= r || x >= c || map[z][y][x] == '#') {
		return false;
	}
	return true;
}

bool bfs() {
	int sec = 0;
	q.push(S);
	visit[S.z][S.y][S.x] = 1;

	while (!q.empty()) {
		int sz = q.size();
		for (int z = 0; z < sz; z++) {
			point t = q.front();
			q.pop();

			if (t.z == E.z && t.y == E.y && t.x == E.x) {
				printf("Escaped in %d minute(s).\n", sec);

				while (!q.empty()) {
					q.pop();
				}
				return true;
			}


			for (int i = 0; i < 6; i++) {
				int tz = t.z + dz[i];
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];

				if (visit[tz][ty][tx] == 0 && check(tz, ty, tx)){
					q.push({ tz, ty, tx });
					visit[tz][ty][tx] = 1;
				}
			}
		}
		sec++;
	}
	return false;
}

void INPUT() {
	scanf("%d %d %d", &l, &r, &c);
	if (l == 0 && r == 0 && c == 0) {
		exit(0);
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			cin >> map[i][j];

			for (int k = 0; k < c; k++) {
				if (map[i][j][k] == 'S') {
					S = { i, j, k };
				}
				else if (map[i][j][k] == 'E') {
					E = { i, j, k };
				}
			}
		}
	}
}

int main() {
	while (1) {
		INPUT();

		if (!bfs()) {
			printf("Trapped!\n");
		}
		
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}