#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

#define INF 987654321

int test;
int clocks[16];

int mat[10][5] = { {0, 1, 2},
					{3, 7, 9, 11},
					{4, 10, 14, 15},
					{0, 4, 5, 6, 7},
					{6, 7, 8, 10, 12},
					{0, 2, 14, 15},
					{3, 14, 15},
					{4, 5, 7, 14, 15},
					{1, 2, 3, 4, 5},
					{3, 4, 5, 9, 13} };

int sizeMat[10] = { 3, 4, 4, 5, 5, 4, 3, 5, 5, 5 };

bool isCorrect() {
	for (int i = 0; i < 16; i++) {
		if (clocks[i] != 12) return false;
	}
	return true;
}

void move(int button, int pcal) {
	int sz = sizeMat[button];
	for (int i = 0; i < sz; i++) {
		int targetCk = mat[button][i];
		clocks[targetCk] += 3 * pcal;
		if (clocks[targetCk] == 15) clocks[targetCk] = 3;
	}
}

int retCnt(int button) {
	if (button == 10) {
		return isCorrect() ? 0 : INF;
	}

	int res = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		res = min(res, cnt + retCnt(button + 1));
		move(button, 1);
	}

	return res;
}

int main() {
	cin >> test;
	while (test--) {
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
		}

		int res = retCnt(0);
		if (res == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << res << '\n';
		}
	}

	return 0;
}