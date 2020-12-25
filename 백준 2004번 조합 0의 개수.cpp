#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long int f[16];
int a, b, c;

void make() {
	f[1] = 5;
	for (int i = 2; i <= 13; i++) {
		f[i] = f[i - 1] * 5;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);

	make();

	

	return 0;
}