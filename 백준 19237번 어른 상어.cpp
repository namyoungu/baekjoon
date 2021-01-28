#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 20

struct Smell {
	int num, k;
};

struct Shark {
	int y, x, dir;
	bool live = true;
};

int n, m, k, time = 0;
int Dir[MAX*MAX+1][4][4];
Smell smell[MAX+1][MAX + 1];
Shark shark[MAX*MAX+1];
int killed = 0;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ddy[] = {1, -1, 0, 0};
int ddx[] = {0, 0, 1, -1};



void print_shark() {
	int map[MAX + 1][MAX + 1] = {0, };

	for (int i = 1; i <= m; i++) {
		if (shark[i].live) map[shark[i].y][shark[i].x] = i;
	}

	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print_smell() {

	cout <<'\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << smell[i][j].k << ' ';
		}
		cout << '\n';
	}
	cout << "------next-------" << '\n';
}

bool is_range(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return false;
	return true;
}

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp > 0) {
				shark[tmp].y = i;
				shark[tmp].x = j;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		shark[i+1].dir = --a;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int h = 0; h < 4; h++) {
				cin >> Dir[i + 1][j][h];
				Dir[i + 1][j][h]--;
			}
		}
	}
}

void make_smell() {
	for (int i = 1; i <= m; i++) {
		if (!shark[i].live) continue;

		int y = shark[i].y;
		int x = shark[i].x;
		int dir = shark[i].dir;

		smell[y][x] = {i, k};
	}
}

void move() {
	bool visit[MAX+1][MAX + 1];
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= m; i++) {
		if (!shark[i].live) continue;

		bool moved = false;
		int y = shark[i].y;
		int x = shark[i].x;
		int now_num = i;
		int now_dir = shark[i].dir;

		//ºóÄ­À» Ã£¾Æº»´Ù
		for (int h = 0; h < 4; h++) {
			int didx = Dir[now_num][now_dir][h];
			int ny = y + dy[didx];
			int nx = x + dx[didx];

			if (!is_range(ny, nx)) continue;
			if (smell[ny][nx].k > 0) continue;
			//if (h >= 4 && smell[i][j].num != now_num) continue;

			if (!visit[ny][nx]) {
				shark[i] = { ny,nx, didx, true };
				visit[ny][nx] = true;
			}
			else {
				shark[i].live = false;
				killed++;
			}

			moved = true;
			break;
		}

		if (moved) continue;
		for (int h = 0; h < 4; h++) {
			int didx = Dir[now_num][now_dir][h];
			int ny = y + dy[didx];
			int nx = x + dx[didx];

			if (!is_range(ny, nx)) continue;
			if (i != smell[ny][nx].num) continue;
			//if (h >= 4 && smell[i][j].num != now_num) continue;

			if (!visit[ny][nx]) {
				shark[i] = { ny,nx, didx, true };
				visit[ny][nx] = true;
			}
			else {
				shark[i].live = false;
				killed++;
			}

			break;
		}
	}
}

void remove_smell() {
	//cout << "remove_smell" << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smell[i][j].k > 0) smell[i][j].k--;
			if (smell[i][j].k == 0) smell[i][j].num = 0;
		}
	}
}

void solve() {
	input();

	time = 0;
	while (1) {
		//print_shark();
		//print_smell();
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			if (shark[i].live) cnt++;
		}
		if (cnt == 1) break;
	
		if (time >= 1000) {
			time = -1;
			break;
		}
		make_smell();
		move();
		remove_smell();

		time++;
	}
	cout << time << '\n';
}

int main() {
	solve();
	
	return 0;
}
