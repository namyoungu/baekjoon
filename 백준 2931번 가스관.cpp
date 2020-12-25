#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

struct info {
	int y, x, dir, cnt;
};

struct point {
	int y, x, dir;
};

int n, m, K;
char map[30][30], gas[7] = {'|', '-', '+', '1', '2', '3', '4'};
int dy[4] = {0, -1, 0, 1 };
int dx[4] = {1, 0, -1, 0 };
int ey, ex, ec;
bool visit[30][30], tvisit[30][30];

queue<info> q;

int check(int dir, char c) {
	if (c == '|') {
		if (dir == 1 || dir == 3) return dir;
	}
	else if (c == '-') {
		if (dir == 0 || dir == 2) return dir;
	}
	else if (c == '+') {
		return dir;
	}
	else if (c == '1') {
		if (dir == 1) return 0;
		if (dir == 2) return 3;
	}
	else if (c == '2') {
		if (dir == 2) return 1;
		if (dir == 3) return 0;
	}
	else if (c == '3') {
		if (dir == 0) return 1;
		if (dir == 3) return 2;
	}
	else if (c == '4') {
		if (dir == 0) return 3;
		if (dir == 1) return 2;
	}
	return -1;
}

void dfs(int cnt, bool used, int y, int x, int dir) {
	//±âÀú»ç·Ê
	if (y < 0 || y >= n || x < 0 || x >= m) return;

	if (map[y][x] == '.') {
		if (used == false) {
			used = true;
			for (int i = 0; i < 7; i++) {
				map[y][x] = gas[i];
				visit[y][x] = true;
				ey = y; ex = x; ec = i;
				dfs(cnt+1, used, y, x, dir);
				map[y][x] = '.';
				visit[y][x] = false;
			}
		}
		return;
	}

	int td = check(dir, map[y][x]);
	if (td == -1) return;

	if (cnt == K) {
		cout << ey + 1 << ' ' << ex + 1 << ' ' << gas[ec] << '\n';
		exit(0);
		return;
	}

	int ty = y + dy[td];
	int tx = x + dx[td];

	if (visit[ty][tx]) {
		dfs(cnt, used, ty, tx, td);
	}
	else {
		visit[ty][tx] = true;
		dfs(cnt + 1, used, ty, tx, td);
		visit[ty][tx] = false;
	}
	
}

int main() {
	int sy, sx, sd;
	int my, mx;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				sy = i; sx = j;
			}
			if (map[i][j] != '.') K++;
		}
	}
	//M, Z Á¦¿Ü + ºó Ä­
	K -= 1;

	for (int i = 0; i < 4; i++) {
		dfs(0, false, sy + dy[i], sx + dx[i], i);
	}

	return 0;
}