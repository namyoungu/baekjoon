#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int y, x;
};

struct tree {
	point a, b, c;
	int s, time;
};

int n;
int map[51][51];
bool visit[50][50][2] = { false, };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

queue<tree> q;

int bfs() {
	while (!q.empty()) {
		tree t = q.front();
		q.pop();

		point a = t.a, b = t.b, c = t.c;

		if (map[a.y][a.x] == 3 && map[b.y][b.x] == 3 && map[c.y][c.x] == 3)
			return t.time;

		for (int i = 0; i < 5; i++) {
			point ta, tb, tc;
			int ts = t.s, time = t.time;

			if (i == 4) {
				bool rot = true;

				if (ts == 0) {
					ta.y = a.y - 1; ta.x = a.x + 1;
					tb.y = b.y; tb.x = b.x;
					tc.y = c.y + 1; tc.x = c.x - 1;
				}
				else {
					ta.y = a.y + 1; ta.x = a.x - 1;
					tb.y = b.y; tb.x = b.x;
					tc.y = c.y - 1; tc.x = c.x + 1;
				}
				ts = (ts + 1) % 2;

				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						int y = tb.y + i; int x = tb.x + j;
						if (y < 0 || y >= n || x < 0 || x >= n) {
							rot = false;
							break;
						}

						if (map[y][x] == 1) {
							rot = false;
							break;
						}
					}
					if (!rot) break;
				}
				if (!rot) continue;
			}
			else {
				ta.y = a.y + dy[i]; ta.x = a.x + dx[i];
				tb.y = b.y + dy[i]; tb.x = b.x + dx[i];
				tc.y = c.y + dy[i]; tc.x = c.x + dx[i];
			}

			if (ta.y < 0 || ta.y >= n || ta.x < 0 || ta.x >= n ||
				tb.y < 0 || tb.y >= n || tb.x < 0 || tb.x >= n ||
				tc.y < 0 || tc.y >= n || tc.x < 0 || tc.x >= n) continue;
			
			
			

			if (visit[tb.y][tb.x][ts] || map[ta.y][ta.x] == 1
				|| map[tb.y][tb.x] == 1 || map[tc.y][tc.x] == 1) continue;

			q.push({ ta, tb, tc, ts, time + 1 });
			visit[tb.y][tb.x][ts] = true;
		}
	}
	return -1;
}


int main() {
	vector<point> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;

			if (ch == 'B') {
				map[i][j] = 2;
				v.push_back({i, j});
			}
			else if (ch == 'E') {
				map[i][j] = 3;
			}
			else if (ch == '0') {
				map[i][j] = 0;
			}
			else if(ch == '1'){
				map[i][j] = 1;
			}
		}
	}

	point a, b, c;
	int s;
	a = v[0]; b = v[1]; c = v[2];
	if (a.y == b.y && b.y == c.y) { 
		s = 0;
	}
	else {
		s = 1;
	}
	q.push({a, b, c, s, 0});
	visit[b.y][b.x][s] = true;

	int res = bfs();
	if (res == -1) cout << 0 << '\n';
	else cout << res << '\n';

	return 0;
}