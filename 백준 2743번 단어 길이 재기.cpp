#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char str[101];

int main(void) {
	scanf("%s", str);
	int len = 0;
	for (int i = 0; str[i]; i++) {
		len++;
	}
	printf("%d\n", len);
	return 0;
}