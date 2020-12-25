#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int a, p;
int check[300000];

int pow(int k) {
	int res=1;
	for (int i = 0; i < p; i++) {
		res *= k;
	}
	return res;
}

int cal(int num) {
	int next=0;

	while (num > 0) {
		next += pow(num % 10);
		num /= 10;
	}
	return next;
}

int dfs(int node, int cnt) {
	if (check[node] != 0) {
		return check[node] - 1;
	}
	check[node] = cnt;
	int next = cal(node);
	dfs(next ,cnt + 1);
}

int main() {
	scanf("%d %d", &a, &p);

	printf("%d\n", dfs(a, 1));

	return 0;
}