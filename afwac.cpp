#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[2][3];

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}

	return 0;
}