#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, Q;
	cin >> N >> Q;

	vector<long long> A(N), B(N);

	for (int i = 0; i < N; i++) {

		cin >> A[i];

	}

	for (int i = 0; i < N; i++) {

		cin >> B[i];

	}

	long long Sum = 0;

	for (int i = 0; i < N; i++) {

		Sum += min(A[i], B[i]);

	}

	//cout << Sum << endl;

	for (int i = 0; i < Q; i++) {

		char C;
		long long X, V;
		
		cin >> C;
		cin >> X >> V;

		long long num1 = min(A[X - 1], B[X - 1]);

		if (C == 'A') {
			A[X - 1] = V;
		}

		else {
			B[X - 1] = V;
		}

		long long num2 = min(A[X-1], B[X-1]);
		
		//cout << num <<  " " ;

		Sum += (num2 - num1);

		cout << Sum << endl;
	}

}