#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAX 10000 + 100

int n;
int delay[MAX];
int inDegree[MAX];
int cache[MAX];
vector<int> graph[MAX];


void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int time, num;
		cin >> time >> num;

		delay[i] = time;

		for (int j = 0; j < num; j++) {
			int first_job;
			cin >> first_job;

			graph[first_job].push_back(i);
			inDegree[i]++;
		}
	}
}

int getMinTime() {
	int res = 0;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] > 0) continue;

		//if (inDegree[i]) { continue; }

		q.push(i);
		cache[i] = delay[i];

		//cout << inDegree[i] << ' ' << i << '\n';
	}

	while (!q.empty()) {
		int job = q.front();
		q.pop();

		for (int next : graph[job]) {
			cout << next << ' ';

			if (--inDegree[next] == 0) {
				q.push(next);
				//cout <<'\n';
				//cout << next << ' ';
				//cout << '\n';
			}

			cache[next] = max(cache[next], cache[job] + delay[next]);
		}
	}

	for (int i = 1; i <= n; i++) {
		res = max(res, cache[i]);
	}

	return res;
}

int main() {
	input();
	
	cout << getMinTime() << '\n';
	return 0;
}