#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int r;
string s;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("%d\n", 1);
		return 0;
	}
	else if (n == 0) {
		printf("%d\n", 0);
		return 0;
	}

	while (n != 1) {
		if (n < 0 && -n % 2 == 1) { // 음수이고 홀수
			s += '1';
			n = (n / -2) + 1;
		}

		/*else if (n > 0 && n % 2 == 1) {
			r = 1;
			n = (n / -2) + 1;
		}*/
		
		else {
			//int r = n % -2;
			s += n % -2 + '0';
			n = n / -2;
		}
		//s += (r + '0');
	}
	s += '1';

	reverse(s.begin(), s.end());

	cout << s << endl;

	//printf("%d\n", -3 / -2);
	//printf("%d\n", -13 % -2);


	return 0;
}
/*printf("%d\n", 4 / -2);
printf("%d\n", 4 % -2);

printf("%d\n", 3 / -2);
printf("%d\n", 3 % -2);

printf("%d\n", -4 / -2);
printf("%d\n", -4 % -2);

printf("%d\n", -3 / -2);
printf("%d\n", -3 % -2);*/