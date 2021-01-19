#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 999

int n, k, xx, yy;
int a[1000][1000] = {0, };
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int y=0, x=0;

void input() {
	cin >> n >> k;
}

void print_a() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool is_range(int y, int x) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	return true;
}

void solve() {
	input();

	int d = 0;
	y = 0; x = 0;
	for (int i = n * n; i; i--) {
		a[y][x] = i;

		if (i == k) { 
			yy = y;
			xx = x;
		}
		if (!is_range(y + dy[d], x + dx[d]) || a[y + dy[d]][x + dx[d]] != 0) {
			d = (d + 1) % 4;
		}
		y = y + dy[d];
		x = x + dx[d];
	}

	print_a();
	cout << yy + 1 << ' ' << xx + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}