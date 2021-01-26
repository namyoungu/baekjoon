#include <iostream>
#include <algorithm>
using namespace std;

struct fish {
	int num, y, x, dir;
	bool live;
};

fish fishes[17];
int map[5][5];
int res = 0;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};


void print_map(int map[][5]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool is_range(int y, int x) {
	if (y < 0 || y >= 4 || x < 0 || x >= 4) return false;
	return true;
}

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			dir--;

			map[i][j] = num;
			fishes[num] = { num, i, j, dir, true };
		}
	}
}

void copy_state(int A[][5], int B[][5], fish C[], fish D[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			A[i][j] = B[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) C[i] = D[i];
}

void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (!fishes[i].live) continue;

		int y = fishes[i].y;
		int x = fishes[i].x;
		int dir = fishes[i].dir;

		for (int j = 0; j < 8; j++) {
			int ndir = (dir + j) % 8;
			int ny = y + dy[ndir];
			int nx = x + dx[ndir];

			if (!is_range(ny, nx)) continue;
			if (map[ny][nx] == -1) continue;

			if (map[ny][nx] == 0) {
				fishes[i].y = ny;
				fishes[i].x = nx;
				fishes[i].dir = ndir;

				map[ny][nx] = i;
				map[y][x] = 0;
			}
			else {
				int nnum = map[ny][nx];
				fish tfish = fishes[nnum];

				map[ny][nx] = i;
				fishes[i] = { i, ny, nx, ndir, true };

				map[y][x] = tfish.num;
				fishes[nnum] = { nnum, y, x, tfish.dir, true };
			}

			break;
		}
	}
}

void dfs(int cnt, int sy, int sx, int sdir) {
	res = max(res, cnt);

	fish tfishes[17];
	int tmap[5][5];

	copy_state(tmap, map, tfishes, fishes);

	//fish moving
	move_fish();

	//shark moving and eat
	int ny = sy;
	int nx = sx;
	for (int i = 0; i < 3; i++) {
		int ndir;
		int fish_num;
		ny += dy[sdir];
		nx += dx[sdir];

		if (!is_range(ny, nx)) continue;
		if (map[ny][nx] == 0) continue;

		fish_num = map[ny][nx];
		ndir = fishes[fish_num].dir;

		map[ny][nx] = -1;
		map[sy][sx] = 0;
		fishes[fish_num].live = false;

		dfs(cnt + fish_num, ny, nx, ndir);

		map[ny][nx] = fish_num;
		map[sy][sx] = -1;
		fishes[fish_num].live = true;
	}
	copy_state(map, tmap, fishes, tfishes);
}

void solve() {
	input();

	int sdir;
	int killed = map[0][0];
	map[0][0] = -1;

	sdir = fishes[killed].dir;
	fishes[killed].live = false;

	dfs(killed, 0, 0, sdir);

	cout << res << '\n';
}


int main() {
	solve();
	return 0;
}