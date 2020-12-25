#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, k;
int map[1001][1001];
int a, b, c, d;

void simul() {
	int J = 0, O = 0, I = 0;

	for (int i = a; i <= c; i++) {
		for (int j = b; j <= d; j++) {
			if (map[i][j] == 0) {
				J++;
			}
			else if (map[i][j] == 1) {
				O++;
			}
			else {
				I++;
			}
		}
	}
	cout << J << ' ' << O << ' ' << I << '\n';
}

//정글 0, 바다 1, 얼음 2
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			char c = s[j];
			if (c == 'J') {
				map[i][j] = 0;
			}
			else if (c == 'O') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 2;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		simul();
	}


	return 0;
}