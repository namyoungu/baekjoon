#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1000 + 1

struct point {
	int y, x;
};

int n, m, pCnt;
bool endCondition;
int map[MAX][MAX];
int range[10];
int res[10] = {0, };
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
queue<point> q[10];

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

bool isRange(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}

void input() {
	cin >> n >> m >> pCnt;
	for (int i = 0; i < pCnt; i++) {
		cin >> range[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;

			if (c == '.') {
				map[i][j] = -1;
			}
			else if (c == '#') {
				map[i][j] = -2;
			}
			else {
				int num = c - '1';
				map[i][j] = num;
				q[num].push({i, j});
				res[num]++;
			}
		}
	}
	//printMap();
}

void bfs(int num, int Range) {
	while (!q[num].empty() && Range--) {

		int size = q[num].size();
		while (size--) {
			point t = q[num].front();
			q[num].pop();

			for (int i = 0; i < 4; i++) {
				int ty = t.y + dy[i];
				int tx = t.x + dx[i];

				if (!isRange(ty, tx)) continue;
				if (map[ty][tx] != -1) continue;

				map[ty][tx] = num;
				q[num].push({ ty, tx });
				res[num]++;
				endCondition = false;
			}
		}
	}
	//printMap();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	while (1) {
		endCondition = true;
		for (int z = 0; z < pCnt; z++) {
			bfs(z, range[z]);
		}
		if (endCondition) break;
	}

	//printMap();
	for (int i = 0; i < pCnt; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}