#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, Q, ANS = 0, Count;
	cin >> N >> Q;

	vector<int> A(Q), V(N, 0); //0 = White,1 = Black;

	if (N == 1) {


		for (int i = 0; i < Q; i++) {

			cin >> A[i];
			A[i]--;
			if (V[A[i]] == 0) {
				V[A[i]] = 1;
				ANS++;
			}
			else {
				V[A[i]] = 0;
				ANS--;
			}

			cout << ANS << endl;
		}

		return 0;
	}

	if (N == 2) {


		for (int i = 0; i < Q; i++) {

			cin >> A[i];
			A[i]--;
			if (V[A[i]] == 0) {
				V[A[i]] = 1;

			}
			else {
				V[A[i]] = 0;
			}

			if (V[0] == 0 && V[1] == 1 || V[0] == 1 && V[1] == 0) {
				ANS = 1;
			}

			if (V[0] == 0 && V[1] == 0) {
				ANS = 0;
			}

			cout << ANS << endl;
		}

		return 0;
	}

	for (int i = 0; i < Q; i++) {

		cin >> A[i];
		A[i]--;
		if (V[A[i]] == 0) V[A[i]] = 1;

		else V[A[i]] = 0;

		if (A[i] >= 1 && A[i] < N - 1) {
	
			if (V[A[i] - 1] == 0 && V[A[i] + 1] == 0 && V[A[i]] == 1) {//WBW
				ANS++;
			}

			if (V[A[i] - 1] == 1 && V[A[i] + 1] == 1 && V[A[i]] == 0) {//BWB
				ANS++;
			}

			if (V[A[i] - 1] == 1 && V[A[i] + 1] == 1 && V[A[i]] == 1) {//WWW
				ANS--;
			}

			if (V[A[i] - 1] == 0 && V[A[i] + 1] == 0 && V[A[i]] == 0) {//WBW
				ANS--;
			}

		}

		else if (A[i] == 0) {

			if (V[A[i] + 1] == 0 && V[A[i]] == 1) {//WW,BW
				ANS++;
			}

			if (V[A[i] + 1] == 0 && V[A[i]] == 0) {//BW,WW
				ANS--;
			}
		}

		else {

			if (V[A[i] - 1] == 0 && V[A[i]] == 1) {//WW,WB
				ANS++;
			}

			if (V[A[i] - 1] == 0 && V[A[i]] == 0) {//WB,WW
				ANS--;
			}
		}

		cout << ANS << endl;

		//for (int j = 0; j < V.size(); j++) {
			//cout << V[j];
		//}

		//cout << endl;
	}

	return 0;

}