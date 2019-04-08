#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue <int> q;

int main(void) {
	int n, k, tmp;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	printf("<");

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < k - 1; i++) {
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		
		printf("%d", q.front());
		if (j != n - 1) {
			printf(", ");
		}
		q.pop();
	}
	printf(">");
	return 0;
}
