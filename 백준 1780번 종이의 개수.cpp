#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 2188

int n;
int oneCnt, zeroCnt, moneCnt;
int map[MAX][MAX];

void counting(int num) {
	if (num == -1) {
		moneCnt++;
	}
	else if (num == 0) {
		zeroCnt++;
	}
	else {
		oneCnt++;
	}
}

void solve(int y, int x, int size) {
	if (size == 1) {
		counting(map[y][x]);
		return;
	}
	
	bool br = false;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (map[y][x] != map[i][j]) {
				br = true;
				break;
			}
			if (br) break;
		}
	}

	if (br) {
		for (int i = y; i < y + size; i += (size/3)) {
			for (int j = x; j < x + size; j += (size/3)) {
				solve(i, j, size / 3);
			}
		}
	}
	else {
		counting(map[y][x]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, n);

	cout << moneCnt << '\n';
	cout << zeroCnt << '\n';
	cout << oneCnt << '\n';
	return 0;
}