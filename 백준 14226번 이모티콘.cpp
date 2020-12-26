#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 1000+1

struct point {
	int display;
	int clip;
	int cnt;
};

queue<point> q;
int s;
bool visit[MAX][MAX];


int bfs() {
	memset(visit, false, sizeof(visit));

	q.push({ 1, 0, 0});
	visit[1][0] = true;

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		if (now.display == s) {
			return now.cnt;
		}

		//연산 1
		if (now.display > 0 && now.display < MAX) {
			point next = now;
			next.clip = now.display;
			next.cnt = now.cnt + 1;

			if (!visit[next.display][next.clip]) {
				q.push(next);
				visit[next.display][next.clip] = true;
			}
		}

		//연산 2
		if (now.clip > 0 && now.display + now.clip < MAX) {
			point next = now;
			next.display = now.display + now.clip;
			next.cnt = now.cnt + 1;

			if (!visit[next.display][next.clip]) {
				q.push(next);
				visit[next.display][next.clip] = true;
			}
		}

		//연산 3
		if (now.display > 0) {
			point next = now;
			next.display = now.display-1;
			next.cnt = now.cnt + 1;

			if (!visit[next.display][next.clip]) {
				q.push(next);
				visit[next.display][next.clip] = true;
			}
		}
	}

	return 2;
}

void solve() {
	int res = bfs();
	cout << res << '\n';
}

int main() {
	cin >> s;

	solve();

	return 0;
}