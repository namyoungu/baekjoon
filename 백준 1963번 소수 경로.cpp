#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;

#define MAX 10000

struct point {
	string num;
	int cnt;
};

int n;
bool is_sosu[MAX+1];
int s, e;

void input() {
	cin >> s >> e;
}

void get_err() {
	memset(is_sosu, true, sizeof(is_sosu));

	for (int i = 2; i < MAX; i++) {
		if (is_sosu[i] == false) continue;
		
		for (int j = i + i; j < MAX; j += i) {
			is_sosu[j] = false;
		}
	}
}

bool is_range(int k) {
	if (1000 <= k && k < MAX) return true;
	return false;
}

int bfs() {
	queue<point> q;
	bool visit[MAX]; memset(visit, false, sizeof(visit));
	string es = to_string(e);

	q.push({ to_string(s) , 0});
	visit[s] = true;

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		if (stoi(now.num) == stoi(es))return now.cnt;

		for (int i = 0; i < now.num.length(); i++) {
			for (int j = 0; j < 10; j++) {
				string num = now.num;
				int cnt = now.cnt;

				//num cal
				num[i] = '0'+j;
				//cout << num[i] << ' ';

				if (!is_range(stoi(num))) continue;
				if (visit[stoi(num)]) continue;
				if (!is_sosu[stoi(num)]) continue;

				q.push({ num, cnt + 1 });
				visit[stoi(num)] = true;
			}

			
		}
	}

	return -1;
}

void solve() {
	get_err();

	cin >> n;
	for (int i = 0; i < n; i++) {
		input();
		int res = bfs();
		if (res == -1) cout << "Impossible" << '\n';
		else cout << res << '\n';
	}
}


int main() {
	solve();
	return 0;
}