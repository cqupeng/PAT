#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 222;
bool input[maxn][maxn] = { 0 };
bool record[maxn] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	int Nv, Ne;
	cin >> Nv >> Ne;
	for (int i = 0; i < Ne; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		input[v1][v2] = input[v2][v1] = 1;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		vector<int> test;
		fill(record, record + maxn, 0);
		for (int j = 0; j < K; j++) {
			int temp;
			cin >> temp;
			test.push_back(temp);
			record[temp] = 1;
		}
		int flag = 1;
		for (int j = 0; j < K; j++) {
			for (int k = j + 1; k < K&&flag; k++) {
				if (input[test[j]][test[k]] == 0) flag = 0;
			}
		}
		if (flag == 0) cout << "Not a Clique" << '\n';
		else {
			for (int j = 1; j <= Nv&&flag; j++) {
				if (record[maxn] == 0) {
					bool maxflag = 1;
					for (int k = 0; k < K&&maxflag; k++) {
						if (input[test[k]][j] == 0) maxflag = 0;
					}
					if (maxflag == 1) flag = 0;
				}
			}
			if (flag == 0) cout << "Not Maximal\n" ;
			else cout << "Yes\n";
		}
	}
	return 0;
}