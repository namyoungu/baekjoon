#include <cstdio>
int n, m, s[9], v[9];

void go(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", s[i]);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) {
			continue;
		}
		s[dep] = i;
		v[i] = 1;
		go(dep + 1);
		v[i] = 0;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	go(0);

	return 0;
}