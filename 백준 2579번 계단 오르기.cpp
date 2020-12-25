#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10001], dp[3][10001], result;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dp[0][1] = 0;
	dp[1][1] = a[1];
	dp[2][1] = a[1];

	for (int i = 1; i <= n; i++) {
		dp[0][i] = max(dp[1][i-1], dp[2][i - 1]);
		dp[1][i] = dp[0][i - 1] + a[i];
		dp[2][i] = max(dp[1][i - 1], dp[0][i - 1]) + a[i];
	}
	result = max(dp[1][n], dp[2][n]);
	printf("%d\n", result);
	return 0;
}