#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, map[126][126], cache[126][126][4];
int dy[4] = {1, -1, 0, 0};
int dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x, int d) {
	if (y == n - 1 && x == n - 1) return map[y][x];
	
	int &res = cache[y][x][d];
	if (res != -1) return res;

	res = 987654321;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

		res = min(res, dfs(ny, nx, i) + map[y][x]);
	}
	return res;
}

int main() {
	int z = 0;
	while (1) {
		z++;
		cin >> n;
		if (n == 0) break;
		
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int ans = min(dfs(0, 0, 0), dfs(0, 0, 2));
		
		cout << "Problem "; cout << z; cout << ": ";
		cout << ans << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << cache[i][j] << ' ';
			}
			puts("");
		}
		puts("");
	}


	return 0;
}