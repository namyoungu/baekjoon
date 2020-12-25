#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[31];

int main() {
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 2; j <= i; j++) {
			if (i - j * 2 < 0) continue;
			dp[i] += 2 * dp[i - j * 2];
		}
	}
	//int result = dp[0][n] + dp[1][n];
	printf("%d\n", dp[n]);
	return 0;
}