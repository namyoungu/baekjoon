#include <iostream>
#include <queue>
using namespace std;

int n, m, map[300][300], a[] = {1,-1,0,0}, b[] = {0,0,1,-1}, v[300][300], cnt, mi[300][300], y_cnt;

struct point {
	int y, x;
};

queue <point> q;

void melt(int y, int x) {
	point t = {y, x};
	
	for (int i = 0; i < 4; i++) {
		int t_y = t.y + a[i];
		int t_x = t.x + b[i];

		if (t_y >= 0 && t_x >= 0 && t_y < n && t_x < m) {
			if (map[t_y][t_x] == 0) {
				if (map[t.y][t.x] > 0) {
					mi[t.y][t.x] += 1;
				}
			}
		}
	}
}

void bfs(int y, int x) {
	v[y][x] = 1;
	q.push({y,x});

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int t_y = t.y + a[i];
			int t_x = t.x + b[i];

			if (t_y >= 0 && t_x >= 0 && t_y < n && t_x < m) {
				if (v[t_y][t_x] == 0 && map[t_y][t_x] > 0) {
					v[t_y][t_x] = 1;
					q.push({ t_y, t_x });
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0) {
					melt(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] -= mi[i][j];
				if (map[i][j] < 0) {
					map[i][j] = 0;
				}
				mi[i][j] = 0;
			}
		}

		int  zero = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0) {
					zero = 1;
				}
			}
		}
		if (zero == 0) {
			printf("%d\n", 0);
			return 0;
		}
		y_cnt++;

		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 0 && map[i][j] > 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			printf("%d\n", y_cnt);
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] = 0;
			}
		}
	}
	return 0;
}