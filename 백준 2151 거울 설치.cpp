#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int y, x, d, cnt;
};

int n, res = 2501;
char map[51][51];
bool visit[50][50][4];
int dy[4] = {0, -1, 0, 1 };
int dx[4] = {1, 0, -1, 0 };
int sy, sx;

struct cmp {
	bool operator()(point a, point b) {
		return a.cnt > b.cnt;
	}
};

priority_queue<point, vector<point>, cmp> q;

void bfs() {
	while (!q.empty()) {
		point t = q.top();
		q.pop();

		if (map[t.y][t.x] == '#' && !(t.y == sy && t.x == sx)) {
			cout << t.cnt << '\n';
			exit(0);
		}

		int ty = t.y + dy[t.d];
		int tx = t.x + dx[t.d];
		int td;
		int tcnt = t.cnt + 1;

		if (ty < 0 || ty >= n || tx < 0 || tx >= n ||
			map[ty][tx] == '*') continue;

		//그냥 가기
		if (!visit[ty][tx][t.d]) {
			q.push({ ty, tx, t.d, t.cnt });
			visit[ty][tx][t.d] = true;
		}

		if (map[ty][tx] == '!') {
			if (t.d == 0) {
				td = 1;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}

				td = 3;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}
			}
			if (t.d == 1) {
				td = 0;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}

				td = 2;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}
			}
			if (t.d == 2) {
				td = 1;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}

				td = 3;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}
			}
			if (t.d == 3) {
				td = 0;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}

				td = 2;
				if (!visit[ty][tx][td]) {
					q.push({ ty, tx, td, tcnt });
					visit[ty][tx][td] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				sy = i; sx = j;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		q.push({sy, sx, i, 0});
		visit[sy][sx][i] = true;
	}
	
	bfs();

	return 0;
}