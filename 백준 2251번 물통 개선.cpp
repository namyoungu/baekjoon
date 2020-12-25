#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int a, b, c;
};

int A, B, C;
int visit[201][201][201];

priority_queue<int, vector<int>, greater<int>> pq;

void bfs() {
	queue<point> q;
	q.push({0, 0, C});

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		int a = t.a;
		int b = t.b;
		int c = t.c;

		if (visit[a][b][c] == 1) continue;
		visit[a][b][c] = 1;

		if (a == 0) pq.push(c);

		//from a
		//to b
		if (a + b <= B) {
			q.push({ 0, b + a, c });
		}
		else {
			q.push({ a - (B - b), B, c });
		}

		//to c
		if (a + c <= C) {
			q.push({0, b, a + c});
		}
		else {
			q.push({a - (C - c), b, C});
		}

		//from b
		//to a
		if (b + a <= A) {
			q.push({b + a, 0, c});
		}
		else {
			q.push({A, b - (A - a), c});
		}

		//to c
		if (b + c <= C) {
			q.push({ a, 0, b + c });
		}
		else {
			q.push({ a, b - (C - c) , C });
		}

		//from C
		//to a
		if (a + c <= A) {
			q.push({a + c, b, 0});
		}
		else {
			q.push({ A, b, c - (A - a)});
		}

		//to b
		if (b + c <= B) {
			q.push({a, b + c, 0});
		}
		else {
			q.push({a, B, c - (B - b)});
		}
	}

}


int main() {
	cin >> A >> B >> C;

	bfs();

	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}