#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

struct point {
	int y, x;
};

int n, m, map[101][101];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt[101][101];

bool bfs(int y, int x) {
	queue<point>q;
	bool visit[100][100] = {false, };

	q.push({y, x});
	visit[y][x] = true;

	while (!q.empty()) {
		//system("pause");
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
			if (visit[ty][tx]) continue;

			if (map[ty][tx] == 1) cnt[ty][tx]++;

			if (map[ty][tx] == 0){
				q.push({ty, tx});
				visit[ty][tx] = true;
			}
		}
	}
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt[i][j] >= 2) {
				map[i][j]--;
				flag = true;
			}
		}
	}

	return flag;
}

void simul() {
	int time = 0;
	while (bfs(0, 0)) {
		//puts("");
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << map[i][j] << ' ';
		//	}
		//	puts("");
		//}

		memset(cnt, 0, sizeof(cnt));
		time++;
	}
	cout << time << '\n';
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	simul();

	return 0;
}