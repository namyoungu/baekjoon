#include <iostream>
#include <algorithm>
using namespace std;

#define Max 500

int n, res = 0;
int map[Max][Max];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int now_y, now_x;

bool is_range(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return false;
	return true;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	now_y = n / 2;
	now_x = n / 2;
}

void print_map() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sand_move(int y, int x, int dir) {
	int sum = map[y][x];
	int five = map[y][x] * 0.05;
	int ten = map[y][x] * 0.1;
	int sev = map[y][x] * 0.07;
	int two = map[y][x] * 0.02;
	int one = map[y][x] * 0.01;
	int a = sum - five - ten * 2 - sev * 2 - two * 2 - one * 2;

	//five, ten, sev, two, one, a order
	
	//five
	int ty = now_y + dy[dir] * 2;
	int tx = now_x + dx[dir] * 2;

	if (!is_range(ty, tx)) res += five;
	else {
		map[ty][tx] += five;
	}



	//ten1
	ty = now_y + dy[dir] * 1;
	tx = now_x + dx[dir] * 1;

	if (dir == 0 || dir == 2) {
		ty++;
	}
	else {
		tx++; 
	}

	if (!is_range(ty, tx)) res += ten;
	else {
		map[ty][tx] += ten;
	}

	//ten2
	ty = now_y + dy[dir] * 1;
	tx = now_x + dx[dir] * 1;

	if (dir == 0 || dir == 2) {
		ty--;
	}
	else {
		tx--;
	}

	if (!is_range(ty, tx)) res += ten;
	else {
		map[ty][tx] += ten;
	}



	//seven1
	ty = now_y;
	tx = now_x;

	if (dir == 0 || dir == 2) {
		ty++;
	}
	else {
		tx++;
	}

	if (!is_range(ty, tx)) res += sev;
	else {
		map[ty][tx] += sev;
	}

	//seven2
	ty = now_y;
	tx = now_x;

	if (dir == 0 || dir == 2) {
		ty--;
	}
	else {
		tx--;
	}

	if (!is_range(ty, tx)) res += sev;
	else {
		map[ty][tx] += sev;
	}



	//two1
	ty = now_y;
	tx = now_x;

	if (dir == 0 || dir == 2) {
		ty+=2;
	}
	else {
		tx+=2;
	}

	if (!is_range(ty, tx)) res += two;
	else {
		map[ty][tx] += two;
	}

	//two2
	ty = now_y;
	tx = now_x;

	if (dir == 0 || dir == 2) {
		ty-=2;
	}
	else {
		tx-=2;
	}

	if (!is_range(ty, tx)) res += two;
	else {
		map[ty][tx] += two;
	}



	//one1
	ty = now_y - dy[dir];
	tx = now_x - dx[dir];

	if (dir == 0 || dir == 2) {
		ty += 1;
	}
	else {
		tx += 1;
	}

	if (!is_range(ty, tx)) res += one;
	else {
		map[ty][tx] += one;
	}

	//one2
	ty = now_y - dy[dir];
	tx = now_x - dx[dir];

	if (dir == 0 || dir == 2) {
		ty -= 1;
	}
	else {
		tx -= 1;
	}

	if (!is_range(ty, tx)) res += one;
	else {
		map[ty][tx] += one;
	}

	//a
	ty = now_y + dy[dir] * 1;
	tx = now_x + dx[dir] * 1;

	if (!is_range(ty, tx)) res += a;
	else {
		map[ty][tx] += a;
	}

	map[y][x] = 0;
	//print_map();
}

void tornado_move() {
	int move = 1;
	int dir = 0;

	while (1) {
		int tmove = move;
		while (tmove--) {
			now_y = now_y + dy[dir];
			now_x = now_x + dx[dir];
			//cout << now_y << ' ' << now_x << '\n';

			if(map[now_y][now_x] != 0)
				sand_move(now_y, now_x, dir);

			if (now_y == 0 && now_x == 0)
				return;
		}
		dir = (dir + 1) % 4;

		tmove = move;
		while (tmove--) {
			now_y = now_y + dy[dir];
			now_x = now_x + dx[dir];
			//cout << now_y << ' ' << now_x << '\n';

			if (map[now_y][now_x] != 0)
				sand_move(now_y, now_x, dir);

			if (now_y == 0 && now_x == 0)
				return;
		}
		dir = (dir + 1) % 4;

		move++;
	}
}

int main() {
	input();
	tornado_move();
	cout << res << '\n';

	return 0;
}