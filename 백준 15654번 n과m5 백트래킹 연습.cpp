#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, v[9], ta[9], a[9];
void go(int cnt) {
	if (cnt == m + 1) {
		for (int j = 1; j <= m; j++) printf("%d ", a[j]);
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) continue;
		a[cnt] = ta[i];
		v[i] = 1;
		go(cnt + 1);
		v[i] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &ta[i]);
	sort(ta + 1, ta + n + 1);
	go(1);
	return 0;
}