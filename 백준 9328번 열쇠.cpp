#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define MAX  1005

struct point {
	int y, x;
};

int test;
int n, m, res;
char map[MAX][MAX];
bool visit[MAX][MAX];
string key;
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

bool isRange(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	return true;
}

void initKey() {
	key = "";
}

void initVisit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
		}
	}
}

vector<point> setStartPoint() {
	vector<point> start;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				if (map[i][j] == '.') {
					start.push_back({ i, j });
				}
			}
		}
	}

	return start;
}

void input() {
	cin >> n >> m;
	n += 2;
	m += 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				map[i][j] = '.';
				continue;
			}
			scanf(" %c", &map[i][j]);
		}
	}
	cin >> key;
	
	if (key == "0") {
		key = "";
	}
}

void openDoor() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c = map[i][j];
			if (0 <= c - 'A' && c - 'Z' <= 0) {
				if (key.find(c) > -1) {
					map[i][j] = '.';
				}
			}
		}
	}
}

bool isGetKey() {
	res = 0;
	bool isGetKey = false;
	queue<point> q;
	initVisit();

	q.push({ 0, 0 });
	visit[0][0];

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = t.y + dy[i];
			int tx = t.x + dx[i];

			if (!isRange(ty, tx)) continue;
			if (visit[ty][tx]) continue;
			char c = map[ty][tx];
			if (c == '*') continue;
			if (0 <= c - 'a' && c - 'z' <= 0) {
				key.push_back(c);
				isGetKey = true;
				map[ty][tx] = '.';
			}
			if (0 <= c - 'A' && c - 'Z' <= 0) {
				char k = tolower(c);
				if (key.find(k) == -1)	continue;
				map[ty][tx] = '.';
			}
			if (map[ty][tx] == '$') res++;

			q.push({ty, tx});
			visit[ty][tx] = true;
		}
	}

	return isGetKey;
}

int main() {
	cin >> test;

	while (test--) {
		initKey();
		input();
		openDoor();

		while (1) {
			//print_map();
			if (!isGetKey()) break;
		}

		cout << res << '\n';
	}

	
	return 0;
}