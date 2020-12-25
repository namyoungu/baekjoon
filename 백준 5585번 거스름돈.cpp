#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int pay, change, cnt=0, dan[] = {500, 100, 50, 10 ,5, 1};

int main(void) {
	scanf("%d", &pay);

	change = 1000 - pay;

	for (int i = 0; i < 6; i++) {
		int k = change / dan[i];
		if (k > 0) {
			cnt += k;
			change -= dan[i]*k;
		}
	}
	
	printf("%d\n", cnt);

	return 0;
}
