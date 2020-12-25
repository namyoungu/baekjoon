#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int main(void){
	int t_c, su[100], t_ind[100], t_imp[100], f, count, M, r=0;
	int imp[100][500], point[100][500];

	scanf("%d", &t_c); //test_case 수 입력

	for (int z = 0; z < t_c; z++) {
		scanf("%d %d", &su[z], &t_ind[z]); //문서의 수와 타겟의 인덱스
		for (int i = 0; i < su[z]; i++) {
			scanf("%d", imp[z]); //문서의 중요도 입력
			r++;
			t_imp[z] = imp[z][t_ind[z]]; //타겟의 중요도 저장
		}

		for (int i = 0; i < su[z]; i++) {
			point[z][i] = i;
		}
	}

		for (int z = 0; z < t_c; z++) {
			f = 0;
			r = 0;//큐 인덱스 초기화
			count = 0;//카운팅 초기화

			//밀어내기
			while (1) {
				for (int i = 0; i < r - f + 1; i++) { //최댓값 구하기
					M = max(-1, imp[z][i]);
				}

				if (imp[z][f] != M) { //선두가 최댓값이 아니면 밀어내기
					imp[z][r] = imp[z][f];
					f++;
					r++;
					count++;
					continue;
				}

				if (M != t_imp[z] || point[z][f] != t_ind[z]) { //선두가 타겟아니면 삭제
					f++;
					count++;
					continue;
				}
				break;
			}

			for (int i = 0; i < z; i++) {
				if (count == 0) printf("%d", 1);
				else printf("%d", count);
			}
		}

	return 0;
}