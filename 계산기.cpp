#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int prior(char p) {
	int k;
	if (p == '+' || p == '-') {
		k = 1;
	}
	else if (p == '*' || p == '/') {
		k = 2;
	}
	else if (p == '^') {
		k = 3;
	}
	else
		k = 4;
	return k;
}

int main(void) {
	queue <char> q_sic; // ����ǥ��� �����
	stack<char>s_cal; // ������ ���ÿ�
	string str1;
	int first = 0;

	cin >> str1;

	for (int i = 0; i < str1.size(); i++) {


		if (str1[i] != '+' && str1[i] != '-' && str1[i] != '*' && str1[i] != '/' &&
			str1[i] != '(' && str1[i] != ')' && str1[i] != '^') {

			q_sic.push(str1[i]);
		}

		else {
			if (s_cal.empty()) {//������ ���� ��������� �׳� Ǫ�� �� ��������
				s_cal.push(str1[i]);
				continue;
			}

			if (s_cal.top() == '(') {//������ 4�� (�� ���ÿ� �� �� ù �����ڸ� y>=x ������ �ֱ⸸ �ϴ� ������ ����
				s_cal.push(str1[i]);
				continue;
			}

			if (str1[i] == ')') {// ()�ȿ� �ִ� ����� ����ǥ��Ŀ� �����ϴ� ����
				while (1) {
					if (s_cal.top() == '(') {
						s_cal.pop();
						break;
					}

					q_sic.push(s_cal.top());// ����ǥ��Ŀ� ����ֱ�
					s_cal.pop(); // ����
				}
				continue;
			}

			//������ �켱���� �� �� �ְ� ����
			if (s_cal.empty()) {
				s_cal.push(str1[i]);
				continue;
			}

			int y = prior(str1[i]);
			int x = prior(s_cal.top());

			if (y > x) {// y >= x�� ���
				s_cal.push(str1[i]);
			}

			else { // y < x�� ���, cal�� �ִ� �� �� ���
				while (!s_cal.empty()) {
					q_sic.push(s_cal.top());
					s_cal.pop();
				}
				s_cal.push(str1[i]);
			}
		}

		//if (i == str1.size() - 1) {//�������̴ϱ� ���� ������ �� Ǫ��
		//	while (!s_cal.empty()) {
		//		q_sic.push(s_cal.top());
		//		s_cal.pop();
		//	}
		//}
	}

	while (!s_cal.empty()) {//������ ���ÿ� ���� ��� ���
		q_sic.push(s_cal.top());
		s_cal.pop();
	}

	while (!q_sic.empty()) {
		printf("%c", q_sic.front());
		q_sic.pop();
	}
	puts("");

	//���� a*(b+c)/d, a*b+(c+d)+e+f, a-(b+c)/d, a+(b+(c-d))
	return 0;
}