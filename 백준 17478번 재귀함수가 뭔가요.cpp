#include <iostream>
#include <algorithm>
using namespace std;

int n;

void firstPrint(int dep) {
	int cnt = n - dep;
	for (int i = 0; i < cnt; i++) {
		cout << "____";
	}
}

void Print(int dep) {
	if (dep == -1) return;
	



	firstPrint(dep);
	cout << "\"����Լ��� ������?\"" << '\n';

	if (dep == 0) {
		firstPrint(dep);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		firstPrint(dep);
		cout << "��� �亯�Ͽ���." << '\n';
		return;
	}

	firstPrint(dep);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';

	firstPrint(dep);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';

	firstPrint(dep);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';

	Print(dep - 1);

	firstPrint(dep);
	cout << "��� �亯�Ͽ���." << '\n';
}

int main() {
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	Print(n);

	return 0;
}