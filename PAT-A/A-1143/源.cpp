#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<int, bool> record;
int main() {
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;
	vector<int> input;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
		record[temp] = 1;
	}
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		if (record[c1] == 0 && record[c2] == 0) {
			cout << "ERROR: " << c1 << " and " << c2 << " are not found.\n";
		}
		else if (record[c1] == 0) cout << "ERROR: " << c1 << " is not found.\n";
		else if (record[c2] == 0) cout << "ERROR: " << c2 << " is not found.\n";
		else {
			int v = 0x3f3f3f3f;
			int flag = 0;
			for (int j = 0; j < N; j++) {
				if (input[j] > min(c1, c2) && input[j] < max(c1, c2)) {
					v = input[j];
					flag = 1;
					break;
				}
				else if (input[j] == c1 || input[j] == c2) {
					if (flag) break;
					v = input[j];
					break;
				}
			}
			if (flag == 0&&v==c1) cout << v << " is an ancestor of " << c2 << ".\n";
			else if (flag == 0 && v == c2) cout << v << " is an ancestor of " << c1 << ".\n";
			else cout << "LCA of " << c1 << " and " << c2 << " is " << v << ".\n";
		}
	}
	return 0;
}