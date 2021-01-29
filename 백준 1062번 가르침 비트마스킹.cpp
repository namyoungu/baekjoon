#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k, res;
int learn, word[50];

void input() {
	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('c' - 'a');

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int len = str.length();
		for (int j = 0; j < len; j++) {
			word[i] |= (1 << (str[j]-'a'));
		}
	}
}

void dfs(int dep, int start)
{
	if (dep == k) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((word[i] & learn) == word[i]) {
				cnt++;
			}
		}
		res = max(res, cnt);
	}
	
	for (int i = start; i < 26; i++) {
		if ((learn & (1 << i)) == 0) {
			learn |= (1 << i);
			dfs(dep + 1, i + 1);
			learn &= ~(1 << i);
		}
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
		dfs(5, 0);
	}

	cout << res << '\n';
}

int main(void)
{
	solve();
	return 0;
}