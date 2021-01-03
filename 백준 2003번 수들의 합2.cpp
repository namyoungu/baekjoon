#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int n;
long long m;
int arr[MAX+1];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int start = 0;
	int end = 0;
	long long sum = arr[0];
	int res = 0;

	while (start<=end && end < n) {
		if (sum < m) {
			sum += arr[++end];
		}
		else if (sum == m) {
			res++;
			sum += arr[++end];
		}
		else if (sum > m) {
			sum -= arr[start++];

			if (start > end && start < n) {
				end = start;
				sum = arr[start];
			}
		}
	}

	cout << res << '\n';
}

int main() {
	input();
	solve();
	return 0;
}