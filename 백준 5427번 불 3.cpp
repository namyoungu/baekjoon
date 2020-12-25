#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int test_case, w, h, s_x, s_y, result, c[1000][1000], v[1000][1000], a[] = { 1, -1, 0, 0 }, b[] = {0, 0, 1, -1};
char map[1001][1001];

struct point {
	int y, x;
};

queue<point> q, q_v;

int bfs(void) {
	while (!q_v.empty()) {
		int fire_size = q.size();//불번짐
		for (int i = 0; i < fire_size; i++) {
			point t = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int t_y = t.y + a[j];
				int t_x = t.x + b[j];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w) {
					if (map[t_y][t_x] == '.' || map[t_y][t_x] == '@') {
						map[t_y][t_x] = '*';
						q.push({ t_y, t_x });
					}
				}
			}
		}

		int run_size = q_v.size();//도망
		for (int i = 0; i < run_size; i++) {
			point t2 = q_v.front();
			q_v.pop();

			for (int j = 0; j < 4; j++) {
				int t_y = t2.y + a[j];
				int t_x = t2.x + b[j];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && v[t_y][t_x] == 0) {
					if (map[t_y][t_x] == '.') {
						c[t_y][t_x] = c[t2.y][t2.x] + 1;

						if (t_y == 0 || t_y == h - 1 || t_x == 0 || t_x == w - 1) {//입구에 서있다
							return c[t_y][t_x] + 1;
						}

						v[t_y][t_x] = 1;
						q_v.push({ t_y, t_x });
					}
				}
			}
		}
	}
	return -1;//상근이가 더 이상 무빙할 수 없음
}

int main(void) {
	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d", &w, &h);

		for (int i = 0; i < h; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '*') {
					q.push({ i, j });
				}
				else if (map[i][j] == '@') {
					q_v.push({i, j});
					v[i][j] = 1;
				}
			}
		}

		result = bfs();

		if (result < 0)  printf("%s\n", "IMPOSSIBLE");
		else printf("%d\n", result);


		while (!q.empty()) {
			q.pop();
		}
		
		memset(v, 0, sizeof(v));
		memset(c, 0, sizeof(c));
	}
	return 0;
}