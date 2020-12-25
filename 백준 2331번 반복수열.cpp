#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int i_num, p;
int a[10000000][2];
int cnt=1;
int ans;
bool check[10000000];
bool stop;
string s_num;

int cal() {
	int len = s_num.length();
	int basu = 1;
	int next = 0;
	for (int i = len-1; i >= 0; i--) {
		int k=1;
		for (int j = 0; j < p; j++) {
			k *= s_num[i] - '0';
		}
		next += k;
	}
	return next;
}

int main() {
	scanf("%d %d", &i_num, &p);
	int start = i_num;
	
	s_num = to_string(i_num);

	int next;
	while (1) {
		next = cal();

		//종료조건
		if (a[next][1] > 0) {
			printf("%d\n", a[next][1] - 1);
			return 0;
		}

		//저장
		a[i_num][0] = next;
		a[i_num][1] = cnt;
		cnt++;
		//다음을 위한 준비
		s_num = to_string(next);
		i_num = next;
	}
}