#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int p[1000000];
int pn;
bool c[1000001];

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 2; i <= n; i++) {
		if (c[i] == false) {
			p[pn++] = i;

			for (int j = i * 2; j <= n; j += i) {
				c[j] = true;
			}
		}
	}

	for (int i = 0; i < pn; i++) {
		if (p[i] >= m) {
			printf("%d\n", p[i]);
		}
	}

	return 0;
}