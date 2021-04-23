#include <iostream>
#include <algorithm>
using namespace std;

int n;
int width[12];
int height[12];
char map[3500][6500];

int retK(int k) {
	int t = 0;
	while (k/2 != 0) {
		t++;
		k /= 2;
	}

	return t;
}

void solve(int y, int x, int k) {
	if (k == 0) {
		map[y][x] = '*';
		map[y+1][x-1] = '*'; map[y+1][x+1] = '*';
		map[y+2][x-2] = '*'; map[y + 2][x-1] = '*'; map[y + 2][x] = '*'; map[y + 2][x+1] = '*'; map[y + 2][x+2] = '*';
		return;
	}
	solve(y, x, k - 1);
	solve(y + height[k - 1], x - width[k - 1] / 2 - 1, k - 1);
	solve(y + height[k - 1], x + width[k - 1] / 2 + 1, k - 1);
}

int main() {
	width[0] = 5;
	height[0] = 3;
	for (int i = 1; i <= 10; i++) {
		width[i] = width[i - 1] * 2 + 1;
		height[i] = height[i - 1] * 2;

	}

	cin >> n;

	int k = n/3;
	k = retK(k);

	solve(0, width[k]/2, k);

	for (int i = 0; i < height[k]; i++) {
		for (int j = 0; j < width[k]; j++) {
			if (map[i][j] == '*') {
				cout << map[i][j];
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}