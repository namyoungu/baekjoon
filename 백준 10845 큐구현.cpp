#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
using namespace std;

int f, r = 0;
int queue[10000];

void push(int k) {
	queue[r] = k;
	r++;
}

void pop() {
	if (r - f == 0) printf("%d\n", -1);
	else {
		printf("%d\n", queue[f]);
		f++;
	}
}

void size() {
	printf("%d\n", r - f);
}

void empty() {
	if (r - f == 0) printf("%d\n", 1);
	else printf("0\n");
}

void front() {
	if (f == r) printf("%d\n", -1);
	else printf("%d\n", queue[f]);
}

void back() {
	if (f == r) printf("%d\n", -1);
	else printf("%d\n", queue[r - 1]);
}


int main(void) {
	char order[6];
	int n, k;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", order);
		if (order[1] == 'u') {
			scanf("%d", &k);
			push(k);
		}
		else if (order[1] == 'o') pop();
		else if (order[0] == 's') size();
		else if (order[0] == 'e') empty();
		else if (order[0] == 'f') front();
		else if (order[0] == 'b') back();
	}

	return 0;
}