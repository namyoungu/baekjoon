#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001];

int main() {
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	printf("%d\n", dp[n]);
	return 0;
}