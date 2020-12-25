#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct point {
	int y, x;
};

int n, lim;
int map[10][10];
bool tile_visit[10][10], row_visit[10][10], col_visit[10][10], square_visit[10][10];
int s1, s2;

vector<point> end_point;


bool row_check(int y1, int x1, int y2, int x2, int num1, int num2) {
	if (row_visit[y1][num1]) return false;
	if (row_visit[y2][num2]) return false;
	return true;
}
bool col_check(int y1, int x1, int y2, int x2, int num1, int num2) {
	if (col_visit[x1][num1]) return false;
	if (col_visit[x2][num2]) return false;
	return true;
}
bool square_check(int y, int x, int num) {
	int ty = y / 3;
	int tx = x % 3;
	
	if (square_visit[ty + tx][num]) return false;

	//square_visit[ty + tx][num] = true;
	return true;
}

void dfs(int dep, int point, bool &suc) {
	if (dep == lim) {
		suc = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			puts("");
		}
		return;
	}

	int y = point / 9;
	int x = point % 9;

	if (map[y][x] != 0) {
		dfs(dep, point+1, suc);
		return;
	}

	//도미노 타일 만들기
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			//도미노 타일 회전
			for (int rot = 0; rot < 2; rot++) {
				//연산
				int y1, x1, y2, x2;
				y1 = y2 = y;
				x1 = x2 = x; 
				if (rot == 0) {
					x2++;
					if (x2 >= 9) continue;
				}
				else {
					y2++;
					if (y2 >= 9) continue;
				}

				if (row_check(y1, x1, y2, x2, i, j) && col_check(y1, x1, y2, x2, i, j)
					&& square_check(y1, x1, i) && square_check(y2, x2, j)) {
					int ty1 = y1 / 3;
					int tx1 = x1 % 3;
					int ty2 = y2 / 3;
					int tx2 = x2 % 3;

					row_visit[y1][i] = true;
					row_visit[y2][j] = true;
					col_visit[x1][i] = true;
					col_visit[x2][j] = true;
					square_visit[ty1 + tx1][i] = true;
					square_visit[ty2 + tx2][j] = true;


					map[y1][x1] = i;
					map[y2][x2] = j;

					dfs(dep + 1, point + 1, suc);
					if (suc) return;

					//역연산
					row_visit[y1][i] = false;
					row_visit[y2][j] = false;
					col_visit[x1][i] = false;
					col_visit[x2][j] = false;
					square_visit[ty1 + tx1][i] = false;
					square_visit[ty2 + tx2][j] = false;

					map[y1][x1] = 0;
					map[y2][x2] = 0;
				}
			}
		}
	}
}

int main() {
	int y = -1;
	for (int i = 0; i < 3; i++) {
		y += 3;
		int x = -1;
		for (int j = 0; j < 3; j++) {
			x += 3;

			end_point.push_back({ y, x });
		}
	}

	int tc = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			int a, b; string str1, str2;
			int y1, x1, y2, x2;

			cin >> a >> str1 >> b >> str2;

			if (str2[0] - str1[0] < 0 || str2[1] - str1[1] < 0) {
				swap(str1, str2);
				swap(a, b);
			}

			y1 = str1[0] - 'A';
			x1 = str1[1] - '0' - 1;
			y2 = str2[0] - 'A';
			x2 = str2[1] - '0' - 1;

			map[y1][x1] = a;
			map[y2][x2] = b;

			int ty1 = y1 / 3;
			int tx1 = x1 % 3;
			int ty2 = y2 / 3;
			int tx2 = x2 % 3;

			tile_visit[a][b] = true;
			row_visit[y1][a] = true;
			row_visit[x1][a] = true;
			col_visit[y2][b] = true;
			col_visit[x2][b] = true;
			square_visit[ty1 + tx1][a] = true;
			square_visit[ty2 + tx2][b] = true;
		}
		for (int i = 1; i <= 9; i++) {
			string str;
			int y, x;

			cin >> str;

			y = str[0] - 'A';
			x = str[1] - '0' - 1;

			map[y][x] = i;

			int ty = y / 3;
			int tx = x % 3;

			row_visit[y][i] = true;
			col_visit[x][i] = true;
			square_visit[ty + tx][i] = true;
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << row_visit[i][j] << ' ';
			}
			puts("");
		}

		puts("");
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			puts("");
		}
		puts("");

		lim = 72 - n;
		bool suc = false;
		cout << "Puzzle " << tc++ << '\n';
		dfs(0, 0, suc);
	}
	return 0;
}