#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

string W;
string S;
int cache[101][101];

bool solve(int w, int s) {
	int& res = cache[w][s];
	if (res != -1) return res;

	while (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s])) {
		w++; s++;
	}

	if (w == W.size())
		return res = (s == S.size());

	if (W[w] == '*') {
		for (int i = 0; i + s <= S.size(); i++) {
			return res = solve(w + 1, i + s);
		}
	}

	return res = 0;
}

int main() {
	int T;
	int n;

	cin >> T;
	while (T--) {
		vector<string> v;

		cin >> W;
		cin >> n;

		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));

			cin >> S;
			if (solve(0, 0)) {
				v.push_back(S);
			}
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}
	
	return 0;
}