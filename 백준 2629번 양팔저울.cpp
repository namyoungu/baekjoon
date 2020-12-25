#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 30;

int n, m;
int ball[7], weight[MAX];
bool cache[MAX + 1][MAX * 500 + 1];

void dfs(int cnt, int sum) {
	if (cnt > n) return;

	bool &res = cache[cnt][sum];
	if (res) return;
	res = true;

	dfs(cnt + 1, sum + weight[cnt]);
	dfs(cnt + 1, sum);
	dfs(cnt + 1, abs(sum - weight[cnt]));

	return;
}

int main() {
	memset(cache, false, sizeof(cache));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ball[i];
	}

	dfs(0, 0);

	for (int i = 0; i < m; i++) {
		if (ball[i] > MAX * 500) cout << "N ";
		else if (cache[n][ball[i]]) cout << "Y ";
		else cout << "N ";
	}
	puts("");

	return 0;
}