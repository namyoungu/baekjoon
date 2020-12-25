#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		if(dp[i] < dp[i-2] + arr[i]) {
			dp[i] = dp[i - 2] + arr[i];
		}
		if (dp[i] < dp[i - 3] + arr[i-1] + arr[i]) {
			dp[i] = dp[i - 3] + arr[i-1] + arr[i];
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}