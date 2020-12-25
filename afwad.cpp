#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
//#include <set>
using namespace std;

struct point {
	int y, x;
};

struct info {
	int state, dir;
};

int n, m;
int map[1000][1000], visit[1000][1000], su[1000][1000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };


queue<point>q;
queue<point>p;

void print() {
	puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", visit[i][j]);
		}
		puts("");
	}
	puts("");

	puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d", su[i][j]);
		}
		puts("");
	}
	puts("");
}

bool cmp(const info &p1, const info &p2) {
	if (p1.state < p2.state) {
		return true;
	}
	else {
		return false;
	}
}

void bfs(int y, int x, int k) {
	int cnt = 1;
	q.push({ y, x });
	visit[y][x] = k;
	p.push({ y, x });

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
			if (visit[ty][tx] == 0) {
				if (map[ty][tx] == 0) {
					q.push({ ty, tx });
					visit[ty][tx] = k;
					p.push({ ty, tx });
					cnt++;
				}
			}

		}
	}
	while (!p.empty()) {
		point t = p.front();
		p.pop();
		su[t.y][t.x] = cnt;
	}
}

void change(int y, int x) {
	//set<int>search;
	vector<info>v;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
		if (map[ty][tx] == 0) {
			v.push_back({visit[ty][tx], i});
		}
	}
	
	if (v.size() == 0) return;

	sort(v.begin(), v.end(), cmp);
	//system("pause");
	for (int i = 0; i < v.size(); i++) {
		if (i + 1 < v.size() && v[i].state == v[i + 1].state) {
			continue;
		}
		int ty = y + dy[v[i].dir];
		int tx = x + dx[v[i].dir];
		map[y][x] += su[ty][tx];
	}
	map[y][x] %= 10;
}

int main() {
	//입력
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);

		}
	}

	//방문확인 및 0의 그룹화
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				bfs(i, j, k);
				k++;
			}
		}
	}

	//맵 카운팅 및 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				change(i, j);
			}
		}
	}
	//print();
	//puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", map[i][j]);
		}
		puts("");
	}

	return 0;
}