#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int w, h, cnt, res;
char map[20][20];
int visit[20][20];
int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };

vector<char>v;

bool check(char t) {
	for (int i = 0; i < v.size(); i++) {
		if (t == v[i]) return false;
	}
	return true;
}

void dfs(int y, int x) {
	/*if (cnt == 2) {
		for (int i = 0; i < v.size(); i++) {
			printf("%c ", v[i]);
		}
		puts("");
	}*/
	res = max(res, cnt);
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		if (ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
		if (visit[ty][tx] == 0) {
			if (!check(map[ty][tx])) continue;
			visit[ty][tx] = 1;
			cnt++;
			v.push_back(map[ty][tx]);
			dfs(ty, tx);
			v.pop_back();
			cnt--;
			visit[ty][tx] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", map[i]);
	}
	visit[0][0] = 1;
	v.push_back(map[0][0]);
	cnt++;
	dfs(0, 0);
	printf("%d\n", res);
	return 0;
}
