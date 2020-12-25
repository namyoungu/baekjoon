#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[12], tc;

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d", &n);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}