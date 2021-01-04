#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;		//������ ������ 

int ans;	//�ּ� �ʿ� �� ��
char YorN[50][50];	// ��ĥ ����
int Col[50][50];	//����
int dx[] = { -1,-1,0,0,1,1 };	// Ȯ���� �ֺ� ��ǥ �� (x)
int dy[] = { 0,1,-1,1,-1,0 };	// Ȯ���� �ֺ� ��ǥ �� (y)

void dfs(int x, int y, int c)
{
	Col[x][y] = c; // c������ ĥ�Ѵ�.

	ans = max(ans, 1);

	for (int k = 0; k < 6; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) // ������ ������ ����� ������
		{
			if (YorN[nx][ny] == 'X')	//��ĥ�Ǿ�� �ϴ� ���̸�
			{
				if (Col[nx][ny] == -1)	//��ĥ �Ǿ� ���� �ʴٸ�
				{
					dfs(nx, ny, 1 - c);	// ����(c)��0 �̸� �ֺ�1, ����(c)��1 �̸� �ֺ�0���� ��ĥ�Ѵ�.
				}
				ans = max(ans, 2);		//�� �ֺ� �� ĥ�����Ƿ� �ּ��� 2�̻�
				if (Col[nx][ny] == c)	//�� ���̶� �ֺ� ���̶� �Ȱ��ٸ�, �� �ֺ��� ���� ���� �� �ٸ� �ֺ� �������� ��ĥ�Ǿ����, �� �ֺ� ���� ���ΰ� ���� ���� ���
				{
					ans = 3; // ans�� 3 ����
				}
			}
		}
	}
}

int main(void)
{
	memset(Col, -1, sizeof(Col));	// ��� �� �ϴ� �� ��ĥ�� (-1��)

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
			if (YorN[i][j] == 'X' && Col[i][j] == -1)	//��ĥ�ؾ��ϴ� ���̳� ��ĥ�� �ȵ�������
			{
				dfs(i, j, 0);	//��ĥ�ؾ��ϴ� �κа� �ϴ� 0������ ĥ�Ѵ�.
			}
		}
	}
	cout << ans;

	return 0;
}