#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int a[10], b[1000];

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		a[i] %= 42;
		b[a[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < 1000; i++) {
		if (b[i] != 0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}