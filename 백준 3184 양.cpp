#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int r, c, c_w, c_y, t_y, t_x;
char arr[251][251];
int a[] = { -1, 0, 1, 0 }, b[] = { 0, 1, 0, -1 };

struct point {
	int y, x;
};

queue <point> q;

void bfs(int y, int x) {
	q.push({ y, x });

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			t_y = t.y + a[i];
			t_x = t.x + b[i];
			
			if (t_y >= 0 && t_x >= 0 && t_y < r && t_x < c && arr[t_y][t_x] != '#') {
				if (arr[t_y][t_x] == 'o') {
					c_y++;
				}
				if (arr[t_y][t_x] == 'v') {
					c_w++;
				}
				arr[t_y][t_x] = '#';
				q.push({ t_y, t_x });
			}
		}
	}
}




point t_c;
int main(void) {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);

	int r_cw = 0, r_cy = 0;
	for(int i=0; i<r; i++)
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != '#') {
				c_y = 0;
				c_w = 0;
				if (arr[i][j] == 'v')
					c_w++;
				if (arr[i][j] == 'o')
					c_y++;
				arr[i][j] = '#';
				bfs(i, j);

				if (c_w >= c_y) {
					r_cw += c_w;
				}
				else {
					r_cy += c_y;
				}
			}
		}
	
	printf("%d %d", r_cy, r_cw);
	return 0;
}