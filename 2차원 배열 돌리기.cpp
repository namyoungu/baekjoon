#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>
using namespace std;

char matrix[11][11];
char rotated[11][11];
int n;

int main(void) {
	scanf("%d", &n);

	//matrix[0][0] = 'A'-1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 'A' + i*n + j;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", matrix[i][j]);
		}
		puts("");
	}
	puts("");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[i][j] = matrix[n-j-1][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rotated[j][n - i-1] = matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", rotated[i][j]);
		}
		puts("");
	}
	puts("");
	return 0;
}