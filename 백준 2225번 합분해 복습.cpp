#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000000
int n, k;
long long int dp[201][201];

int main() {
	scanf("%d %d", &n, &k);

	for (int j = 0; j <= n; j++) {
		dp[1][j] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i - 1][l];
				//dp[i][j] %= mod;
			}
			dp[i][j] %= mod;
		}
	}

	printf("%lld\n", dp[k][n]);
	return 0;
}