#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000000;
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long int dp[201][201], result;

int main() {
	scanf("%d %d", &n, &k);

	/*for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}*/
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i-1][j-l];
				dp[i][j] %= mod;
			}
		}
	}

	printf("%lld\n", dp[k][n]);
	return 0;
}