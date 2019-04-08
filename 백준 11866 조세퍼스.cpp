#define _CRT_NO_SECURE_WARNING
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, k, p=-1;
	int arr[1000];

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		arr[i] = i+1;
	}

	int c = 0;
	printf("<");
	for (int i = 0; i < n; i++) {
		while (1) {
			if (c < n && arr[i] == 0) {
				p++;
				c++;
				continue;
			}
			break;
		}
		c = 0;
		p += k;
		while (1) {
			if (p > n - 1) {
				p -= n;
				continue;
			}
			break;
		}
		printf("%d", arr[p]);
		arr[p] = 0;
		if (i != n - 1) printf(", ");
	}
	printf(">");
		



	return 0;
}