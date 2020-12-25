#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
bool e = false;
string num;

bool check(void) {
	//int len = num.length()/2;

	for (int i = 1; i <= num.length() / 2; i++) {
		string a = num.substr(num.length() - i, i);
		string b = num.substr(num.length() - i*2, i);

		if (a == b) {
			num.pop_back();
			return false;
		}
	}
	return true;
}

void dfs(int dep = 0) {
	if (dep == n) {
		printf("%s\n", num.c_str());
		e = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		num += i + '0';
		if (!check()) {
			continue;
		}
		dfs(dep+1);
		num.pop_back();
		if (e) return;
	}
}

int main(void) {
	scanf("%d", &n);

	dfs();

	return 0;
}