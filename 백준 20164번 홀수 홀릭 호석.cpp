#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 987654321

int n;
int big = -INF;
int small = INF;

int counting(string str) {
	int cnt = 0;
	for(int i = 0; i < str.size(); i++) {
		int num = str[i] - '0';
		if (num % 2 == 1) {
			cnt++;
		}
	}
	return cnt;
}

string divideAndAdd(int p, int q, string str) {
	string a = "";
	string b = "";
	string c = "";
	int A, B, C;

	for (int i = 0; i < p; i++) {
		a += str[i];
	}
	for (int i = p; i < q; i++) {
		b += str[i];
	}
	for (int i = q; i < str.size(); i++) {
		c += str[i];
	}
	int tmp = stoi(a) + stoi(b) + stoi(c);
	return to_string(tmp);
}

void retCnt(string str, int sum) {
	if (str.size() == 1) {
		big = max(big, sum);
		small = min(small, sum);
	}
	if (str.size() == 2) {
		string str2 = "";
		int tres;

		str2 = to_string((str[0] - '0') + (str[1] - '0'));
		tres = counting(str2);

		retCnt(str2, sum + tres);
	}
	else {
		int tbig = -INF;
		int tsmall = INF;
		for (int i = 1; i < str.size()-1; i++) {
			for (int j = i+1; j < str.size(); j++) {
				string str2 = "";
				int tres;
				pair<int, int> tmp;

				str2 = divideAndAdd(i, j, str);
				tres = counting(str2);

				retCnt(str2, sum + tres);
			}
		}
	}
}

int main() {

	cin >> n;
	int k = counting(to_string(n));

	retCnt(to_string(n), 0);

	cout << small + k << ' ' << big + k << '\n';

	return 0;
}