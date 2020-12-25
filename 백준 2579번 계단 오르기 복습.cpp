#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[301][3], a[10001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[1][0] = 0;
	dp[1][1] = a[1];
	dp[1][2] = a[1];
	for (int i = 1; i <= n-1; i++) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = dp[i-1][0] + a[i];
		dp[i][2] = dp[i-1][1] + a[i];
	}
	printf("%d\n", max(dp[n-1][1], dp[n-1][0])+a[n]);
	return 0;
}