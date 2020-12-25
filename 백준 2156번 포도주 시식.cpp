#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[3][10001];
int arr[10001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
		dp[1][i] = dp[0][i-1] + arr[i];
		dp[2][i] = dp[1][i-1] + arr[i];
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(dp[0][i], max(dp[1][i], dp[2][i]));
	}
	printf("%d\n", result);
	return 0;
}