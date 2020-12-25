#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100001], dp[100001], result;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	result = a[1];
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = a[i];
		if (dp[i-1] > 0) {
			dp[i] = a[i] + dp[i - 1];
		}
		result = max(result, dp[i]);
	}

	printf("%d\n", result);
	return 0;
}