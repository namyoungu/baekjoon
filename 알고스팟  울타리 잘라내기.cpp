#include <iostream>
#include <algorithm>
using  namespace std;

#define MAX 20000+1

int test;
int h[MAX];

int solve(int left, int right) {
	if (left == right) return h[left];

	int mid = (left + right) / 2;

	int res = max(solve(left, mid), solve(mid+1, right));

	int low = mid;
	int high = mid+1;
	int height = min(h[low], h[high]);

	res = max(res, 2*height);

	while (left < low || high < right) {
		if (high < right && (low == left || h[low-1] < h[high+1])) {
			high++;
			height = min(height, h[high]);
		}
		else {
			low--;
			height = min(height, h[low]);
		}

		res = max(res, height * (high - low + 1));
	}
	return res;
}

int main() {
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		cout << solve(0, n-1) << '\n';
	}

	return 0;
}