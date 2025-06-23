#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, Q;
	cin >> N >> Q;

	vector<int> A(N);
	
	for (int i = 0; i < N; i++) {

		A[i] = i + 1;

	}

	int Y=0;

	for (int i = 0; i < Q; i++) {


		int num;

		cin >> num;

		if (num == 1) {

			int P, X;
			cin >> P >> X;

			A[((P+Y-1)%N)] = X;

		}

		else if (num == 2) {

			int P;
			cin >> P;

			cout << A[((P + Y - 1) % N)] << endl;

		}

		else {

			int K;
			cin >> K;

			Y += (K % N);
			Y %= N;

		}

	}

	return 0;
}