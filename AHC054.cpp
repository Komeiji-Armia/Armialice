#include <bits/stdc++.h>
using namespace std;

/*
* N×N マスの森がある。左上のマスの座標を(0,0)とし、下方向にi、右方向にjマス進んだ位置の座標を(i,j) とする。
* 
* 花:プログラム全体としてたどり着くべき目的地
* 目的地:標準入力で与えられる暫定の目的地
* 木:Stringで'T'として与えられる。障害物。確認は出来る、暫定の目的地(qi,qj)になりうる。BFSで通過は出来ない。
* 
while(ture){

1:現在位置 に花がある場合、目的を達成し行動を終了する。(return 0)

2:上下左右それぞれの方向に対し、現在位置からその方向に進んだ最初の「T」のマスまで（そのTのマスを含む）のすべての未確認マスを 確認済みマス に追加する。(ビームサーチ)

3:花(Ti,Tj)が確認済みマスに含まれている場合、目的地をそのマスに設定する。(qi = ti,qj=tj)

4:目的地が未定でなく、暫定地図 において目的地が現在位置から空きマスのみを通って到達不能な場合、目的地を未定に戻す。(bfsのルート確認,dist[qi][qj] == -1 continur;)

5:目的地が未定であるか、伝説の花以外の確認済みマスにある場合、暫定地図において、現在位置から空きマスのみを通って到達可能な未確認マスの中から次のqi,qjの入力を受け取り、それを 目的地 に設定する（そのようなマスが存在しない場合、WAとなる）。

6:暫定地図において、各マスから空きマスのみを通って 目的地へ到達する最短距離を計算する。現在位置に隣接する空きマスのうち、目的地までの最短距離がより短くなるマスに1マスだけ移動する。そのようなマスが複数ある場合、上下左右(重要)の順に優先度をつけ、先に挙げられた方向を選択する。

}

*/

//方針はBFSを目的地変更の時に実施(TLE対策)。毎ターンビームサーチして花が見つかれば目的地を変更し、目的地に向かって1マス移動。移動方向は出力しない(デバイス用のcout)。ターン毎に0を出力する。


vector<vector<int>> bfs(const vector<string>& B, int gi, int gj) {

	int N = B.size();

	vector<vector<int>> dist(N, vector<int>(N, -1));
	if (gi < 0 || gj < 0 || gi >= N || gj >= N) return dist;
	if (B[gi][gj] == 'T') return dist;//目的地が木かつサーチ済みなら次の目的地に変更


	queue<pair<int, int>> q;

	dist[gi][gj] = 0; //与えられたマスは探索ずみ
	q.push({ gi, gj });//キューに入れる

	//UDLR
	int di[4] = { -1,1,0,0 };
	int dj[4] = { 0,0,1,-1 };

	while (!q.empty()) {

		auto p = q.front(); q.pop();
		int i = p.first, j = p.second;

		for (int d = 0; d < 4; d++) {

			int ni = i + di[d], nj = j + dj[d];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;//範囲外

			if (dist[ni][nj] != -1) continue;//探索済み

			if (B[ni][nj] == 'T') continue; // 木は通れない
			dist[ni][nj] = dist[i][j] + 1;//距離探索
			q.push({ ni, nj });//再度探索の準備
		}
	}
	return dist;
}


int main() {

	int N, ti, tj,Flag = -1;
	cin >> N >> ti >> tj;

	vector<string> B(N);
	vector<vector<int>> V(N, vector<int>(N, -1));//未確認マス

	for (int i = 0; i < N; i++) {

		cin >> B[i];

	}
	
	int Nowi = 0, Nowj = N / 2;

	for (int i = 0; i < (N * N) - 1; i++) {

		int qi, qj;

		cin >> qi >> qj;

		vector<vector<int>> dist; // 現在の距離マップ
		int curGoalI = -1, curGoalJ = -1; // 現在の目的地

		dist = bfs(B, qi, qj);

		if (dist[Nowi][Nowj] == -1){
			continue;//次の
		}

		while (true) {//毎ターンの処理

			if (Nowi == ti && Nowj == tj) {
				cout << "0" << endl;
				return 0;
			}

			//if (V[qi][qj] == 0) {
				//cout << "break" << endl;
				//break;
			//}//目標地点が見つかれば次の目標地点に変更
			//qi,qjを変更しても探索済みならbreakしてた。花なら到達しなければならない。比較用のBefore変数。多分Flagでいい。

			for (int i = Nowi; i >= 0; i--) {

				V[i][Nowj] = 0;//探索済み

				if (i == ti && Nowj == tj) {//花が見つかれば目標地点を変更
					qi = ti;
					qj = tj;
					Flag = 0;
					//cout << "C" << endl;
				}

				if (B[i][Nowj] == 'T') {//木のマスも探索済み扱いにする
					break;
				}
			}

			for (int i = Nowi; i < N; i++) {

				V[i][Nowj] = 0;

				if (i == ti && Nowj == tj) {
					qi = ti;
					qj = tj;
					Flag = 0;
					//cout << "C" << endl;
				}

				if (B[i][Nowj] == 'T') {
					break;
				}

			}

			for (int j = Nowj; j >= 0; j--) {

				V[Nowi][j] = 0;

				if (Nowi == ti && j == tj) {
					qi = ti;
					qj = tj;
					Flag = 0;
					//cout << "C" << endl;
				}

				if (B[Nowi][j] == 'T') {
					break;
				}
			}

			for (int j = Nowj; j < N; j++) {

				V[Nowi][j] = 0;

				if (Nowi == ti && j == tj) {
					qi = ti;
					qj = tj;
					Flag = 0;
					//cout << "C" << endl;
				}

				if (B[Nowi][j] == 'T') {
					break;
				}

			}

			if (Flag == 0) {
				dist = bfs(B, ti, tj);
			}

			if (dist[Nowi][Nowj] == -1) break;

			// 現在位置の距離
			int curd = dist[Nowi][Nowj];

			// U/D/L/R の優先順で、隣接マスのうち dist がより小さいマスを選ぶ
			bool moved = false;

			// UDLR
			int di[4] = { -1, 1, 0, 0 };
			int dj[4] = { 0, 0, -1, 1 };

			for (int d = 0; d < 4; d++) {
				int ni = Nowi + di[d];
				int nj = Nowj + dj[d];
				if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
				if (dist[ni][nj] == dist[Nowi][Nowj] - 1) {
					Nowi = ni;
					Nowj = nj;
					moved = true;

					//if (d == 0) cout << 'U';
					//if (d == 1) cout << 'D';
					//if (d == 2) cout << 'L';
					//if (d == 3) cout << 'R';

					break; // UDLR の順番を優先
				}
			}

			if (!moved) {
				// 隣接で距離が小さくなるマスが無い（袋小路等）。目的地リセットして抜ける。
				break;
			}


			//cout <<qi << " " << qj << " " << Nowi << " " << Nowj << " " << "0" << endl;
			cout << "0" << endl;

		}

	}

	return 0;

}