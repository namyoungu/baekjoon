#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct info {
	int a, b, c;
};

int A, B, C;
int ha, hb, hc;
int lim[3];
int visit[200][200][200];

set<int>res;
queue<info> q;

void bfs() {
	q.push({ 0, 0, C });
	visit[0][0][C] = 1;
	res.insert(C);

	while (!q.empty()) {
		info t = q.front();
		q.pop();

		int a = t.a, b = t.b, c = t.c;
		//cout << a << ' ' << b << ' ' << c << '\n';
		//if (visit[a][b][c] == 1) continue;

		//a가 시작
		//to b
		a = t.a, b = t.b, c = t.c;
		int gap = B - b;
		if (gap >= a) {
			b = b + a;
			a = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			b = B;
			a -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		//to c
		a = t.a, b = t.b, c = t.c;
		gap = C - c;
		if (gap >= a) {
			c = c + a;
			a = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			c = C;
			a -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}


		//b가 시작
		//to a
		a = t.a, b = t.b, c = t.c;
		gap = A - a;
		if (gap >= b) {
			a = a + b;
			b = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			a = A;
			b -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		//to c
		a = t.a, b = t.b, c = t.c;
		gap = C - c;
		if (gap >= b) {
			c = c + b;
			b = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			c = C;
			b -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}

		//c가 시작
		//to a
		a = t.a, b = t.b, c = t.c;
		gap = A - a;
		if (gap >= c) {
			a = a + c;
			c = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			a = A;
			c -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		//to b
		a = t.a, b = t.b, c = t.c;
		gap = B - b;
		if (gap >= c) {
			b = b + c;
			c = 0;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
		else {
			b = B;
			c -= gap;
			if (visit[a][b][c] == 0) {
				q.push({ a, b, c });
				visit[a][b][c] = 1;
				if (a == 0) res.insert(c);
			}
		}
	}
}



int main(void) {
	cin >> A >> B >> C;
	int have[3];
	have[0] = 0; have[1] = 0; have[2] = C;
	lim[0] = A; lim[1] = B; lim[2] = C;

	bfs();
	
	set<int>::iterator iter;
	for (iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << ' ';
	}
	puts("");

	return 0;
}