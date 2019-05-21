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
	queue <char> q_sic; // 후위표기식 저장용
	stack<char>s_cal; // 연산자 스택용
	string str1;
	int first = 0;

	cin >> str1;

	for (int i = 0; i < str1.size(); i++) {


		if (str1[i] != '+' && str1[i] != '-' && str1[i] != '*' && str1[i] != '/' &&
			str1[i] != '(' && str1[i] != ')' && str1[i] != '^') {

			q_sic.push(str1[i]);
		}

		else {
			if (s_cal.empty()) {//연산자 스택 비어있으면 그냥 푸쉬 후 다음과정
				s_cal.push(str1[i]);
				continue;
			}

			if (s_cal.top() == '(') {//레벨이 4인 (가 스택에 들어간 후 첫 연산자를 y>=x 과정인 넣기만 하는 과정을 실행
				s_cal.push(str1[i]);
				continue;
			}

			if (str1[i] == ')') {// ()안에 있는 놈들을 후위표기식에 저장하는 과정
				while (1) {
					if (s_cal.top() == '(') {
						s_cal.pop();
						break;
					}

					q_sic.push(s_cal.top());// 후위표기식에 집어넣기
					s_cal.pop(); // 삭제
				}
				continue;
			}

			//연산자 우선순위 비교 후 넣고 빼고
			if (s_cal.empty()) {
				s_cal.push(str1[i]);
				continue;
			}

			int y = prior(str1[i]);
			int x = prior(s_cal.top());

			if (y > x) {// y >= x인 경우
				s_cal.push(str1[i]);
			}

			else { // y < x인 경우, cal에 있는 거 다 출력
				while (!s_cal.empty()) {
					q_sic.push(s_cal.top());
					s_cal.pop();
				}
				s_cal.push(str1[i]);
			}
		}

		//if (i == str1.size() - 1) {//마지막이니까 남은 연산자 다 푸쉬
		//	while (!s_cal.empty()) {
		//		q_sic.push(s_cal.top());
		//		s_cal.pop();
		//	}
		//}
	}

	while (!s_cal.empty()) {//연산자 스택에 남은 놈들 출력
		q_sic.push(s_cal.top());
		s_cal.pop();
	}

	while (!q_sic.empty()) {
		printf("%c", q_sic.front());
		q_sic.pop();
	}
	puts("");

	//현재 a*(b+c)/d, a*b+(c+d)+e+f, a-(b+c)/d, a+(b+(c-d))
	return 0;
}