#include <bits/stdc++.h>
using namespace std;

int N, ti, tj;

bool reachable(int si, int sj, int ti, int tj, const vector<string>& B) {
	int N = B.size();
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> q;

	dist[si][sj] = 0;
	q.push({ si, sj });

	int di[4] = { -1,1,0,0 };
	int dj[4] = { 0,0,-1,1 };

	while (!q.empty()) {
		int i, j;
		i = q.front().first;
		j = q.front().second;
		q.pop();

		if (i == ti && j == tj) return true;

		for (int d = 0; d < 4; d++) {
			int ni = i + di[d];
			int nj = j + dj[d];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
			if (B[ni][nj] == 'T') continue; // 木は通れない
			if (dist[ni][nj] != -1) continue;

			dist[ni][nj] = dist[i][j] + 1;
			q.push({ ni,nj });
		}
	}

	return false;
}


int main() {

	long long Count = 0;
	cin >> N >> ti >> tj;

	vector<string> B(N);

	vector<vector<int>> V(N,vector<int>(N, -1));

	for (int i = 0; i < N; i++) {

		cin >> B[i];

	}

	int pi = 0, pj = N/2;

	while (true) {

		if (Count == 0) {
			Count++;
			vector<pair<int, int>> D;

			

			if (ti > 0) {
				if (B[ti - 1][tj] != 'T' && V[ti - 1][tj] == -1) {
					B[ti - 1][tj] = 'T';
					D.push_back({ti-1,tj});
				}
			}

			if (ti < N - 1) {
				if (B[ti + 1][tj] != 'T' && V[ti + 1][tj] == -1) {
					B[ti + 1][tj] = 'T';
					D.push_back({ ti +1,tj });
				}
			}

			if (tj > 0) {
				if (B[ti][tj - 1] != 'T' && V[ti][tj - 1] == -1) {
					B[ti][tj - 1] = 'T';
					D.push_back({ ti ,tj-1 });
				}
			}

			if (tj < N - 1) {
				if (B[ti][tj + 1] != 'T' && V[ti][tj + 1] == -1) {
					B[ti][tj + 1] = 'T';
					D.push_back({ ti ,tj+1 });
				}
			}

			if (D.size() != 0) {

				vector<pair<int, int>> TREE;
				int TotalTree = 0;

				for (int i = 0; i < D.size(); i++) {

					//B[D[i].first][D[i].second] = '.';

					if (reachable(pi, pj, D[i].first, D[i].second, B)) {
						
						TREE.push_back({D[i].first,D[i].second});
						//TotalTree++;
						continue;
					}
					else {
						B[D[i].first][D[i].second] = '.'; // 戻す
					}
				}

				cout << TREE.size();
				for (int i = 0; i < TREE.size(); i++) {
					cout << TREE[i].first << " " << TREE[i].second << " ";
				}
				cout << endl;
				continue;
			}
		}

		int pi, pj;
		if (!(cin >> pi >> pj)) break;

		if (pi == ti && pj == tj) {

			return 0;
		}

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {

			int x,y;

			cin >> x >> y;

			V[x][y] = 0;//訪問済み

		}

		cout << "0" << endl;
		
	}

	return 0;

}