#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <memory.h>
using namespace std;

struct point {
	int y, x;
};

int n, m, h;
int map[100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int cluster_visit[100][100], fly_visit[100][100];
int down_cnt=INT_MAX;
bool crush;
int total;

queue<point>q;
queue<point>fly_q;
vector <point>v;
queue<int>w;

void print() {
	//puts("");
	for (int i = 0; i < n; i++) {
		printf("%d ", n - i);
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}
}

void INIT() {
	memset(cluster_visit, 0, sizeof(cluster_visit));
	memset(fly_visit, 0, sizeof(fly_visit));
	v.clear();
}

void left(int y, int x) {
	if (!(0 <= x && x < m)) return;
	if (map[y][x] == 1) {
		crush = true;
		map[y][x] = 0;
		return;
	}
	left(y, x + 1);
}

void right(int y, int x) {
	if (!(0 <= x && x < m)) return;
	if (map[y][x] == 1) {
		crush = true;
		map[y][x] = 0;
		return;
	}
	right(y, x - 1);
}

//void fly_cluster(int y, int x) {
//	fly_q.push({y, x});
//	fly_visit[y][x]++;
//	v.push_back({y, x});
//
//	while (!fly_q.empty()) {
//		point t = fly_q.front();
//		fly_q.pop();
//		
//		for (int i = 0; i < 4; i++) {
//			int ty = t.y + dy[i];
//			int tx = t.x + dx[i];
//
//			if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
//			if (map[ty][tx] == 1 && cluster_visit[ty][tx] == 0 && fly_visit[ty][tx] == 0) {
//				fly_q.push({ty, tx});
//				fly_visit[ty][tx] = 1;
//				v.push_back({ ty, tx });
//			}
//		}
//	}
//}

int dfs(int y, int x, int cnt) {
	if (y >= n) return cnt-1;
	if (map[y][x] == 1) {
		if (fly_visit[y][x] == 1) {
			return INT_MAX;
		}
		else {
			return cnt-1;
		}
	}
	return dfs(y + 1, x, cnt+1);
}

int cal_min() {
	int m = INT_MAX;
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].y;
		int x = v[i].x;

		int k = dfs(y+1, x, 1);
		//printf("%d  %d %d\n", k, y, x);
		m = min(m, k);
	}
	return m;
}

void down(int k) {
	//printf("%d\n", k);
	for (int i = 0; i < v.size(); i++) {
		map[v[i].y][v[i].x] = 0;
	}
	for (int i = 0; i < v.size(); i++) {
		map[v[i].y+k][v[i].x] = 1;
	}
}

void gravity() {
	int k = cal_min();
	
	down(k);
}

void clustering(int y, int x, int &cnt) {
	queue<point>cluster_q;
	cluster_q.push({ y, x });
	cluster_visit[y][x] = 1;

	while (!cluster_q.empty()) {
		point t = cluster_q.front();
		cluster_q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
			if (cluster_visit[ty][tx] == 1 || map[ty][tx] == 0) continue;
			cluster_q.push({ ty, tx });
			cluster_visit[ty][tx] = 1;
			//cnt++;
		}
	}
}

bool is_fly() {
	int cnt = 0;
	bool fly;
	for (int j = 0; j < m; j++) {
		if (map[n-1][j] == 1 && cluster_visit[n-1][j] == 0) {
			clustering(n-1, j, cnt);
		}
	}

	bool yes = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && cluster_visit[i][j] == 0) {
				v.push_back({ i, j });
				fly_visit[i][j] = 1;
				yes = true;
			}
		}
	}
	//printf("sz=%d\n", v.size());

	return yes;
}

void simul() {
	int seq = 0;
	while (!w.empty()) {
		int z = w.front();
		w.pop();
		if (seq % 2 == 0) {
			left(z, 0);
		}
		else {
			right(z, m-1);
		}
		if (crush) {
			//printf("hit\n");
			//print();

			total--;
			if (is_fly()) {
				gravity();
			}
			crush = false;

			//printf("g\n");
			//print();
			//printf("g end\n");
		}
		INIT();
		seq++;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			scanf(" %c", &t);
			if (t == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
				total++;
			}
		}
	}
	scanf("%d", &h);
	for (int i = 0; i < h; i++) {
		int t;
		scanf("%d", &t);
		w.push(n-t);
	}

	/*puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	puts("");*/

	simul();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				printf(".");
			}
			else {
				printf("x");
			}
		}
		puts("");
	}

	/*puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}*/

	return 0;
}