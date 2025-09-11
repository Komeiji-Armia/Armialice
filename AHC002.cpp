#include <bits/stdc++.h>
using namespace std;
// 2025/07/17 Score:178,985 921位相当

int main() {

	int Si, Sj;
	cin >> Sj >> Si;

	Si, Sj;

	string ANS;

	vector<vector<int>> T(50,vector<int>(50)),P(50, vector<int>(50)), C(50, vector<int>(50,0));
	
	for (int i = 0; i < 50; i++) {

		for (int j = 0; j < 50; j++) {

			cin >> T[i][j];

		}


	}

	for (int i = 0; i < 50; i++) {

		for (int j = 0; j < 50; j++) {

			cin >> P[i][j];

		}


	}

	for (int i = 0; i < 1000; i++) {

		int Check = -1;

		C[Sj][Si] = -1;

		//訪問済みチェック
		if (Si > 0 && T[Sj][Si - 1] == T[Sj][Si] && C[Sj][Si - 1] != -1) {
			C[Sj][Si - 1] = -1;
			//cout << "R";
		}

		if (Sj > 0 && T[Sj-1][Si] == T[Sj][Si] && C[Sj - 1][Si] != -1) {
			C[Sj-1][Si] = -1;
			//cout << "U";
		}

		if (Si < 49 && T[Sj][Si + 1] == T[Sj][Si] && C[Sj][Si + 1] != -1) {
			C[Sj][Si + 1] = -1;
			//cout << "L";
		}

		if (Sj < 49 && T[Sj + 1][Si] == T[Sj][Si] && C[Sj + 1][Si] != -1) {
			C[Sj + 1][Si] = -1;
			//cout << "D";
		}
		//4方向

		int Point = -1;

		if (Si > 0 && C[Sj][Si - 1] != -1) {
			Point = max(Point,P[Sj][Si-1]);

		}

		if (Sj > 0 && C[Sj - 1][Si] != -1) {
			Point = max(Point, P[Sj-1][Si]);

		}

		if (Si < 49 && C[Sj][Si + 1] != -1) {
			Point = max(Point, P[Sj][Si + 1]);

		}

		if (Sj < 49 && C[Sj + 1][Si] != -1) {
			Point = max(Point, P[Sj + 1][Si]);

		}

		//cout << i << " " << P[Sj][Si] << endl;

		if (Point == -1) {
			cout << ANS << endl;
			return 0;
		}

		

		if (Sj > 0 && C[Sj - 1][Si] != -1 && P[Sj - 1][Si] == Point) {
			Sj--;
			ANS += 'U';
			continue;
		}

		if (Si > 0 && C[Sj][Si - 1] != -1 && P[Sj][Si - 1] == Point) {

			Si--;
			ANS += 'L';
			continue;
		}

		if (Si < 49 && C[Sj][Si + 1] != -1 && P[Sj][Si + 1] == Point) {
			Si++;
			ANS += 'R';
			continue;
		}

		if (Sj < 49 && C[Sj + 1][Si] != -1 && P[Sj + 1][Si] == Point) {
			Sj++;
			ANS += 'D';
			continue;
		}


	}


	return 0;

}