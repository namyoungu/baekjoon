#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int res;
vector<pair<int, int>> v;

void move(int dep, int from, int to) {
	if (dep == 1) {
		res++;
		v.push_back(make_pair(from, to));
		return;
	}

	int tmp;
	for (int i = 1; i < 4; i++) {
		if (i != from && i != to) {
			tmp = i;
		}
	}

	move(dep-1, from, tmp);
	move(1, from, to);
	move(dep-1, tmp, to);
}

int main() {
	cin >> n;

	move(n, 1, 3);

	cout << res << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}