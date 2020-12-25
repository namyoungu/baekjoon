#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int map[9][9];
int tmap[9][9];
int used[9][10];
bool ed = false;
vector<int>v;

bool square_check(int y, int x) {
	int visit[10] = { 0, };
	y %= 9;
	x %= 9;

	if (y < 3 && x < 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((3 <= y && y < 6) && x < 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((6 <= y && y < 9) && x < 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if (y < 3 && (3 <= x && x < 6)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((3 <= y && y < 6) && (3 <= x && x < 6)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((6 <= y && y < 9) && (3 <= x && x < 6)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if (y < 3 && (6 <= x && x < 9)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((3 <= y && y < 6) && (6 <= x && x < 9)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	else if ((6 <= y && y < 9) && (6 <= x && x < 9)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (visit[tmap[i][j]] == 1) {
					for (int i = 1; i <= 9; i++) {
						printf("%d ", visit[i]);
					}
					puts("");

					return false;
				}
				if (tmap[i][j] != 0) {
					visit[tmap[i][j]] = 1;
				}
			}
		}
	}

	return true;
}

bool col_check(int x, int value) {
	for (int i = 0; i < 9; i++) {
		if (tmap[i][x] == value) {
			return false;
		}
	}
	return true;
}

void dfs(int y, int dep) {
	if (dep == n) {
		/*puts("");
		for (int i = 0; i < 9; i++) {
			printf("%d ", tmap[y][i]);
		}
		puts("");*/
		//system("pause");
		ed = true;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (tmap[y][i] != 0) continue;
		for (int j = 0; j < n; j++) {
			int x = v[j];
			if (col_check(i, x)) {
				if (!square_check(y, i)) continue;
				used[y][x] = 1;
				tmap[y][i] = x;
				dfs(y, dep + 1);
				if (ed) return;
				used[y][x] = 0;
			}
		}
	}
}

void init() {
	v.clear();
	ed = false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			tmap[i][j] = map[i][j];
		}
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			used[i][map[i][j]] = 1;
		}
		for (int j = 1; j <= 9; j++) {
			if (used[i][j] == 0) {
				v.push_back(j);
				//printf("%d\n", j);
				//system("pause");
			}
		}
		n = v.size();
		dfs(i, 0);

		/*puts("");
		for (int a = 0; a < 9; a++) {
			for (int b = 0; b < 9; b++) {
				printf("%d ", tmap[a][b]);
			}
			puts("");
		}
		puts("");*/

		init();
	}
	//puts("");
	for (int a = 0; a < 9; a++) {
		for (int b = 0; b < 9; b++) {
			printf("%d ", tmap[a][b]);
		}
		puts("");
	}
	puts("");

	return 0;
}
