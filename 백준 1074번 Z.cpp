#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int r, c;
int res;

void find(int len, int sy, int sx, int startNum) {
	if (sy == r && sx == c) {
		res = startNum;
		return;
	}

	int half = len / 2;
	int y = sy + half;
	int x = sx + half;

	if (r < y && c < x) {
		find(half, sy, sx, startNum);
	}
	else if (r < y && c >= x) {
		find(half, sy, x, startNum + half*half);
	}
	else if (r >= y && c < x) {
		find(half, y, sx, startNum + half * half * 2);
	}
	else {
		find(half, y, x, startNum + half * half * 3);
	}
}

int main() {
	cin >> n >> r >> c;

	find(pow(2, n), 0, 0, 0);

	cout << res << '\n';
}