#define _CRT_SECURE_NO_WARNIGNS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int tc, cnt, n, len;
int s[7], num[7], visit[7];
char tnum[8];

vector<int>v;
set<int>ss;

int make_num(int l) {
	int t = 0;
	for (int i = 0; i < l; i++) {
		t += pow(10, l - 1 - i) * s[i];
	}
	return t;
}

void check(int dep){
	int l = dep + 1;

	if (l > 1) {
		if (s[dep] % 2 == 0) return;
	}

	int t = make_num(l);

	if (ss.find(t) != ss.end()) return;
	if (t == 0 || t == 1) return;

	for (int i = 2; i*i <= t; i++) {
		if (t%i == 0) return;
	}
	
	ss.insert(t);
	return;
}

void dfs(int dep = 0) {
	if (dep == len) {
		return;
	}
	for (int i = 0; i < len; i++) {
		if (visit[i] == 1) continue;
		visit[i] = 1;
		s[dep] = num[i];
		check(dep);
		dfs(dep+1);
		visit[i] = 0;
	}
}

void counting() {
	cnt = ss.size();

	ss.clear();
	memset(visit, 0, sizeof(visit));
	return;
}

int main(void) {
	cin >> tc;
	for (int T = 0; T < tc; T++) {
		cin >> tnum;

		len = strlen(tnum);
		for (int i = 0; i < len; i++) {
			num[i] = tnum[i] - '0';
		}

		dfs();
		counting();
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}