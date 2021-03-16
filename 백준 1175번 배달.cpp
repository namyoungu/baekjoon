#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define MAX  50+1

struct point {
	int y, x, dir, cnt;
	bool cVisited = false, dVisited = false;
};

int n, m, sy, sx;
char map[MAX][MAX];
bool visit[MAX][MAX][5][2][2];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool isRange(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			if (map[i][j] == 'C') {
				cnt++;
				if (cnt == 2) {
					map[i][j] = 'D';
				}
			}
		}
	}

	//print_map();
}

int bfs() {
	queue<point> q;
	
	q.push({ sy, sx, -1, 0, 0, 0 });
	visit[sy][sx][4][0][0] = true;
	
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		if (t.cVisited && t.dVisited) {
			return t.cnt;
		}

		
		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];
			int cnt = t.cnt + 1;
			bool C = t.cVisited;
			bool D = t.dVisited;

			if (t.dir == i) continue;
			if (!isRange(ty, tx)) continue;
			if (map[ty][tx] == '#') continue;
			if (visit[ty][tx][i][C][D]) continue;

			if (map[ty][tx] == 'C') {
				C = true;
			}
			if (map[ty][tx] == 'D') {
				D = true;
			}
			visit[ty][tx][i][C][D] = true;
			q.push({ ty, tx, i, cnt, C, D });

		}
	}

	return -1;
}

int main() {
	input();
	cout << bfs() << '\n';
	return 0;
}