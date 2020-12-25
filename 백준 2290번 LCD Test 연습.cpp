#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int s;
int y, x;
string n;
string str[23];

void one() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			for (int j = 0; j < x; j++) {
				str[i].push_back(' ');
			}
		}
		else {
			for (int j = 0; j < x-1; j++) {
				str[i].push_back(' ');
			}
			str[i].push_back('|');
		}
		str[i].push_back(' ');
	}
}

void two() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x-2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				str[i].push_back('|');
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
			}
		}
		str[i].push_back(' ');
	}
}
void three() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void four() {
	for (int i = 0; i < y; i++) {
		if (i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else if (i == 0 || i == y - 1) {
			for (int j = 0; j < x; j++) {
				str[i].push_back(' ');
			}
		}

		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void five() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
			}
			else {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void six() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
			}
			else {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void seven() {
	for (int i = 0; i < y; i++) {
		if (i == 0) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else if (i == y / 2 || i == y - 1) {
			for (int j = 0; j < x; j++) {
				str[i].push_back(' ');
			}
		}
		else {
			for (int j = 0; j < x - 1; j++) {
				str[i].push_back(' ');
			}
			str[i].push_back('|');
		}
		str[i].push_back(' ');
	}
}
void eight() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void nine() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1 || i == y / 2) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				for (int j = 0; j < x - 1; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
void zero() {
	for (int i = 0; i < y; i++) {
		if (i == 0 || i == y - 1) {
			str[i].push_back(' ');
			for (int j = 0; j < x - 2; j++) {
				str[i].push_back('-');
			}
			str[i].push_back(' ');
		}
		else if (i == y / 2) {
			for (int j = 0; j < x; j++) {
				str[i].push_back(' ');
			}
		}
		else {
			if (i < y / 2) {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
			else {
				str[i].push_back('|');
				for (int j = 0; j < x - 2; j++) {
					str[i].push_back(' ');
				}
				str[i].push_back('|');
			}
		}
		str[i].push_back(' ');
	}
}
int main() {
	cin >> s;
	cin >> n;

	y = s * 2 + 3;
	x = s + 2;

	for (int i = 0; i < n.length(); i++) {
		switch (n[i]) {
		case '1': one(); break;
		case '2': two(); break;
		case '3': three(); break;
		case '4': four(); break;
		case '5': five(); break;
		case '6': six(); break;
		case '7': seven(); break;
		case '8': eight(); break;
		case '9': nine(); break;
		case '0': zero(); break;
		default: break;
		}
	}
	int k = 0;
	for (int i = 0; i < y; i++) {
		//if (i == y - 1) k++;
		for (int j = 0; j < str[i].length()-k; j++) {
			cout << str[i][j];
		}
		puts("");
	}

	return 0;
}