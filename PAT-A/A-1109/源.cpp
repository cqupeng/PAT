#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
struct student {
	string name;
	int high;
}input[10011];
bool cmp(student A, student B) {
	if (A.high != B.high)return A.high > B.high;
	else return A.name < B.name;
}
int N, K, num_row;
void pri(int left, int right) {
	deque<int> output;
	int flag = 0;
	for (int i = left; i <= right; i++) {
		if (flag == 1) {
			output.push_front(i);
			flag = 0;
		}
		else {
			output.push_back(i);
			flag = 1;
		}
	}
	while (!output.empty()) {
		cout << input[output.front()].name;
		output.pop_front();
		if (output.empty()) cout << '\n';
		else cout << ' ';
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input[i].name >> input[i].high;
	}
	sort(input, input + N, cmp);
	num_row = N / K;
	int ex_s = N-num_row*K;
	pri(0, ex_s + num_row - 1);
	for (int i = 1; i < K; i++) pri(ex_s + num_row * i, ex_s + num_row * i + num_row - 1);
	return 0;
}