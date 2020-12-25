#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, cnt;

bool prime() {
	if (k < 2) return false;

	for (int i = 2; i*i <= k; i++) {
		if (k%i == 0) return false;
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (prime()) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}