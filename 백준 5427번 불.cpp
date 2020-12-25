#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int test_case, w, h, v[1001][1001], fire[1000][1000], a[] = { 1,-1, 0, 0 }, b[] = {0, 0, 1, -1};
char map[1001][1001];

struct point {
	int y, x;
};

queue<point> q;

void burn(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int t_y = y + a[i];
		int t_x = x + b[i];

		if (t_x >= 0 && t_x < h && t_y >= 0 && t_y < w) {
			if (fire[t_y][t_x] == 0 || map[t_y][t_x] == '@') {
				fire[t_y][t_x] = 1;
			}
		}
	}
}

void run(int y, int x) {
	v[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int t_y = y + a[i];
		int t_x = x + b[i];

		if (t_x >= 0 && t_x < h && t_y >= 0 && t_y < w) {
			if (fire[t_y][t_x] == 0) {
				v[t_y][t_x] = v[y][x] + 1;
			}
		}
	}
}



int main(void) {
	scanf("%d", &test_case);

	for (int z = 0; z < test_case; z++) {
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", &map[i]);
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '#') {
					fire[i][j] = 2;
				}

				else if (map[i][j] == '*') {
					fire[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (fire[i][j] == 1) {
					burn(i, j);
				}

				else if (map[i][j] == '@' && v[i][j] == 0) {
					run(i, j);
				}
			}
		}
	}

	return 0;
}

//v[y][x] = 1;
//q.push({ y, x });

//while (!q.empty()) {
//	point t = q.front();
//	q.pop();

//	for (int i = 0; i < 4; i++) {
//		int t_y = t.y + a[i];
//		int t_x = t.x + b[i];

//		if (t_x > 0 && t_x < h-1 && t_y > 0 && t_y < w-1) {
//			if (map[t_y][t_x] == '.') {
//				v[t_y][t_x] = v[t.y][t.x] + 1;
//			}
//		}

//		else if (t_x == 0 && t_y < w && map[t_y][t_x] == '.'){
//			printf("%d\n", v[t_y][t_x] - 1);
//		}

//		else if (t_x == h-1 && t_y < w && map[t_y][t_x] == '.') {
//			printf("%d\n", v[t_y][t_x] - 1);
//		}

//		else if (t_x < h && t_y == 0 && map[t_y][t_x] == '.') {
//			printf("%d\n", v[t_y][t_x] - 1);
//		}

//		else if (t_x < h && t_y == w-1 && map[t_y][t_x] == '.') {
//			printf("%d\n", v[t_y][t_x] - 1);
//		}
//	}
//}