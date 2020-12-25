#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <algorithm>
#include<functional>
#include <queue>
using namespace std;
queue <int> q;
queue <int> ind;
queue <int> imp_s;

int main(void) {
	int t_s, n[100], m[100], M, tmp, tmp2, t_i, count;
	int imp[100][100], tmp_imp[100];

	scanf("%d", &t_s);
	for (int i = 0; i < t_s; i++) {
		scanf("%d %d", &n[i], &m[i]);
		for (int j = 0; j < n[i]; j++) {
			scanf("%d", &imp[i][j]);
			//printf(" %d\n", imp[i][j]);
		}
	}
	
	for (int i = 0; i < t_s; i++) {
		for (int z = 0; z < n[i]; z++) {// 최대값을 위한 임시중요도
			tmp_imp[z] = imp[i][z];
			//printf("  %d", tmp_imp[z]);
		}
		sort(tmp_imp, tmp_imp + n[i], greater<int>());
	
		for (int z = 0; z < n[i]; z++) { // 중요도, 인덱스 큐 생성
			q.push(imp[i][z]);
			ind.push(z);
		}
		
		t_i = imp[i][m[i]]; // 타켓의 중요도

		count = 0;
		int k = 0;
		while (1) {
			if (q.front() != tmp_imp[k]) {//최대값을 맨 앞으로 오게하기위함
				tmp = q.front();
				tmp2 = ind.front();
				q.pop();
				q.push(tmp);
				ind.pop();
				ind.push(tmp2);
				continue;
			}
			//현재 최대값이 맨 앞인 상태

			if (tmp_imp[k] != t_i) {//타겟중요도랑 현재 최대값이랑 다르면
				q.pop();
				ind.pop();
				count++;
				//printf("a%d\n", count);
				k++;//배출하고 그 다음 최대값
				continue;
			}
			else {
				if (ind.front() != m[i]) {
					q.pop();
					ind.pop();
					count++;
					//printf("b%d\n", count);
				}
				else {
					count++;
					//printf("c%d\n", count);
					break;
				}
			}
		}
		
		printf("%d\n", count);

		while (!q.empty()) { //큐 초기화
			q.pop();
			ind.pop();
		}
	}
}