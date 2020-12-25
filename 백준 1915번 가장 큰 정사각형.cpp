#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int w, h;
int dp[1001][1001];
int map[1001][1001];
int result;

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}
	printf("%d\n", result*result);
	return 0;
}