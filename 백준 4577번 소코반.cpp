#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int py, px;
int n, m;
char tmap[17][17];
char map[17][17];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int Dir[51];
string tDir;
vector <point> target;

void print_map() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

bool is_range(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}

bool input() {
	cin >> n >> m;
	if (n == 0 && m == 0) return false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			
			if (map[i][j] == 'B') {
				tmap[i][j] = '+';
				map[i][j] = 'b';
				target.push_back({i, j});
			}
			if (map[i][j] == 'W') {
				tmap[i][j] = '+';
				map[i][j] = 'w';
				target.push_back({ i, j });
			}
			if (map[i][j] == '+') {
				tmap[i][j] = '+';
				map[i][j] = '.';
				target.push_back({ i, j });
			}

			if (map[i][j] == 'w') {
				py = i; px = j;
			}
		}
	}

	cin >> tDir;

	for (int i = 0; i < tDir.length(); i++) {
		char cc = tDir[i];
		if (cc == 'U') {
			Dir[i] = 0;
		}
		else if (cc == 'D') {
			Dir[i] = 1;
		}
		else if (cc == 'L') {
			Dir[i] = 2;
		}
		else {
			Dir[i] = 3;
		}
	}
	return true;
}

bool is_Stop() {
	int cnt = 0;
	if (target.size() == 0) return false;
	for (int j = 0; j < target.size(); j++) {
		int ty = target[j].y;
		int tx = target[j].x;

		if (map[ty][tx] == 'b') cnt++;
	}
	if (cnt != target.size()) return false;
	return true;
}

void move() {
	
	//cout << tDir.length() << '\n';
	//for (int i = 0; i < tDir.length(); i++) {
	//	cout << Dir[i] << ' ';
	//}
	

	for (int i = 0; i < tDir.length(); i++) {

		if (is_Stop()) {
			break;
		}

		int ny = py + dy[Dir[i]];
		int nx = px + dx[Dir[i]];

		if (!is_range(ny, nx)) continue;
		if (map[ny][nx] == '#') continue;

		if (map[ny][nx] == '.') {
			map[ny][nx] = 'w';
			map[py][px] = '.';

			py = ny; px = nx;
		}
		else if (map[ny][nx] == 'b') {
			int nny = ny + dy[Dir[i]];
			int nnx = nx + dx[Dir[i]];

			if (!is_range(nny, nnx)) continue;
			if (map[nny][nnx] == '#' || map[nny][nnx] == 'b') continue;

			if (map[nny][nnx] == '.') {
				map[nny][nnx] = 'b';
				map[ny][nx] = 'w';
				map[py][px] = '.';

				py = ny; px = nx;
			}
		}
		//cout << tDir[i];
		//print_map();
	}
}

void map_set() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmap[i][j] == '+') {
				//map[i][j] = tmap[i][j];

				if (map[i][j] == 'w') {
					map[i][j] = 'W';
				}
				else if (map[i][j] == 'b') {
					map[i][j] = 'B';
				}
				else {
					map[i][j] = '+';
				}
			}
		}
	}
}

bool count_plus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '+') return false;
		}
	}
	return true;
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmap[i][j] = '.';
			
		}
	}
	target.clear();
}

void solve() {
	int cnt = 1;
	while (1) {
		init();
		if (!input()) break;

		move();
		map_set();

		bool suc = count_plus();
		if (suc) {
			cout << "Game " << to_string(cnt) << ": complete" << '\n';

		}
		else {
			cout << "Game " << to_string(cnt) << ": incomplete" << '\n';
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}

		cnt++;
	}
}

int main() {
	solve();
	return 0;
}
