#include <iostream>
#include <algorithm>
using namespace std;

long long ret(int a, int b, int c) {
	if (b == 0)
		return 1;

	long long half = ret(a, b / 2, c);

	if (b % 2 == 0) {
		return (half * half) % c;
	}
	else {
		return ((half * half) % c * a) % c;
	}
}

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	
	cout << ret(a % c, b, c) << '\n';

	return 0;
}