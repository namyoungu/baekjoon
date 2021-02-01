#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int m;
int a[20];
int k=0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m;

	while (m--) {
		string str;
		int x;
		cin >> str;

		if (str == "add") {
			cin >> x;

			k |= (1 << x);
		}
		else if (str == "remove") {
			cin >> x;

			k &= ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;

			if (k & (1 << x)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			cin >> x;

			k ^= (1 << x);
		}
		else if (str == "all") {
			k = (1 << 21) - 1;
		}
		else if (str == "empty") {
			k = 0;
		}
	}
	
	return 0;
}