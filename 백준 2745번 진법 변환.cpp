#define _CRT_SECURE_NO_WARNIGNS
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int b;
string n;

int main() {
	cin >> n;
	int len = n.length();
	scanf("%d", &b);

	long long int sum = 0;
	for (int i = 0; i < len; i++) {
		int t;
		if (n[i] >= 'A') {
			t = n[i] - 'A' + 10;
		}
		else {
			t = n[i] - '0';
		}
		//sum += t * pow(b, len-1-i);
		sum = sum * b + t;
	}
	printf("%lld\n", sum);
	return 0;
}