#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n;
char s[20][35], e[20][5];


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}

	for (int i = 0; i < n; i++) {
		int len = strlen(s[i]);
		int k = len - 1;

		if (s[i][k] == 'a') {
			s[i][k + 1] = 's';
			len++;
		}

		else if (s[i][k] == 'i') {
			s[i][k + 1] = 'o';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 'y') {
			s[i][k] = 'i';
			s[i][k + 1] = 'o';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 'l') {
			s[i][k + 1] = 'e';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 'n') {
			//s[i][k - 1] = 'a';
			s[i][k] = 'a';
			s[i][k + 1] = 'n';
			s[i][k + 2] = 'e';
			s[i][k + 3] = 's';
			len++; len++; len++;
		}

		else if (s[i][k] == 'e') {
			if (s[i][k - 1] == 'n') {
				s[i][k - 1] = 'a';
				s[i][k] = 'n';
				s[i][k + 1] = 'e';
				s[i][k + 2] = 's';
				//s[i][k + 3] = 's';
				len++; len++;
			}
			else {
				s[i][k + 1] = 'u';
				s[i][k + 2] = 's';
				len++; len++;
			}
		}

		else if (s[i][k] == 'o') {
			s[i][k + 1] = 's';
			len++;
		}

		else if (s[i][k] == 'r') {
			s[i][k + 1] = 'e';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 't') {
			s[i][k + 1] = 'a';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 'u') {
			s[i][k + 1] = 's';
			len++;
		}

		else if (s[i][k] == 'v') {
			s[i][k + 1] = 'e';
			s[i][k + 2] = 's';
			len++; len++;
		}

		else if (s[i][k] == 'w') {
			s[i][k + 1] = 'a';
			s[i][k + 2] = 's';
			len++; len++;
		}
		else {
			s[i][k + 1] = 'u';
			s[i][k + 2] = 's';
			len++; len++;
		}
		

		for (int j = 0; j < len; j++) {
			
			printf("%c", s[i][j]);
		}
		puts("");
	}

	return 0;
}