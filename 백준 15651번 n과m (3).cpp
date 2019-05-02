#include <cstdio>
int n, m, s[8];

void go(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", s[i]);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
		s[dep] = i;
		go(dep + 1);
	}

}

int main(void) {
	scanf("%d %d", &n, &m);

	go(0);

	return 0;
}