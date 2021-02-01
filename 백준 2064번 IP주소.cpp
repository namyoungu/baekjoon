#include <iostream>
#include <cstdio>

using namespace std;

int ip[1000];

void print(int mask) {
	int shift = 24;
	for (int i = 0; i < 4; i++, shift -= 8) {
		//cout << (mask >> shift) << '\n';
		cout << ((mask >> shift) & ((1 << 8) - 1));
		if (i != 3) cout << '.';
	}
	cout << '\n';
}

void solve() {
	int n;
	cin >> n;

	//ip�Է¹ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			ip[i] <<= 8;
			ip[i] |= a;
			getchar();
		}
	}

	//�����
	int subnet = 0;

	//0��° ip�� Ʋ���κ� ã��
	//ã���� Ż���ؼ� Ʋ���κ� �������� ���� 1�� ä���.
	for (int i = 31; i >= 0; i--) {
		int bit = 1 << i;
		bool end = 0;

		for (int j = 1; j < n; j++) {
			if ((ip[0] & bit) != (ip[j] & bit)) {
				end = 1;
				break;
			}
		}

		if (end) break;
		else subnet |= bit;
	}
	cout << subnet << '\n';
	while (subnet/2 != 0) {
		cout << subnet % 2 << ' ';
		subnet /= 2;
	}
	cout << '\n';
	//��Ʈ��ũ �ּ� ����ϱ�
	print(ip[0] & subnet);
	//����� �ּ� ����ϱ�
	print(subnet);
}

int main() {
	solve();
	
	cout << (1 << 1) << '\n';

	return 0;
}
