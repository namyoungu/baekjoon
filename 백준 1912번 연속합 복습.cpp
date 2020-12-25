#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[100001], a[100001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = a[i];

		if (dp[i - 1] > 0) {
			dp[i] += dp[i - 1];
		}
	}
	int result = -1001;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i]);
		//printf("%d ", dp[i]);
	}
	//puts("");
	printf("%d\n", result);
	return 0;
}