#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000


int n;
long long a[MAX];

long long solve(int left, int right) {
	if (left == right) return a[left];

	int mid = (left + right) / 2;

	long long res = max(solve(left, mid), solve(mid+1, right));

	int low = mid;
	int high = mid + 1;
	long long height = min(a[low], a[high]);

	res = max(res, (2) * height);
	

	while (left < low || high < right) {
		if (high < right && (low == left || a[low-1] < a[high+1])) {
			high++;
			height = min(height, a[high]);
		}
		else {
			low--;
			height = min(height, a[low]);
		}

		res = max(res, (high - low + 1) * height);
	}

	return res;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << solve(0, n-1) << '\n';

	return 0;
}