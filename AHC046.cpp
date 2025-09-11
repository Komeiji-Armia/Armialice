#include <bits/stdc++.h>
using namespace std;
// 2025/09/11 Score:204,033 448位相当

int main() {

	int N,M;
	cin >> N >> M;

	vector<pair<int, int>> P(M);
	
	for (int i = 0; i < M; i++) {

		cin >> P[i].first >> P[i].second;

	}

	for (int i = 1; i < M; i++) {

		//直接向かった方が早いか、一度端まで飛んでからの方が早いかのチェック
		//壁は置かない

		if (abs(P[i].first - P[i - 1].first) > P[i].first) {
			cout << "S U" << endl;
			P[i - 1].first = 0;
		}

		else if (abs(P[i].first - P[i - 1].first) > abs(P[i].first-N)) {
			cout << "S D" << endl;
			P[i - 1].first = N-1;
		}

		if (abs(P[i].second - P[i - 1].second) > P[i].second) {
			cout << "S L" << endl;
			P[i - 1].second = 0;
		}

		else if (abs(P[i].second - P[i - 1].second) > abs(P[i].second - N)) {
			cout << "S R" << endl;
			P[i - 1].second = N - 1;
		}

		while (true) {//気合の1マス移動

			if (P[i].first > P[i - 1].first) {
				cout << "M D" << endl;
				P[i - 1].first++;
			}

			else if (P[i].first < P[i - 1].first) {
				cout << "M U" << endl;
				P[i - 1].first--;
			}

			if (P[i].second > P[i - 1].second) {
				cout << "M R" << endl;
				P[i - 1].second++;
			}

			else if (P[i].second < P[i - 1].second) {
				cout << "M L" << endl;
				P[i - 1].second--;
			}

			if (P[i].first == P[i - 1].first && P[i].second == P[i - 1].second) {
				break;
			}

		}

	}

	return 0;

}