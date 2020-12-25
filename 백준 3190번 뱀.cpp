#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int time;
	char dir;
};

struct point2{
	int y, x;
};

int n, k, l;
int map[100][100], test[100][100];
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
int now_d;

queue<point2>snake;
point x[10001];

bool endcase(int ty, int tx) {
	if (ty < 0 || tx < 0 || ty >= n || tx >= n ) {
		//printf("123123\n");
		return true;
	}

	int sz = snake.size();
	while (sz--) {
		point2 t = snake.front();
		snake.pop();
		snake.push(t);

		if (t.y == ty && t.x == tx) {
			return true;
		}
	}
	return false;
}

int simul() {
	snake.push({0, 0});
	now_d = 0;
	point2 head = {0, 0};
	
	for (int i = 1; i <= 10000; i++) {
		head = snake.back();

		//새로운 머리 좌표
		int ty = head.y + dy[now_d];
		int tx = head.x + dx[now_d];

		//종료조건 만족하면 몇 초에 끝나는지 return
		if (endcase(ty, tx)) {
			return i;
		}

		//일단 머리 이동
		snake.push({ ty, tx });

		test[ty][tx] = 1;

		//사과가 없으면 꼬리 자르기
		if (map[ty][tx] == 0) {

			point2 tmp = snake.front();
			test[tmp.y][tmp.x] = 0;

			snake.pop();
		}
		map[ty][tx] = 0;//사과 먹었으니까 사라짐

		//방향전환
		if (x[i].time == 1) {
			if (x[i].dir == 'D') {
				now_d = (now_d + 1) % 4;
			}
			else {
				now_d = (now_d + 3) % 4;
			}
		}

		/*for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				printf("%d ", test[a][b]);
			}
			puts("");
		}
		puts("");*/
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[--r][--c] = 1;
		test[r][c] = 2;
	}

	int t; char tt;
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &t, &tt);
		x[t].time = 1;
		x[t].dir = tt;
	}
	int result = simul();
	printf("%d\n", result);
	return 0;
}