#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int g, l;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);

	g = gcd(a, b);
	l = a*b/g;

	printf("%d\n%d\n", g, l);

	return 0;
}