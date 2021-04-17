#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 2200

int n;
char map[MAX][MAX];


void solve(int y, int x, int k) {
	if (k == 1) {
		int t = 0;
		for (int i = y; i < y + 3; i++) {
			for (int j = x; j < x + 3; j++) {
				t++;
				if (t == 5) {
					//map[i][j] = ' ';
					continue;
				}
				map[i][j] = '*';
			}
		}
		return;
	}

	int len = pow(3, k);
	int t = 0;
	for (int i = y; i < y + len; i += (len / 3)) {
		for (int j = x; j < x + len; j += (len / 3)) {
			t++;
			if (t == 5) continue;
			solve(i, j, k-1);
		}
	}
}


int main() {
	cin >> n;

	int k = 0;
	while (n / 3 != 0) {
		k++;
		n /= 3;
	}
	
	solve(0, 0, k);

	int len = pow(3, k);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (map[i][j] == '*')
				cout << map[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}