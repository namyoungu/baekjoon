#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, k;
int sy, sx, num;
int map[129][129];

bool isEmpty(int y, int x, int sz) {
	for (int i = y; i < y + sz; i++) {
		for (int j = x; j < x + sz; j++) {
			if (map[i][j] != 0) return false;
		}
	}
	return true;
}

void solve(int y, int x, int sz) {
	num++;
	int s = sz / 2;
	if (isEmpty(y, x, s)) {
		map[y + s - 1][x + s - 1] = num;
	}
	if (isEmpty(y, x + s, s)) {
		map[y + s - 1][x + s] = num;
	}
	if (isEmpty(y + s, x, s)) {
		map[y + s][x + s - 1] = num;
	}
	if (isEmpty(y + s, x + s, s)) {
		map[y + s][x + s] = num;
	}
	if (sz == 2) return;

	solve(y, x, s);
	solve(y, x + s, s);
	solve(y + s, x, s);
	solve(y + s, x + s, s);
}

int main() {
	cin >> k;
	cin >> sx >> sy;
	sx--; sy--;
	n = pow(2, k);

	map[sy][sx] = -1;

	solve(0, 0, 1 << k);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}