#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define white 0
#define black 1

int S, N, K;
int R1, R2, C1, C2;
int map[100][100];

bool isBlack(int t) {
	if ((N - K) / 2 <= t && t < (N - K) / 2 + K) return true;
	return false;
}


bool isRange(int r1, int c1, int r2, int c2) {
	if (R2 < r1 || r2 < R1) return false;
	if (C2 < c1 || c2 < C1) return false;
	return true;
}

void solve(int y, int x, int s, int color) {
	int t = pow(N, S-s);
	if (!isRange(y * t, x * t, y * t + t - 1, x * t + t - 1)) return;

	if (s == S) {
		map[y - R1][x - C1] = color;
		return;
	}

	int ncolor;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(color  == black)
				ncolor = black;
			else
				ncolor = (isBlack(i) && isBlack(j));

			solve(y * N + i, x * N + j, s + 1, ncolor);
		}
	}
	
}

int main() {
	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;

	solve(0, 0, 0, 0);

	for (int i = 0; i < R2 - R1 + 1; i++) {
		for (int j = 0; j < C2 - C1 + 1; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}