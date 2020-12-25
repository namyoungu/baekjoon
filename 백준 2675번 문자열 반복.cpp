#include<stdio.h>

int main(void){
	int n, c, cnt;
	char arr[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		scanf("%s", arr);

		cnt = 0;
		while (1) {
			if (arr[cnt] == '\0') {
				break;
			}
			cnt += 1;
		}
		for (int j = 0; j < cnt; j++) {
			for (int k = 0; k < c; k++) {
				printf("%c", arr[j]);
			}
		}
		puts("");
	}
	return 0;
}