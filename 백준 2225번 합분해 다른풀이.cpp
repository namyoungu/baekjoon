#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000000;
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long int dp[2][201], result;

int main() {
	scanf("%d %d", &n, &k);


	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i%2][j] += dp[1-i%2][j - l];
				dp[i%2][j] %= mod;
			}
		}
	}
	result = dp[0][n];
	result = max(result, dp[1][n]);
	printf("%lld\n", result);
	return 0;
}