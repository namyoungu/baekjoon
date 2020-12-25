#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int cnt = 0;
int a[] = { 1, -1, 0, 0 }, b[] = { 0, 0, 1, -1 };
int visit[5][5];
char map[5][6];

struct point {
	int y, x;
};

queue<point>q;
vector<point>s;

void check(int y, int x) {
	int tcnt = 0;
	int v[5][5] = {0, };
	//printf("%d %d\n", y, x);
	q.push({ y, x });
	v[y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (ty < 0 || ty >= 5 || tx < 0 || tx >= 5) continue;
			//printf("%d", 1);
			if (visit[ty][tx] == 1 && v[ty][tx] == 0) {
				v[ty][tx] = 1;
				q.push({ ty, tx });
				tcnt++;
				//system("pause");
			}
		}
	}
	//printf("%d\n", tcnt);
	//puts("");

	if (tcnt == 6) {
		cnt++;
	}
	return;
}

void dfs(int dep = 0, int start = 0) {
	if (dep == 7) {
		int scnt = 0;

		for (int i = 0; i < 7; i++) {
			int y = s[i].y;
			int x = s[i].x;

			if (map[y][x] == 'S') scnt++;
		}
		if (scnt < 4) return;

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d", visit[i][j]);
			}
			puts("");
		}
		puts("");*/


		check( s[0].y , s[0].x );
		//system("pause");
		return;
	}


	for(int i = start; i < 25; i++){
		int ty = i / 5;
		int tx = i % 5;

		visit[ty][tx] = 1;
		s.push_back({ty, tx});
		dfs(dep + 1, i+1);
		s.pop_back();
		visit[ty][tx] = 0;
	}
}

int main(void) {
	for (int i = 0; i < 5; i++) {
		scanf("%s", map[i]);
	}

	dfs();

	printf("%d\n", cnt);
	return 0;
}