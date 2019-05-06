#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, tmp ,s[9], f[9], v[9];

void go(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", s[i]);
		}
		puts("");
		return;
	}

	for (int i = 0; i < n; i++) {
		tmp = f[i];
		if (dep > 0 && s[dep-1] >= tmp) {
			continue;
		}
		s[dep] = tmp;
		go(dep + 1);
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
	}
	sort(f, f + n);
	go(0);
	return 0;
}