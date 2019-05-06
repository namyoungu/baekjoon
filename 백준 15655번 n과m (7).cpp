#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, tmp, s[8], f[8];

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