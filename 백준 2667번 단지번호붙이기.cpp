#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int n, map[25][25], visit[25][25];
int cnt;
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };

queue<point>q;
vector<int>v;

void bfs(int y, int x) {
	int k = 1;
	q.push({ y, x });
	visit[y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= n) continue;
			if (visit[ty][tx] == 0 && map[ty][tx] == 1) {
				q.push({ ty, tx });
				visit[ty][tx] = 1;
				k++;
			}
		}
	}
	v.push_back(k);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}