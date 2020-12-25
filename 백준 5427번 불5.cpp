#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int test_case, w, h, f_cnt=0, m_cnt=0, result=0;
int m_v[1000][1000], a[] = {1,-1,0,0}, b[] = {0,0,1,-1};
char s[1001][1001];

struct point {
	int y, x;
};

queue<point> fire;
queue<point> man;

int bfs(void) {
	while (!man.empty()) {
		int f_size = fire.size();
		for (int z = 0; z < f_size; z++) {
			point t = fire.front();
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int t_y = t.y + a[i];
				int t_x = t.x + b[i];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w) {
					if (s[t_y][t_x] != '#' && s[t_y][t_x] != '*') {
						s[t_y][t_x] = '*';
						fire.push({ t_y, t_x });
					}
				}
			}
		}

		int m_size = man.size();
		for (int z = 0; z < m_size; z++) {
			point t = man.front();
			man.pop();

			if (t.y == 0 || t.y == h - 1 || t.x == 0 || t.x == w - 1) {
				return result+1;
			}

			for (int i = 0; i < 4; i++) {
				int t_y = t.y + a[i];
				int t_x = t.x + b[i];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w) {
					if (m_v[t_y][t_x] == 0 && s[t_y][t_x] == '.') {
						m_v[t_y][t_x] = 1;
						man.push({ t_y, t_x });
					}
				}
			}
		}
		result++;
	}
	return -1;
}


int main(void){
	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d", &w, &h);

		for (int i = 0; i < h; i++) {
			scanf("%s", s[i]);
			for (int j = 0; j < w; j++) {
				if(s[i][j] == '*'){
					fire.push({i,j});
				}
				else if (s[i][j] == '@') {
					man.push({ i,j });
				}
			}
		}

		int g = bfs();
		if (g > 0) {
			printf("%d\n", g);
		}
		else {
			printf("%s\n", "IMPOSSIBLE");
		}
		result = 0;
		while (!fire.empty()) {
			fire.pop();
		}
		while (!man.empty()) {
			man.pop();
		}

		memset(m_v, 0, sizeof(m_v));
	}

	return 0;
}