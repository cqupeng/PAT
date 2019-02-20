#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N, B;
	cin >> N >> B;
	vector<int> result;
	while (N) {
		result.push_back(N%B);
		N /= B;
	}
	vector<int> reverse_result=result;
	reverse(result.begin(), result.end());
	if (result == reverse_result) cout << "Yes" << endl;
	else cout << "No" << endl;
	for (auto it = result.begin(); it != result.end(); it++) {
		if (it != result.begin()) cout << ' ';
		cout << *it;
	}
	return 0;
}