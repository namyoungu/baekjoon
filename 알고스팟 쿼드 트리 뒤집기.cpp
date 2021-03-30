#include <iostream>
#include <string>
using namespace std;

int test;
string First;

string reverse(string::iterator &it) {
	char head = *it++;

	if (head == 'b' || head == 'w') {
		string s = "";
		s += head;
		return s;
	}

	string upL = reverse(it);
	string upR = reverse(it);
	string downL = reverse(it);
	string downR = reverse(it);

	return "x" + downL + downR + upL + upR;
}

int main() {
	cin >> test;
	while (test--) {
		cin >> First;
		string::iterator it = First.begin();
		cout << reverse(it) << '\n';
	}

	return 0;
}