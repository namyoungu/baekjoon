#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c, p, cnt;

vector<int>v;

void one() {
	//가로
	for (int i = 0; i < c; i++) {
		if (i + 3 < c) {
			if (v[i] == v[i + 1] && v[i + 1] == v[i + 2] && v[i + 2] == v[i + 3]) {
				cnt++;
				//printf("%d %d %d %d %d\n",i, v[i], v[i+1], v[i+2], v[i+3]);
				//system("pause");
			}
		}
	}

	//세로
	cnt += c;
	
	return;
}

void two() {
	for (int i = 0; i < c; i++) {
		if (i + 1 >= c) break;
		if (v[i] == v[i + 1]) cnt++;
	}

	return;
}

void three() {
	for (int i = 0; i < c; i++) {
		if (i + 2 < c) {
			if (v[i] == v[i + 1] && v[i+1] == v[i+2] - 1) {
				if (v[i] + 1 == v[i + 2]) {
					cnt++;
				}
			}
		}

		if (i + 1 < c) {
			if (v[i] - 1== v[i + 1]) {
				cnt++;
			}
		}
	}

	return;
}

void four() {
	for (int i = 0; i < c; i++) {
		if (i + 2 < c) {
			if (v[i + 1] == v[i + 2]) {
				if (v[i] - 1 == v[i + 1]) {
					cnt++;
				}
			}
		}
		if (i + 1 < c) {
			if (v[i] == v[i + 1] - 1) {
				cnt++;
			}
		}
	}
	return;
}

void five() {
	for (int i = 0; i < c; i++) {
		if (i + 2 < c) {
			if (v[i] == v[i + 1] && v[i+1] == v[i + 2]) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1] - 1) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1] + 1) {
				cnt++;
			}
		}
		if (i + 2 < c) {
			if (v[i] == v[i + 1] + 1 && v[i+1] + 1 == v[i + 2]) {
				cnt++;
			}
		}
	}
	return;
}

void six() {
	for (int i = 0; i < c; i++) {
		if (i + 2 < c) {
			if (v[i] == v[i + 1] && v[i+1] == v[i + 2]) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1] + 2) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1]) {
				cnt++;
			}
		}
		if (i + 2 < c) {
			if (v[i] + 1 == v[i + 1] && v[i+1] == v[i + 2]) {
				cnt++;
			}
		}
	}
	return;
}

void seven() {
	for (int i = 0; i < c; i++) {
		if (i + 2 < c) {
			if (v[i] == v[i + 1] && v[i+1] == v[i + 2]) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1] - 2) {
				cnt++;
			}
		}

		if (i + 1 < c) {
			if (v[i] == v[i + 1]) {
				cnt++;
			}
		}
		if (i + 2 < c) {
			if (v[i] == v[i + 1] && v[i+1] == v[i + 2] + 1) {
				cnt++;
			}
		}
	}
	return;
}

void simul() {
	if (p == 1) {
		one();
	}
	else if (p == 2) {
		two();
	}
	else if (p == 3) {
		three();
	}
	else if (p == 4) {
		four();
	}
	else if (p == 5) {
		five();
	}
	else if (p == 6) {
		six();
	}
	else {
		seven();
	}
	return;
}

int main() {
	//int tc;
	//scanf("%d", &tc);
	//while (tc--) {
		scanf("%d %d", &c, &p);
		int t;
		for (int z = 0; z < c; z++) {
			scanf("%d", &t);
			v.push_back(t);
		}

		simul();
		printf("%d\n\n\n", cnt);
		//cnt = 0;
		//v.clear();
	//}
	return 0;
}