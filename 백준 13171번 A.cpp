#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define M 1000000007

long long A, X;
long long Ax[65];


//Ax[n] = A^(2^n)
long long retAx(long long x) {
	if (Ax[x] != 0) return Ax[x];
	if (x == 0) return A;

	return Ax[x] = (retAx(x - 1) * retAx(x - 1)) % M;
}

int main() {
	cin >> A;
	cin >> X;
	A %= M;

	long long tX = X;
	long long res = 1;
	int dep = 0;
	while (tX != 0) {
		if (tX % 2) {
			res *= retAx(dep);
			res %= M;
		}
		tX /= 2;
		dep++;
	}
	cout << res << '\n';

	return 0;
}