#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int main(void){
	int t_c, su[100], t_ind[100], t_imp[100], f, count, M, r=0;
	int imp[100][500], point[100][500];

	scanf("%d", &t_c); //test_case �� �Է�

	for (int z = 0; z < t_c; z++) {
		scanf("%d %d", &su[z], &t_ind[z]); //������ ���� Ÿ���� �ε���
		for (int i = 0; i < su[z]; i++) {
			scanf("%d", imp[z]); //������ �߿䵵 �Է�
			r++;
			t_imp[z] = imp[z][t_ind[z]]; //Ÿ���� �߿䵵 ����
		}

		for (int i = 0; i < su[z]; i++) {
			point[z][i] = i;
		}
	}

		for (int z = 0; z < t_c; z++) {
			f = 0;
			r = 0;//ť �ε��� �ʱ�ȭ
			count = 0;//ī���� �ʱ�ȭ

			//�о��
			while (1) {
				for (int i = 0; i < r - f + 1; i++) { //�ִ� ���ϱ�
					M = max(-1, imp[z][i]);
				}

				if (imp[z][f] != M) { //���ΰ� �ִ��� �ƴϸ� �о��
					imp[z][r] = imp[z][f];
					f++;
					r++;
					count++;
					continue;
				}

				if (M != t_imp[z] || point[z][f] != t_ind[z]) { //���ΰ� Ÿ�پƴϸ� ����
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