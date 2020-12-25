#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int n;
int map[100][100];

vector<point>v;

void dfs(int dep, int p) {
	int y = p / n;
	int x = p % n;

	if (p == n * n) {
		printf("%d\n", v.size());
		system("pause");
		for (int i = 0; i < v.size(); i++) {
			printf("%d %d\n", v[i].y, v[i].x);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (i < y) continue;
		for (int j = 0; j < n; j++) {
			v.push_back({ y, x });
			dfs(dep + 1, p + 1);
			v.pop_back();
		}
	}

}

int main() {
	scanf("%d", &n);

	dfs(0, 0);

	return 0;
}