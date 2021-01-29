#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

#define MAX 100000

string A, B;
int a[MAX + 1], b[MAX + 1];

int main() {
	cin >> A >> B;
	int len = A.length();
	for (int i = 0; i < len; i++) {
		a[i] = A[i] - '0';
		b[i] = B[i] - '0';
	}

	for (int i = 0; i < len; i++) {
		int t = a[i] & b[i];
		cout << t;
	}
	cout << '\n';
	
	for (int i = 0; i < len; i++) {
		int t = a[i] | b[i];
		cout << t;
	}
	cout << '\n';

	for (int i = 0; i < len; i++) {
		int t = a[i] ^ b[i];
		cout << t;
	}
	cout << '\n';

	for (int i = 0; i < len; i++) {
		int t = !a[i];
		cout << t;
	}
	cout << '\n';

	for (int i = 0; i < len; i++) {
		int t = !b[i];
		cout << t;
	}

	return 0;
}