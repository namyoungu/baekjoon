#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long int dp[91];

int main() {
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i-2];
	}
	printf("%lld\n", dp[n]);
	return 0;
}