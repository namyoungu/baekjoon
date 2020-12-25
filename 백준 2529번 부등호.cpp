#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

string s;

vector <int>v;
vector<int> v_m;
vector<int> v_M;

int k, n;
int visit[10];
long long int m = 10000000000, M = -1;

void make_num() {
	long long int num = 0;

	long long int t = 1;
	for (int i = n-1; i >= 0; i--) {
		num += (v[i] * t);
		t *= 10;
	}

	if (m > num) {
		m = num;
		v_m.clear();
		for (int i = 0; i < n; i++) {
			v_m.push_back(v[i]);
		}
	}
	if (M < num) {
		M = num;
		v_M.clear();
		for (int i = 0; i < n; i++) {
			v_M.push_back(v[i]);
		}
	}
	return;
}

void dfs(int dep = 0) {
	if (dep == k) {
		make_num();
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visit[i] == 1) continue;

		if (s[dep] - '<' == 0) {
			if (v[dep] < i) {
				v.push_back(i);
				visit[i] = 1;

				dfs(dep+1);

				v.pop_back();
				visit[i] = 0;
			}
		}
		else {
			if (v[dep] > i) {
				v.push_back(i);
				visit[i] = 1;

				dfs(dep + 1);

				v.pop_back();
				visit[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &k);
	n = k + 1;

	char c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		s += c;
	}

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		visit[i] = 1;

		dfs();

		v.clear();
		for (int j = 0; j < 10; j++) {
			visit[i] = 0;
		}
	}
	
	for (int i = 0; i < v_M.size(); i++) {
		printf("%d", v_M[i]);
	}
	puts("");
	for (int i = 0; i < v_m.size(); i++) {
		printf("%d", v_m[i]);
	}

	return 0;
}