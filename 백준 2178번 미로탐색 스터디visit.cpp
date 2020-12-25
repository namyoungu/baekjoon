//visit맵을 통한 카운팅
#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point{
	int y, x;
};

int n, m;
int map[100][100], visit[100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

queue<point> q;

bool range_check(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) {
		return true;
	}
	return false;
}

bool Is_empty(int y, int x) {
	if (map[y][x] == 0) {
		return false;
	}
	return true;
}

bool Is_visit(int y, int x) {
	if (visit[y][x] == 0) return true;
	return false;
}

void bfs() {
	q.push({0, 0}); //시작점이 원점이라 가정했을 때
	visit[0][0] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {//사방의 좌표
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];
			
			//맵 밖으로 나가지는지 확인
			//맵상에서 이동가능한 곳인지 확인
			//방문한 곳인지 아닌지 확인
			if (range_check(ty, tx) && Is_empty(ty, tx) && Is_visit(ty, tx)) {
				q.push({ty, tx});
				visit[ty][tx] = visit[t.y][t.x] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();
	printf("%d\n", visit[n-1][m-1]);
	return 0;
}