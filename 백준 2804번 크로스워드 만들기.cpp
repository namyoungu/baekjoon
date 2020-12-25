#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string>v;
vector<char> share;
char a[26];
char b[26];

int main(void) {
	for (int i = 0; i < 2; i++) {
		cin >> s;
		v.push_back(s);
	}

	for (int j = 0; j < v[0].size(); j++) {
		s = v[0];
		a[s[j] - 'A'] += 1;
	}
	for (int j = 0; j < v[1].size(); j++) {
		s = v[0];
		b[s[j] - 'A'] += 1;
	}

	for (int i = 0; i < 26; i++) {
		if (a[i] != 0 && b[i] != 0) {
			share.push_back('A' + i);
		}
	}

	for (int i = 0; i < share.size(); i++) {
		
	}

	return 0;
}