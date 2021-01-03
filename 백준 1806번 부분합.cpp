#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int n, s;
int list[100001];
int max_num = 0;
int sum_num = 0;

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		max_num = max(max_num, list[i]);
		sum_num += list[i];
	}
}

int cal() {
	int start = 0, end = 0, sum = list[0], res = 987654321;

	while (start <= end && end < n) {
		if (sum < s) {
			end++;
			sum += list[end];
		}
		else if (sum == s) {
			res = min(res, end - start + 1);
			end++;
			sum += list[end];
		}
		else if (sum > s) {
			res = min(res, end - start + 1);
			sum -= list[start];
			start++;
		}
	}
	return res;
}

void solve() {
	input();
	int res = cal();
	if (res == 987654321) cout << 0 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}