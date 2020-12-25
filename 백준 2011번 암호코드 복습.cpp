#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define mod 1000000
int n;
long long int dp[5001][2];
int a[5001];
string s;

int main() {
	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		if (a[1] == 0) {
			printf("0\n");
			return 0;
		}
		if (i > 1 && a[i - 1] == 0 && a[i] == 0) {
			printf("0\n");
			return 0;
		}
	}

	dp[1][0] = 1;
	dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] != 0) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][0] %= mod;
		}

		int t = a[i - 1] * 10 + a[i];
		//printf("%d %d %d ", a[i-1]-'0', a[i]-'0', t);
		if (10 <= t && t <= 26) {
			dp[i][1] += dp[i - 1][0];
			dp[i][1] %= mod;
		}
		//printf("i=%d  %d %d %d\n",i, dp[i][0], dp[i][1], t);
	}
	//puts("");
	

	printf("%lld\n", (dp[n][0] + dp[n][1])%mod);
	return 0;
}