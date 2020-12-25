#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[31];

int main() {
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 2; j * 2 <= i; j++) {
			if (j*2 <= i) {
				dp[i] += dp[i - j * 2] * 2;
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
