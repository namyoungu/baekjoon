#include <iostream>
#include <queue>
using namespace std;

int n, m, cnt, year, danoc, mi[300][300], map[300][300], v[300][300], a[] = {1, -1, 0, 0}, b[] = {0, 0, 1, -1};

void f(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int t_y = y + a[i];
		int t_x = x + b[i];

		if (t_y >= 0 && t_y < n && t_x >= 0 && t_x < m) {
			if (map[t_y][t_x] == 0 && map[y][x] >0) {
				mi[y][x] += 1;
				//danoc = 1;
			}
		}
	}
}

struct point {
	int y, x;
};

queue<point> q;

void bfs(int y, int x) {
	q.push({y, x});
	v[y][x] = 1;

	while(!q.empty()){
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int t_y = t.y + a[i];
			int t_x = t.x + b[i];

			if (t_x >= 0 && t_x < m && t_y >= 0 && t_y < n) {
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
		//danoc = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] = 0;
				f(i, j);
			}
		}
		//if (danoc == 0) {
		//	printf("%d\n", 0);
		//	return 0;
		//}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mi[i][j] > 0) {
					map[i][j] -= mi[i][j];
					if (map[i][j] < 0) {
						map[i][j] = 0;
					}
					mi[i][j] = 0;
				}
			}
		}
		year++;

		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 0 && map[i][j] > 0) {
					bfs(i, j);
					cnt++;
					if (cnt >= 2) {
						printf("%d\n", year);
						return 0;
					}
				}
			}
		}
		if (cnt == 0) {
			printf("%d\n", 0);
			return 0;
		}
	}

	return 0;
}