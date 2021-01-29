#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 50

int n, k;
bool visit[27];
int res;
string S[MAX+1];

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
}

int check_same() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int len = S[i].length();

		bool suc = true;
		for (int j = 0; j < len; j++) {
			int idx = S[i][j] - 'a';
			if (!visit[idx]) {
				suc = false;
				break;
			}
		}
		if (suc) cnt++;
	}
	return cnt;
}

void dfs(int dep, int start) {
	if (dep == k) {
		res = max(res, check_same());
		return;
	}

	for (int i = start; i < 26; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(dep+1, i+1);
		visit[i] = false;
	}
}

void setting() {
	string s;
	s.push_back('a'); s.push_back('n'); s.push_back('t'); s.push_back('i'); s.push_back('c');

	for (int i = 0; i < s.length(); i++) {
		visit[s[i]-'a'] = true;
	}
}

void solve() {
	input();

	if (k == 26) {
		res = n;
	}
	else if (k < 5) {
		res = 0;
	}
	else {
		setting();
		dfs(5, 0);
	}

	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}