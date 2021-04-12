#include <iostream>
#include <algorithm>
#include <memory.h>
#include  <vector>
using namespace std;

typedef vector<vector<long long>> vec;

long long N, B;
vec map(6, vector<long long>(6, 0));


void  print(vec v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

vec doMod(vector<vector<long long>> v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] %= 1000;
		}
	}
	return v;
}

vec doMul(vec v1, vec v2) {
	vec tmap(6, vector<long long>(6, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tmap[i][j] += ((v1[i][k] * v2[k][j])) % 1000;
			}
			tmap[i][j] %= 1000;
		}
	}

	return tmap;
}


vec solve(long long b) {
	if (b == 1) {
		return map;
	}

	vec half = solve(b/2);
	half = doMod(half);

	vec next = doMul(half, half);

	if (b % 2 == 0) {
		return next;
	}
	else {
		next = doMul(next, map);
		return next;
	}

}

int  main() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	map = doMod(map);
	
	print(solve(B));

	return 0;
}