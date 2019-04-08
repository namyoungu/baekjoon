#define _CRT_SECURE_NO_WANINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int k, cnt;
int map[50][50], a[] = { 0, 0, 1, -1 }, b[] = {1, -1, 0, 0};

struct point {
	int y, x;
};

queue <point> q;//bfs
queue <point> qs;//m, n의 값을 저장
queue <point> qp;//양배추의 좌표 저장
queue <int> qk;//양배추의 수 저장

void bfs(int y, int x, int n, int m) {
	map[y][x] = 2;
	q.push({ y, x });
	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + a[i];
			int tx = t.x + b[i];

			if (tx >= 0 && ty >= 0 && tx < m && ty < n) {
				if (map[ty][tx] == 1) {
					q.push({ ty, tx });
					map[ty][tx] = 2;
				}
			}
		}
	}
}

int main(void) {
	int test_case, m, n, y, x;

	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d %d", &m, &n, &k);
		qs.push({ n, m});
		qk.push(k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			qp.push({ y, x });
		}
	}

	for (int z = 0; z < test_case; z++) {//맵 세팅
		k = qk.front();
		qk.pop();
		for (int i = 0; i < k; i++) {
			point tmp = qp.front();
			qp.pop();
			map[tmp.y][tmp.x] = 1;
		}

		cnt = 0;
		point tmp2  = qs.front();
		qs.pop();

		for (int i = 0; i < tmp2.y; i++)
			for (int j = 0; j < tmp2.x; j++) {
				if (map[i][j] == 1) {
					
					bfs(i, j, tmp2.y, tmp2.x);
					cnt++;
				}
			}

		for (int i = 0; i < tmp2.y; i++)
			for (int j = 0; j < tmp2.x; j++)
				map[i][j] = 0;

	printf("%d\n", cnt);
	}
	return 0;
}
