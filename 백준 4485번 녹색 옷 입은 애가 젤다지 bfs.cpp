#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

struct point {
	int y, x, val;
};

int n, map[126][126];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

struct cmp {
	bool operator()(point a, point b) {
		return a.val > b.val;
	}
};

int bfs() {
	priority_queue<point, vector<point>, cmp> q;
	bool visit[125][125] = {false, };

	q.push({0, 0, map[0][0]});

	while (!q.empty()) {
		point t = q.top();
		q.pop();

		if (t.y == n - 1 && t.x == n - 1) {
			return t.val;
		}

		visit[t.y][t.x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = t.y + dy[i];
			int nx = t.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visit[ny][nx]) continue;

			int nval = t.val + map[ny][nx];
			q.push({ ny, nx, nval });
		}
	}
	
}

int main() {
	int z = 0;
	while (1) {
		z++;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		cout << "Problem "; cout << z; cout << ": ";
		cout << bfs() << '\n';

	}


	return 0;
}