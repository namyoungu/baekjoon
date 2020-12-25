#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int p[1000000];
int pn;
bool c[1000001];
int n;

void prime() {
	for (int i = 2; i <= 1000000; i++) {
		if (c[i] == false) {
			p[pn++] = i;

			for (int j = i * 2; j <= 1000000; j += i) {
				c[j] = true;
			}
		}
	}
	return;
}

int main() {
	prime();

	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;

		int a, b;
		bool suc = false;
		for (int i = 0; i < pn; i++) {
			if (p[i] > n / 2) continue;
			a = p[i];
			if (c[n - a] == false) {
				b = n - a;
				printf("%d = %d + %d\n", n, a, b);
				suc = true;
				break;
			}
		}
		if (!suc) printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}