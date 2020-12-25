#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int h, w, tmp = 1;
int a[] = { 1,-1,0,0 }, b[] = { 0,0,1,-1 }, v[1500][1500], mv[1500][1500], day[1500][1500];
char s[1501][1501];

struct point {
	int y, x;
};

queue<point>q;
queue<point>m;
//pair<int, int>start;
vector<pair<int, int>>start;

//bool check() {
//	q.push({ start.first, start.second });
//	v[start.first][start.second] = 1;
//
//	while (!q.empty()) {
//		point t = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int t_y = t.y + a[i];
//			int t_x = t.x + b[i];
//
//			if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && v[t_y][t_x] == 0) {
//				if (s[t_y][t_x] == 'L') {
//					return true;
//				}
//				if (s[t_y][t_x] == '.') {
//					q.push({ t_y, t_x });
//					v[t_y][t_x] = 1;
//				}
//			}
//		}
//	}
//	return false;
//}

bool check(int y, int x) {
	q.push({y, x});

	while (!q.empty()) {
		point t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int t_y = t.y + a[i];
			int t_x = t.x + b[i];

			if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && v[t_y][t_x] == 0) {
				
			}
		}
	
	
	
	
	}

}

void melt() {
	int cnt = 1;
	while(!m.empty()){
		int sz = m.size();
		for(int i=0; i<sz; i++){
			point t = m.front();
			m.pop();
			mv[t.y][t.x] = 1;
			for (int k = 0; k < 4; k++) {
				int t_y = t.y + a[k];
				int t_x = t.x + b[k];

				if (t_y >= 0 && t_y < h && t_x >= 0 && t_x < w && mv[t_y][t_x] == 0) {
					if (s[t_y][t_x] != 'L') {
						m.push({ t_y, t_x });
						mv[t_y][t_x] = 1;
						day[t_y][t_x] = cnt;
					}
				}
			}
		}
		cnt++;
	}
}

int main(void) {
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < w; j++) {
			if (s[i][j] == 'L' || s[i][j] == '.') {
				m.push({i, j});
				mv[i][j] = 1;
			}
			if (s[i][j] == 'L') {
				start.push_back({ i, j });
			}
		}
	}
	//
	puts("");
	puts("");
	//

	melt();

	while (!check(start[0].first, start[0].second)) {
		
	
	}

	return 0;
}