#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 65

int n, L, sn, Llist[1001];
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

struct point {
	int y, x;
};

void print_map() {
	cout << '\n';
	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool is_range(int y, int x) {
	if (y < 0 || y >= sn || x < 0 || x >= sn) return false;
	return true;
}

void init_visit() {
	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			visit[i][j] = false;
		}
	}
}

void copy_map(int A[][MAX], int B[][MAX]) {
	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			A[i][j] = B[i][j];
		}
	}
}

void input() {
	cin >> n >> L;
	sn = pow(2, n);

	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < L; i++) {
		cin >> Llist[i];
	}
}

int bfs(int sy, int sx) {
	vector<point> visited;
	queue<point> q;

	q.push({ sy, sx });
	visit[sy][sx] = true;
	visited.push_back({ sy, sx });

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			//cout << ty << ' ' << tx << '\n';

			if (!is_range(ty, tx)) continue;
			if (visit[ty][tx]) continue;
			if (map[ty][tx] == 0) continue;

			q.push({ ty, tx });
			visit[ty][tx] = true;
			visited.push_back({ ty, tx });
		}
	}

	return visited.size();
}

int cal_sum() {
	int sum = 0;
	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			if (map[i][j] != 0) {
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int cal_cnt() {
	init_visit();
	int sum = 0;

	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			if (visit[i][j] || map[i][j] == 0) continue;
			sum = max(sum, bfs(i, j));
		}
	}

	return sum;
}

void reduce_ice() {
	vector<point> v;

	for (int i = 0; i < sn; i++) {
		for (int j = 0; j < sn; j++) {
			int sum = 0;

			for (int d = 0; d < 4; d++) {
				int ty = i + dy[d];
				int tx = j + dx[d];

				//cout << ty << ' ' << tx << '\n';

				if (!is_range(ty, tx)) continue;
				if (map[ty][tx] == 0) continue;
				sum++;
			}

			if (sum < 3) {
				v.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int y = v[i].y;
		int x = v[i].x;

		if (map[y][x] == 0) continue;

		map[y][x] -= 1;
	}
}

void rotate(int sL, int y, int x) {
	int tmap[MAX][MAX];
	copy_map(tmap, map);

	for (int i = 0; i < sL; i++) {
		for (int j = 0; j < sL; j++) {
			map[y + j][x + sL - 1 -i] = tmap[y + i][x + j];
		}
	}
}

int main() {
	input();

	//print_map();
	for (int z = 0; z < L; z++) {
		int sL = pow(2, Llist[z]);

		for (int i = 0; i < sn; i = i + sL) {
			for (int j = 0; j < sn; j = j + sL) {
				rotate(sL, i, j);
			}
		}
		//print_map();
		reduce_ice();
		//print_map();
	}

	cout << cal_sum() << '\n' << cal_cnt() << '\n';




	return 0;
}
