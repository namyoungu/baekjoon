#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[301], dp[301], result;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i<= n; i++) {
		dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
	}

	printf("%d\n", dp[n]);
	return 0;
}