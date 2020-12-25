#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int tc, len, cnt;
int num[7], s[7], visit[7];
char tnum[8];

vector<int>v;

void check(int n) {
	int k=0;
	for (int i = 0; i < n; i++) {
		k += pow(10, n-1-i) * s[i];
	}

	if (k == 1 || k == 0) return;
	//printf("%d\n", k);
	for (int i = 2; i < k; i++) {
		if (k % i == 0) {
			return;
		}
	}
	v.push_back(k);
	return;
}

void dfs(int dep, int n) {
	if (dep == n) {
		//if (n>1 && s[n - 1] % 2 == 0) return;
		if (n > 1) {
			if (s[n - 1] == 5 || s[n - 1] == 9 || s[n - 1] % 2 == 0) return;
		}
		check(n);

		return;
	}
	for (int i = 0; i < len; i++) {
		if (visit[i] == 1) continue;
		visit[i] = 1;
		s[dep] = num[i];
		dfs(dep+1, n);
		visit[i] = 0;
	}
}

int main(void) {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> tnum;
		len = strlen(tnum);

		for (int j = 0; j < len; j++) {
			num[j] = tnum[j] - '0';
		}
		for (int j = 1; j <= len; j++) {
			dfs(0, j);
			memset(visit, 0, 7);
		}
		sort(v.begin(), v.end());
		/*for (int j = 0; j < v.size(); j++) {
			printf("%d ", v[j]);
		}
		puts("");*/
		for (int j = 0; j < v.size(); j++) {
			if (j > 0 && v[j - 1] != v[j]) {
				cnt++;
			}
		}
		if (cnt != 0) {
			cnt++;
		}
		v.clear();
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}