#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

struct point {
	int y, x;
};

int w, h;
int map[1000][1000];
int visit[2][1000][1000];
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };

queue<point>q;
queue<point>qq;

void bfs(int y, int x) {
	q.push({ y, x });
	visit[0][y][x] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty == h - 1 && tx == w - 1) {
				printf("  %d\n", visit[0][t.y][t.x] + 2);
				exit(0);
			}

			if (ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
			if (map[ty][tx] == 0 && visit[0][ty][tx] == 0) {
				q.push({ ty, tx });
				visit[0][ty][tx] = visit[0][t.y][t.x] + 1;
			}
			else if (map[ty][tx] == 1 && visit[0][ty][tx] == 0) {
				//if (crush == 1) {
					//crush--;
				//system("pause");
				//printf("%d %d\n", ty, tx);
				qq.push({ ty, tx });
				visit[1][ty][tx] = visit[0][t.y][t.x] + 1;

				while (!qq.empty()) {

					point tt = qq.front();
					qq.pop();

					for (int l = 0; l < 4; l++) {
						int tty = tt.y + dy[l];
						int ttx = tt.x + dx[l];

						//printf("%d %d\n", tty, ttx);
						if (tty == h - 1 && ttx == w - 1) {
							/*for (int u = 0; u < h; u++) {
								for (int z = 0; z < w; z++) {
									printf("%d ", visit[1][u][z]);
								}
								puts("");
							}
							puts("");*/

							printf("%d\n", visit[1][tt.y][tt.x] + 1);
							exit(0);
						}

						if (tty < 0 || ttx < 0 || tty >= h || ttx >= w) continue;
						if (map[tty][ttx] == 0 && visit[0][tty][ttx] == 0 && visit[1][tty][ttx] == 0) {
							qq.push({ tty, ttx });
							visit[1][tty][ttx] = visit[1][tt.y][tt.x] + 1;
							//printf("%d\n", visit[1][tty][ttx]);
							//system("pause");
						}
					}
				}
			}
			/*for (int u = 0; u < h; u++) {
				for (int z = 0; z < w; z++) {
					visit[1][u][z] = 0;
				}
			}*/
			memset(visit[1], 0, sizeof(visit[1]));
		}
	}
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);
	printf("%d\n", -1);
	return 0;
}