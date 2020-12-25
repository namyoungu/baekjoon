#include <iostream>
#include <queue>
using namespace std;

int test_case, w, h;
char map[1001][1001];

struct point {
	int y, x;
};

queue<point>fire, sg;

void bfs() {
	int fire_size = fire.size();
	for (int i = 0; i < fire_size; i++) {
		point t = fire.front();
		fire.pop();

		

	}


}



int main(void) {
	scanf("%d", &test_case);
	for (int z = 0; z < test_case; z++) {
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '*') {
					fire.push({ i, j });
				}
				else if (map[i][j] == '@') {
					sg.push({i, j});
				}
			}
		}
	}

	bfs();

	return 0;
}