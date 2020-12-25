#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	int list[51];

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> list[i];
	}
	sort(list, list+cnt);

	cout << list[0] * list[cnt - 1] << '\n';

	return 0;
}