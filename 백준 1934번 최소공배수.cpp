#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int tc, a, b;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d", &a, &b);
		int g = gcd(a, b);
		long long int l = a * b / g;
		printf("%lld\n", l);
	}

	return 0;
}