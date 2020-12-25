#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define mod 1000000;
string s;
long long int dp[5001];
int len, a[5001];

int main() {
	cin >> s;
	len = s.length();
	for (int i = 1; i <= len; i++) {
		a[i] = s[i-1] - '0';
		/*if (i > 1 && a[i] == 0 && a[i - 1] == 0) {
			printf("0\n");
			exit(0);
		}
		if (i > 1 && a[i] == 0) {
			if (3 <= a[i - 1] && a[i-1]<= 9) {
				printf("0\n");
				exit(0);
			}
		}*/
	}
	if (a[1] == 0) {
		printf("0\n");
		exit(0);
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (a[i] != 0) {
			dp[i] = (dp[i - 1] + dp[i]) % mod;
		}
		//if (i == 1) continue;
		if (a[i - 1] == 0) continue;
		int x = a[i - 1] * 10 + a[i];
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % mod;
		}
	}
	/*for (int i = 1; i <= len; i++) {
		printf("%lld ", dp[i]);
	}*/
	printf("%lld\n", dp[len]);
	return 0;
}