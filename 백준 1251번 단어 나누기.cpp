#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string start;
int n;
string res;
int cnt = 0;

void Merge(int b, int c) {
	cnt++;

	string A = start.substr(0, b);
	string B = start.substr(b, c-b);
	string C = start.substr(c, n-c);

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());

	string D = A + B + C;

	if (res > D) {
		res = D;
	}

	if (cnt % 100 == 0) cout << cnt << '\n';
}

void Select(int b, int c) {
	Merge(b, c);

	if (b + 1 < c) {
		Select(b + 1, c);
	}
	if (c + 1 < n) {
		Select(b, c + 1);
	}
}

void solution() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			string A = start.substr(0, i);
			string B = start.substr(i, j - i);
			string C = start.substr(j, n - j);

			reverse(A.begin(), A.end());
			reverse(B.begin(), B.end());
			reverse(C.begin(), C.end());

			string D = A + B + C;

			if (res > D) {
				res = D;
			}
		}
	}
}

int main() {
	cin >> start;

	res = "~";
	n = start.size();

	solution();

	//Select(1, 2);

	cout << res << '\n';

	return 0;
}