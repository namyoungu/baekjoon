#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int y, x, t;
};

int n, m;
char map[51][51];
bool visit_q[51][51];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

queue <point> q;
queue <point> w;

int bfs() {
	while (!q.empty()) {
		int sz_w = w.size();
		for (int z = 0; z < sz_w; z++) {
			point t = w.front();
			w.pop();

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];
				int tt = t.t + 1;

				if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;

				if (map[ty][tx] == '.') {
					w.push({ ty, tx, tt });
					map[ty][tx] = '*';
				}
			}
		}

		int sz_q = q.size();
		for (int z = 0; z < sz_q; z++) {
			point t = q.front();
			q.pop();

			if (map[t.y][t.x] == 'D') return t.t;

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];
				int tt = t.t + 1;

				if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
				if (visit_q[ty][tx] || map[ty][tx] == 'X' || map[ty][tx] == '*') continue;

				q.push({ ty, tx, tt });
				visit_q[ty][tx] = true;
			}
		}
	}
	return -1;
}

int main() {
	point t;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push({ i, j, 0 });
				visit_q[i][j] = true;
				t.y = i; t.x = j;
			}
			else if (map[i][j] == '*') {
				w.push({ i, j, 0 });
			}
		}
	}

	int res = bfs();
	if (res == -1) {
		cout << "KAKTUS" << '\n';
	}
	else {
		cout << res << '\n';
	}

	return 0;
}