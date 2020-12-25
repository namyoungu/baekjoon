#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string s;
vector <string> v;

void Print() {
	for (int i = 1; i < v.size(); i++) {
		cout << v[0];

		bool do_space = true;
		string t = v[i];
		for (int j = t.length()-1; j >= 0; j--) {
			if (!(('A' <= t[j] && t[j] <= 'Z') || ('a' <= t[j] && t[j] <= 'z'))) {
				if (t[j] == ']') {
					cout << "[]";
					j--;
					continue;
				}
				cout << t[j];
			}
			else {
				for (int k = 0; k <= j; k++) {
					if (do_space) {
						cout << ' ';
						do_space = false;
					}
					cout << t[k];
				}
				break;
			}
		}
		cout << ';';
		puts("");
	}
}

int main() {
	getline(cin, s);

	bool kind = true;
	int idx;
	for (int i = 0; i < s.length(); i++) {
		if (kind) {
			if (s[i] == ' ') {
				string t;
				for (int j = 0; j < i; j++) {
					t += s[j];
				}
				v.push_back(t);
				idx = i;
				kind = false;
				continue;
			}
		}

		if (s[i] == ',') {
			string t;
			for (int j = idx + 1; j < i; j++) {
				t += s[j];
			}
			v.push_back(t);
			idx = i+1;
		}

		if (s[i] == ';') {
			string t;
			for (int j = idx + 1; j < i; j++) {
				t += s[j];
			}
			v.push_back(t);
		}
	}

	Print();

	return 0;
}