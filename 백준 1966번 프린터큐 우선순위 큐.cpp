#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct info {
	int imp, idx;
};

int tc, n, m;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		queue<info> q;
		priority_queue <int> pq;
		int res = 0;

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int u;
			scanf("%d", &u);
			q.push({ u, i });
			pq.push(u);
		}

		while (!q.empty()) {
			info t = q.front();
			q.pop();

			if (t.imp == pq.top()) {
				res++;

				if (t.idx == m) {
					printf("%d\n", res);
					break;
				}
				pq.pop();
			}
			else q.push(t);
		}
	}
	return 0;
}