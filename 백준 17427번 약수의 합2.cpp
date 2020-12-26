#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
		
	int test;
	int n;
	vector<long long> g(MAX+1);

	for (int i = 1; i <= MAX; i++) {
		g[i] = 0;
		for (int j = 1; j <= i; j++) {
			g[i] += ((long long)(i / j) * (long long)j);
		}
	}

	cin >> test;

	while (test--) {
		cin >> n;

		cout << g[n] << '\n';
	}
	return 0;
}