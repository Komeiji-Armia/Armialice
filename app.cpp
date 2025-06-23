#include <vector>
#include <string>
#include <algorithm>
#include "app.hpp"
using namespace std;

vector<string> create_solution(long long step, long long q, vector<long long> n, vector<long long> s, vector<long long> a, vector<long long> t, vector<long long> b) {
	// TODO: Implement this function

	vector<string> res;
	long long Plus = 0;

	vector<long long> Type(4);

	for (long long i = 1; i <= 3; i++) {

		Type[i] = (i % 3) + 1;//有利タイプ

	}

	for (long long z = 0; z < q; z++) {

		long long N = n[z];

		long long SIZE = 1;

		for (long long i = 1; i <= N; i++) {

			SIZE *= i;

		}

		//sort(s.begin(), s.end());

		vector<vector<long long>> X;
		vector<long long> num(N);

		for (long long i = 0; i < N; i++) {

			num[i] = i;

		}

		do {
			X.push_back(num);
		} while (next_permutation(num.begin(), num.end()));



		long long Finjudge = 1;


		for (long long i = 0; i < SIZE; i++) {

			long long judge = 1;//勝ち

			//cout << X[i].size() << endl;

			for (long long j = 0; j < N; j++) {//あとはこの行

				long long Satk, Tatk;

				if (Type[s[X[i][j] + Plus]] == t[j + Plus]) {
					Satk = a[X[i][j] + Plus] * 2;
					Tatk = b[j + Plus];
				}

				else if (Type[t[j + Plus]] == s[X[i][j] + Plus]) {
					Satk = a[X[i][j] + Plus];
					Tatk = b[j + Plus] * 2;
				}

				else {
					Satk = a[X[i][j] + Plus];
					Tatk = b[j + Plus];
				}

				//cout << Satk << " " << Tatk << " " << i << " " << j << endl;

				if (Satk <= Tatk) {
					judge = -1;
					//cout << "lose" << endl;
					break;
				}

			}

			Finjudge = judge;

			if (judge == 1) {
				res.push_back("yes");
				//cout << "Flag Y" << endl;
				break;
			}

		}

		if (Finjudge == -1) {
			res.push_back("no");
			//cout << "Flag N" << endl;
		}

		Plus += N;
		//cout << Plus << endl;
	}

	return res;

}