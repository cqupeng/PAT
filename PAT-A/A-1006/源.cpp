#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct record {
	string id, in, out;
};
bool cmp_earliest(record A, record B) {
	return A.in < B.in;
}
bool cmp_lastest(record A, record B) {
	return A.out > B.out;
}
int main() {
	int N;
	cin >> N;
	vector<record> input;
	for (int i = 0; i < N; i++) {
		record temp_re;
		cin >> temp_re.id >> temp_re.in >> temp_re.out;
		input.push_back(temp_re);
	}
	sort(input.begin(), input.end(), cmp_earliest);
	cout << input.begin()->id<<' ';
	sort(input.begin(), input.end(), cmp_lastest);
	cout << input.begin()->id;
	return 0;
}