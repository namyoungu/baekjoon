#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	long long num;
	int s, e;
};

int n;
int a[100001];
int s, e;


point solve(int left, int right) {
	if (left == right) return { (long long)a[left] * a[left], left, right};

	int mid = (left + right) / 2;

	point res;
	point p = solve(left, mid);
	point q = solve(mid + 1, right);

	if (p.num > q.num){
		res = p;
	}
	else {
		res = q;
	}

	int low = mid;
	int high = mid + 1;
	int mNum = min(a[low], a[high]);
	long long sum = (long long)a[low] + a[high];

	long long t = sum * mNum;
	if (res.num < t) {
		res.num = t;
		res.s = low;
		res.e = high;
	}

	while (left < low || high < right) {
		if (high < right && (low == left || a[low - 1] < a[high + 1])) {
			high++;
			mNum = min(mNum, a[high]);
			sum += a[high];
		}
		else {
			low--;
			mNum = min(mNum, a[low]);
			sum += a[low];
		}
		long long t = sum * mNum;
		if (res.num < t) {
			res.num = t;
			res.s = low;
			res.e = high;
		}
	}

	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}

	point res = solve(1, n);

	cout << res.num << '\n';
	cout << res.s<< ' ' << res.e<< '\n';

	return 0;
}