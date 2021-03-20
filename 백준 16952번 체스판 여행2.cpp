#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 10 + 1

struct point {
	int y, x;
	int kind, num;
	int time, change;
};


int n, sy, sx;
int map[MAX][MAX];
pair<int, int> visited[MAX][MAX][150][3];
int dy[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int kDir[4][2] = { {7, 4}, {4, 5}, {6, 5}, {6, 7} };
int resTime = 987654321, resChange = 987654321;
pair<int, int> ans(-1, -1);

bool isRange(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return false;
	return true;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				sy = i;
				sx = j;
			}
		}
	}
}

void init() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < 150; k++)
				for (int l = 0; l < 3; l++)
					visited[i][j][k][l] = make_pair(-1, -1);
}

pair<int, int> bfs() {
	queue<point> q;

	for (int i = 0; i < 3; i++) {
		q.push({ sy, sx, i, 1, 0, 0 });
		visited[sy][sx][1][i] = make_pair(0, 0);
	}

	while (!q.empty()) {
		point t = q.front();
		q.pop();
		auto& p = visited[t.y][t.x][t.num][t.kind];

		/*
		cout << t.y << ' ';
		cout << t.x << ' ';
		cout << t.kind << ' ';
		cout << t.next << ' ';
		cout << t.time << ' ';
		cout << t.change << '\n';
		*/

		//cout << t.num << '\n';
		if (t.num == n * n) {
			//cout << ans.first << ' ' << ans.second << '\n';
			//cout << p.first << ' ' << p.second << '\n';
			if (ans.first == -1 || ans > p) {
				ans = p;
				//cout << p.first << ' ' << p.second << '\n';
			}
		}

		//move
		switch (t.kind) {
		case 0://나이트
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 2; j++) {
					int ty = t.y + dy[i] + dy[kDir[i][j]];
					int tx = t.x + dx[i] + dx[kDir[i][j]];
					int kind = t.kind;
					int num = t.num;
					int time = t.time + 1;
					int change = t.change;

					if (!isRange(ty, tx)) continue;
					if (map[ty][tx] == num + 1) {
						num++;
					}
					auto np = make_pair(p.first + 1, p.second);
					if ((visited[ty][tx][num][kind]).first == -1 ||
						(visited[ty][tx][num][kind] > np)) {

						visited[ty][tx][num][kind] = np;
						q.push({ ty, tx, kind, num, time, change });						
					}

					/*
					cout << "-----" << '\n';
					cout << t.y << ' ' << t.x << '\n';
					cout << ty << ' ' << tx << '\n';
					cout << "-----" << '\n';
					*/

					
				}
			}
			break;

		case 1://비숍
			for (int i = 4; i < 8; i++) {
				int ty = t.y;
				int tx = t.x;

				while (1) {
					ty += dy[i];
					tx += dx[i];
					int kind = t.kind;
					int num = t.num;
					int time = t.time + 1;
					int change = t.change;

					if (!isRange(ty, tx)) break;
					if (map[ty][tx] == num + 1) {
						num++;
					}
					auto np = make_pair(p.first + 1, p.second);
					if ((visited[ty][tx][num][kind]).first == -1 ||
						(visited[ty][tx][num][kind] > np)) {

						visited[ty][tx][num][kind] = np;
						q.push({ ty, tx, kind, num, time, change });
					}
				}
			}
			break;

		case 2://록
			for (int i = 0; i < 4; i++) {
				int ty = t.y;
				int tx = t.x;

				while (1) {
					ty += dy[i];
					tx += dx[i];
					int kind = t.kind;
					int num = t.num;
					int time = t.time + 1;
					int change = t.change;

					if (!isRange(ty, tx)) break;
					if (map[ty][tx] == num + 1) {
						num++;
					}
					auto np = make_pair(p.first + 1, p.second);
					if ((visited[ty][tx][num][kind]).first == -1 ||
						(visited[ty][tx][num][kind] > np)) {

						visited[ty][tx][num][kind] = np;
						q.push({ ty, tx, kind, num, time, change });
					}
				}
			}
			break;
		}

		//changeKind
		for (int k = 0; k < 3; k++) {
			int ty = t.y;
			int tx = t.x;
			int kind = t.kind;
			int num = t.num;
			int time = t.time + 1;
			int change = t.change;

			if (k == kind) continue;
			kind = k;
			change++;

			auto np = make_pair(p.first + 1, p.second + 1);
			if ((visited[ty][tx][num][kind]).first == -1 ||
				(visited[ty][tx][num][kind] > np)) {

				visited[ty][tx][num][kind] = np;
				q.push({ ty, tx, kind, num, time, change });
			}
		}

	}
	return ans;
}

int main() {
	init();
	input();
	auto ans = bfs();
	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}