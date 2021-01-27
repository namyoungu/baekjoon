#include <iostream>
#include <algorithm>
using namespace std;

int green[7][5];
int blue[7][5];
int n, t, sy, sx;
int score_line, score_line_cnt;
bool scored;
int res=0, res2=0;

void print_green() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << green[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print_blue() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << blue[i][j] << ' ';
		}
		cout << '\n';
	}
}


bool is_range(int y, int x) {
	if (y < 0 || y >= 6 || x < 0 || x >= 4) return false;
	return true;
}

void copy_map(int tmap[][5], int map[][5]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}

void pale_move(int map[][5]) {
	int dep = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) {
				dep++;
				break;
			}
		}
	}

	if (dep == 0) return;

	int tmap[7][5];

	copy_map(tmap, map);

	for (int i = 5; i >= 2; i--) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = tmap[i - dep][j];
		}
	}
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = 0;
		}
	}
}

void falling_by_score(int map[][5]) {
	int tmap[7][5];
	//cout << score_line << ' ' << score_line_cnt << '\n';
	copy_map(tmap, map);

	for (int i = score_line; i >= 0; i--) {
		if (i - score_line_cnt < 0) break;
		for (int j = 0; j < 4; j++) {
			map[i][j] = tmap[i- score_line_cnt][j];
		}
	}
}

void remove_score_line(int map[][5]) {
	score_line_cnt = 0;
	scored = false;

	for (int i = 0; i <= 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) cnt++;
		}
		if (cnt == 4) {
			for (int k = 0; k < 4; k++) {
				map[i][k] = 0;
			}
			score_line = i;
			score_line_cnt++;
			scored = true;
			res++;
		}
	}
}

void Gfirst_move(int map[][5]) {
	if (t == 1) {
		int y = 0;
		int x = sx;

		for (int i = 1; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1) {
				map[ny-1][x] = 1;
				break;
			}
		}
	}
	else if (t == 2) {
		int y = 0;
		int x = sx;

		for (int i = 1; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1 || map[ny][x+1] == 1) {
				map[ny - 1][x] = 1;
				map[ny - 1][x+1] = 1;
				break;
			}
		}
	}
	else {
		int y = 0;
		int x = sx;

		for (int i = 2; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1) {
				map[ny - 1][x] = 1;
				map[ny - 2][x] = 1;
				break;
			}
		}
	}
}

void Bfirst_move(int map[][5]) {
	if (t == 1) {
		int y = 0;
		int x = sy;

		for (int i = 1; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1) {
				map[ny - 1][x] = 1;
				break;
			}
		}
	}
	else if (t == 2) {
		int y = 0;
		int x = sy;

		for (int i = 2; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1) {
				map[ny - 1][x] = 1;
				map[ny - 2][x] = 1;
				break;
			}
		}
	}
	else {
		int y = 0;
		int x = sy;

		for (int i = 1; i <= 6; i++) {
			int ny = y + i;

			if (map[ny][x] == 1 || map[ny][x + 1] == 1) {
				map[ny - 1][x] = 1;
				map[ny - 1][x + 1] = 1;
				break;
			}
		}
	}
}

void count_blocks() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1) res2++;
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[i][j] == 1) res2++;
		}
	}
}

void set_edge() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 6 || j == 4) {
				green[i][j] = 1;
				blue[i][j] = 1;
			}
		}
	}
}

void solve() {
	set_edge();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> sy >> sx;

		Gfirst_move(green);

		//cout << "---green---" << '\n';
		//print_green();


		remove_score_line(green);
		if(scored)	falling_by_score(green);
		pale_move(green);



		Bfirst_move(blue);

		//cout << "---blue---" << '\n';
		//print_blue();

		remove_score_line(blue);
		if (scored)	falling_by_score(blue);
		pale_move(blue);

		//cout << "---green af---" << '\n';
		//print_green();
		//cout << "---blue af---" << '\n';
		//print_blue();

	}
	//print_green();
	//print_blue();
	count_blocks();
	cout << res << '\n';
	cout << res2 << '\n';
}

int main() {
	solve();
	return 0;
}