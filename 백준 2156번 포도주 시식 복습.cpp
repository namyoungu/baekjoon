#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[10001], a[10001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + a[i - 1]) + a[i]);
	}

	printf("%d\n", dp[n]);
	return 0;
}