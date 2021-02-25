#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX  51

struct fire {
	int y, x, m, s, d;
};

int n, m, k;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<fire> map[MAX][MAX];
vector<fire> tmap[MAX][MAX];

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		a--; b--;

		fire t = { a, b, c, d, e };
		map[a][b].push_back(t);
	}
}

void copy_map(vector<fire> A[][MAX], vector<fire> B[][MAX]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = B[i][j];
		}
	}
}

void set_out_range(int &ty, int &tx) {
	while (ty < 0) {
		ty += n;
	}
	while (ty > n - 1) {
		ty -= n;
	}
	while (tx < 0) {
		tx += n;
	}
	while (tx > n - 1) {
		tx -= n;
	}
}

void init_tmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmap[i][j].clear();
		}
	}
}

void move() {
	init_tmap();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < map[i][j].size(); z++) {
				fire t = map[i][j][z];

				int ty = i + dy[t.d] * t.s;
				int tx = j + dx[t.d] * t.s;

				set_out_range(ty, tx);

				t.y = ty;
				t.x = tx;

				tmap[ty][tx].push_back(t);
			}
		}
	}

	copy_map(map, tmap);
}

bool all_dir_same(int y, int x) {
	bool odd = true, even = true;

	for (int i = 0; i < map[y][x].size(); i++) {
		if (map[y][x][i].d % 2 == 0) {
			odd = false;
		}
		else {
			even = false;
		}
	}
	if (odd || even) return true;
	return false;
}

int cal_m(int y, int x) {
	int sum = 0;

	for (int i = 0; i < map[y][x].size(); i++) {
		sum += map[y][x][i].m;
	}

	return sum / 5;
}

int cal_s(int y, int x) {
	int all_cnt = map[y][x].size();
	int sum = 0;

	for (int i = 0; i < map[y][x].size(); i++) {
		sum += map[y][x][i].s;
	}

	return sum / all_cnt;
}

void cal_same() {
	init_tmap();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d1, d2, d3, d4;
			fire f1, f2, f3, f4;

			if (map[i][j].size() > 1) {
				int new_m = cal_m(i, j);
				int new_s = cal_s(i, j);

				if (new_m == 0) {
					map[i][j].clear();
					continue;
				}

				//dir
				if (all_dir_same(i, j)) {
					d1 = 0;
					d2 = 2;
					d3 = 4;
					d4 = 6;
				}
				else {
					d1 = 1;
					d2 = 3;
					d3 = 5;
					d4 = 7;
				}

				
				f1 = {i, j, new_m, new_s, d1};
				f2 = { i, j, new_m, new_s, d2 };
				f3 = { i, j, new_m, new_s, d3 };
				f4 = { i, j, new_m, new_s, d4 };

				map[i][j].clear();

				map[i][j].push_back(f1);
				map[i][j].push_back(f2);
				map[i][j].push_back(f3);
				map[i][j].push_back(f4);
			}
		}
	}

	//copy_map(map, tmap);
}

int solve() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < map[i][j].size(); z++) {
				sum += map[i][j][z].m;
			}
		}
	}

	return sum;
}

int main() {
	input();
	
	for (int i = 0; i < k; i++) {
		move();
		cal_same();
	}
	
	cout << solve() << '\n';
	return 0;
}