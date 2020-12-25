#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct point {
	int y, x;
};

queue<point>q;
vector<point> v;
point mineral_p;

int r, c, n, h[100];
int lr;
char map[101][101];
bool visit[100][100];
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};

void fall() {
	int cnt = 0;
	bool stop = false;
	int sz = v.size();

	int j = 1;
	while (1) {
		for (int i = 0; i < sz; i++) {
			point t;
			t.y = v[i].y;
			t.x = v[i].x;

			if (visit[t.y + j][t.x] == true) continue;
			if (map[t.y + j][t.x] == 'x' || t.y + j >= r) {
				stop = true;
				break;
			}
		}
		if (stop) break;
		cnt++;
		j++;
	}
	if (cnt == 0) return;

	char tmap[101][101];
	for (int i = 0; i < sz; i++) {
		point t;
		t.y = v[i].y;
		t.x = v[i].x;

		map[t.y][t.x] = '.';
		tmap[t.y+cnt][t.x] = 'x';
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tmap[i][j] == 'x') {
				map[i][j] = 'x';
			}
		}
	}

	return;
}

bool check(int y, int x) {
	q.push({ y, x });
	visit[y][x] = true;
	v.push_back({y, x});

	bool max_y = true;
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= r || tx >= c) continue;
			if(visit[ty][tx] == false && map[ty][tx] == 'x'){
				q.push({ty, tx});
				visit[ty][tx] = true;
				v.push_back({ty, tx});
				if (ty == r - 1) {
					max_y = false;
				}
			}
		}
	}
	return max_y;
}

//lr%2 == 0이면 왼쪽
bool att(int k) {
	if (lr % 2 == 0) {//left
		for (int i = 0; i < c; i++) {
			if (map[k][i] == 'x') {
				map[k][i] = '.';
				mineral_p.y = k;
				mineral_p.x = i;

				lr++;
				return true;
			}
		}
	}
	else {
		for (int i = c-1; i >= 0; i--) {
			if (map[k][i] == 'x') {
				map[k][i] = '.';
				mineral_p.y = k;
				mineral_p.x = i;

				lr++;
				return true;
			}
		}
	}
	lr++;
	return false;
}

void simul() {
	for (int i = 0; i < n; i++) {
		if (att(h[i])) {
			//미네랄이 막대기에 맞는다면
			for (int j = 0; j < 4; j++) {
				memset(visit, false, sizeof(visit));
				v.clear();

				int ty = mineral_p.y + dy[j];
				int tx = mineral_p.x + dx[j];

				if (map[ty][tx] == 'x') {
					if (check(ty, tx)) {
						fall();
						break;
					}
				}
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		h[i] = r - x;
	}

	simul();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
	puts("");

	return 0;
}