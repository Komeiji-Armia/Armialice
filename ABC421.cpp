#include <bits/stdc++.h>
using namespace std;

int main() {

	int N;
	cin >> N;

	string S;
	cin >> S;

	vector<int> B(N);

	int j = 0;
	for (int i = 0; i < 2 * N; i++) {

		if (S[i] == 'B') {
			B[j] = i;
			j++;
		}

	}

	long long ANS1=0, ANS2=0;

	for (int i = 0; i < N; i++) {
		ANS1 += abs(((2*i)+1)-B[i]);//ABパターン
		ANS2 += abs(((2*i))-B[i]);//BAパターン

		//cout << abs(((2 * i) + 1) - B[i]) << " " << abs(((2 * i)) - B[i]) << endl;
	}

	cout << min(ANS1,ANS2) << endl;

	return 0;

}