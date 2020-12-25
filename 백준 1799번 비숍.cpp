#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int n;
int map[10][10], tmap[10][10], visit[10][10];
int dy[] = { -1, 1, 1, -1 }, dx[] = {1, 1, -1, -1};
int res = INT_MIN;
bool can_go[10][10] = { false, };
//bool t_go[10][10];

vector<point>v;

void re_road(int y, int x) {
	can_go[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ty = y;
		int tx = x;
		while (1) {
			ty += dy[i];
			tx += dx[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) break;
			can_go[ty][tx] = true;
		}
	}
	//벽만 복구
	/*for (int i = 0; i < v.size(); i++) {
		map[v[i].y][v[i].x] = 1;
	}*/

	return;
}

int make_road(int y, int x, int rm) {
	can_go[y][x] = false;
	rm--;
	for (int i = 0; i < 4; i++) {
		int ty = y;
		int tx = x;
		while (1) {
			ty += dy[i];
			tx += dx[i];
			//printf("ty %d tx %d\n", ty, tx);
			//system("pause");
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) break;
			if (can_go[ty][tx] == true) {
				can_go[ty][tx] = false;
				rm--;
			}
		}
	}
	return rm;
}

void dfs(int p, int cnt, int remains) {
	int y = p / n;
	int x = p % n;

	//printf("%d\n", wh);
	//printf("%d %d\n", y, x);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%d ", can_go[i][j]);
	//	}
	//	puts("");
	//}
	//puts("");

	//if (can_go[0][1] == true) {
		//printf("cnt=%d\n", cnt);
		//system("pause");
	//}
	

	if (p == n * n) {
		res = max(res, cnt);

		/*if (cnt == 4) {
			for (int i = 0; i < v.size(); i++) {
				tmap[v[i].y][v[i].x] = 2;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", tmap[i][j]);
				}
				puts("");
			}
			puts("");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", can_go[i][j]);
				}
				puts("");
			}
			puts("");

			system("pause");
		}*/

		return;
	}

	if (cnt + remains < res) return;

	//맵이 0이라서 또는 다른 비숍한테 먹혀서 갈 수 없을 때
	if (map[y][x] == 0 || can_go[y][x] == false) {
		dfs(p + 1, cnt, remains);
	}
	//갈 수 있을 때
	else {
		//간다
		v.push_back({ y,x });

		//can_go 임시저장
		bool t_go[10][10];
		int rm = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bool tmp = can_go[i][j];
				t_go[i][j] = tmp;
				if (tmp == true) rm++;
			}
		}

		int t = make_road(y, x, remains);
		dfs(p + 1, cnt + 1, remains - t);

		//can_go 롤백
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				can_go[i][j] = t_go[i][j];
			}
		}

		//re_road(y, x);
		v.pop_back();

		//안간다
		dfs(p + 1, cnt, remains);
	}
}

int main() {
	scanf("%d", &n);
	int rm=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			tmap[i][j] = map[i][j];
			if (map[i][j] == 1) {
				can_go[i][j] = true;
				rm++;
			}
		}
	}

	dfs(0, 0, rm);
	printf("%d\n", res);
	return 0;
}