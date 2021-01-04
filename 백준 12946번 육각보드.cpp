#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;		//육각판 사이즈 

int ans;	//최소 필요 색 수
char YorN[50][50];	// 색칠 여부
int Col[50][50];	//색깔
int dx[] = { -1,-1,0,0,1,1 };	// 확인할 주변 좌표 값 (x)
int dy[] = { 0,1,-1,1,-1,0 };	// 확인할 주변 좌표 값 (y)

void dfs(int x, int y, int c)
{
	Col[x][y] = c; // c색으로 칠한다.

	ans = max(ans, 1);

	for (int k = 0; k < 6; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) // 육각판 범위를 벗어나지 않으며
		{
			if (YorN[nx][ny] == 'X')	//색칠되어야 하는 곳이며
			{
				if (Col[nx][ny] == -1)	//색칠 되어 있지 않다면
				{
					dfs(nx, ny, 1 - c);	// 본인(c)이0 이면 주변1, 본인(c)이1 이면 주변0으로 색칠한다.
				}
				ans = max(ans, 2);		//내 주변 색 칠했으므로 최소한 2이상
				if (Col[nx][ny] == c)	//내 색이랑 주변 색이랑 똑같다면, 즉 주변이 본인 말고 또 다른 주변 영향으로 색칠되어졋으며, 그 주변 색이 본인과 색이 같을 경우
				{
					ans = 3; // ans에 3 넣음
				}
			}
		}
	}
}

int main(void)
{
	memset(Col, -1, sizeof(Col));	// 모든 색 일단 색 안칠함 (-1로)

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> YorN[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (YorN[i][j] == 'X' && Col[i][j] == -1)	//색칠해야하는 곳이나 색칠이 안되있으면
			{
				dfs(i, j, 0);	//색칠해야하는 부분과 일단 0색으로 칠한다.
			}
		}
	}
	cout << ans;

	return 0;
}