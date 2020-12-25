#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n;
	while (cin >> n) {
		int cnt = 1;
		long long one_num = 1;
		while (1) {
			if (one_num % n == 0) {
				cout << cnt << '\n';
				break;
			}
			one_num %= n;
			one_num = (one_num * 10) + 1;
			cnt++;
		}
	}
	return 0;
}