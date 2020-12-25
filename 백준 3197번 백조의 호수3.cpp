#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

struct point {
	int y, x;
};

queue<point>waterQ;
queue<point>sQ;
queue<point>t_sQ;
pair<int, int>start_p;

int w, h, s_cnt = 0;
int swanv[1500][1500], a[] = { 0, 0, 1, -1 }, b[] = {1, -1, 0, 0};
char map[1501][1501];

void bfs() {
	while (!waterQ.empty()) {
		int w_sz = waterQ.size();
		for (int z = 0; z < w_sz; z++) {
			point t = waterQ.front();
			waterQ.pop();

			for (int i = 0; i < 4; i++) {
				int t_y = t.y + a[i];
				int t_x = t.x + b[i];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w) {
					if (map[t_y][t_x] == 'X') {
						map[t_y][t_x] = '.';
						waterQ.push({t_y, t_x});
					}
				}
			}
		}

		////
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++) {
		//		printf("%c", map[i][j]);
		//	}
		//	puts("");
		//}
		////
	
		while (!sQ.empty()) {
			point t = sQ.front();
			sQ.pop();
			swanv[t.y][t.x] = 1;

			for (int i = 0; i < 4; i++) {
				int t_y = t.y + a[i];
				int t_x = t.x + b[i];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && swanv[t_y][t_x] == 0) {
					if (map[t_y][t_x] == 'L') {
						return;
					}

					else if (map[t_y][t_x] == '.') {
						swanv[t_y][t_x] = 1;
						sQ.push({t_y, t_x});
					}
					else if (map[t_y][t_x] == 'X') {
						swanv[t_y][t_x] = 1;
						t_sQ.push({t_y, t_x});
					}
				}
			}
		}
		
		while (!t_sQ.empty()) {
			sQ.push(t_sQ.front());
			t_sQ.pop();
		}

		////
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++) {
		//		printf("%d", swanv[i][j]);
		//	}
		//	puts("");
		//}
		////

		s_cnt++;
	}
}

int main(void) {
	scanf("%d %d", &h, &w);
	for(int i=0; i<h; i++){
		scanf("%s", map[i]);
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'L' || map[i][j] == '.') {
				if (map[i][j] == 'L') {
					start_p.first = i;
					start_p.second = j;
				}
				waterQ.push({i, j});
			}
		}
	}

	sQ.push({start_p.first, start_p.second });

	bfs();
	
	s_cnt++;
	printf("%d\n", s_cnt);
	return 0;
}
