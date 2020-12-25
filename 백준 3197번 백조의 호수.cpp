#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int h, w, tmp = 1;
int a[] = { 1,-1,0,0 }, b[] = {0,0,1,-1}, v[1500][1500], mv[1500][1500];
char s[1501][1501];

struct point {
	int y, x;
};

queue<point>q;
queue<point>m;
pair<int, int>start;
vector<pair<int, int>>s_p;

bool check() {
	q.push({ start.first, start.second });
	v[start.first][start.second] = 1;

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int t_y = t.y + a[i];
			int t_x = t.x + b[i];
			
			if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && v[t_y][t_x] == 0) {
				if (s[t_y][t_x] == 'L') {
					return true;
				}
				if (s[t_y][t_x] == '.') {
					q.push({ t_y, t_x });
					v[t_y][t_x]=1;
				}
			}
		}
	}
	return false;
}

void melt() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.' || s[i][j] == 'L') {
				for (int k = 0; k < 4; k++) {
					int t_y = i + a[k];
					int t_x = j + b[k];

					if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && mv[t_y][t_x] == 0) {
						if (s[t_y][t_x] == 'X') {
							m.push({ t_y, t_x });
							mv[t_y][t_x] = 1;
						}
					}
				}
			}
		}
	}

	while (!m.empty()) {
		point t = m.front();
		m.pop();
		s[t.y][t.x] = '.';
	}
}

int main(void) {
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++) {
		scanf("%s", s[i]);
		for(int j=0; j<w; j++){
			if (s[i][j] == 'L') {
				s_p.push_back({ i, j });
			}
			else if () {
			
			}
		}
	}
	//
	puts("");
	puts("");

	while () {
		
	}

	printf("%d\n", cnt);

	return 0;
}
//
////
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++) {
//		printf("%d", v[i][j]);
//	}
//	puts("");
//}
//puts("");
//puts("");
//
////
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++) {
//		printf("%c", s[i][j]);
//	}
//	puts("");
//}
//puts("");
//puts("");
//
//system("pause");