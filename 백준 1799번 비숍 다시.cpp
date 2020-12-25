#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, res = INT_MIN;
int map[10][10];
int dy[] = { 1, -1 }, dx[] = { 1, 1 };
bool can_go[10][10] = { false, };

void paint(int y, int x) {
	//놓는 점 방문체크
	can_go[y][x] = false;

	for (int i = 0; i < 2; i++) {
		int ty = y;
		int tx = x;
		while (1) {
			ty += dy[i];
			tx += dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= n) break;
			can_go[ty][tx] = false;
		}
	}
	return;
}

bool check(int y, int x) {
	if (map[y][x] == 0 || can_go[y][x] == false) return false;
	return true;
}

void dfs(int dep, int y, int x, int cnt) {
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%d ", can_go[i][j]);
	//	}
	//	puts("");
	//}
	//puts("");
	//printf("%d\n", x);
	//system("pause");
	//printf("%d\n", dep);
	if (x == n) {
		res = max(res, cnt);
		return;
	}

	//다음 열로 이동
	if (y == n) {
		dfs(dep, 0, x + 1, cnt);
	}
	else {
		//놓을 수 없으면 다음 칸으로 이동
		if (map[y][x] == 0 || !check(y, x)) {
			dfs(dep + 1, y + 1, x, cnt);
		}
		else {
			//1.안놓는다
			dfs(dep + 1, y + 1, x, cnt);

			//2.놓는다

			//칠하기 전 상태 저장
			bool t_go[10][10];
			for (int i = 0; i < n; i++) {
				for (int j = x; j < n; j++) {
					bool tmp = can_go[i][j];
					t_go[i][j] = tmp;
				}
			}
			paint(y, x);

			dfs(dep + 1, y + 1, x, cnt + 1);

			//can_go 롤백
			for (int i = 0; i < n; i++) {
				for (int j = x; j < n; j++) {
					can_go[i][j] = t_go[i][j];
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			map[i][j] = t;
			if (t == 1) {
				can_go[i][j] = true;
			}
		}
	}

	dfs(0, 0, 0, 0);
	printf("%d\n", res);
	return 0;
}