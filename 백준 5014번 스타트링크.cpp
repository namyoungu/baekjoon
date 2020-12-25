#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define max 1000000
int F, S, G, U, D;
bool visit[max + 1];

queue<int> q;

int bfs() {
	q.push(S);
	visit[S] = true;

	int cnt = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int now = q.front();
			q.pop();

			if (!(1 <= now && now <= F)) continue;

			if (now == G) {
				return cnt;
			}

			int u = now + U;
			int d = now - D;

			if (u <= max) {
				if (!visit[u]) {
					visit[u] = true;
					q.push(u);
				}
			}
			if (1 <= d) {
				if (!visit[d]) {
					visit[d] = true;
					q.push(d);
				}
			}
		}
		cnt++;
	}

	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;

	int ans = bfs();
	if (ans == -1) cout << "use the stairs" << '\n';
	else cout << ans << '\n';

	return 0;
}