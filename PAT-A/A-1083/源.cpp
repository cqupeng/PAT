#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct student {
	string name, id;
	int score;
	friend bool operator < (student A, student B) {
		return A.score > B.score;
	}
}input[111];
int main() {
	int N;
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i].name >> input[i].id >> input[i].score;
	}
	sort(input, input + N);
	int grade1, grade2, flag = 0;
	cin >> grade1 >> grade2;
	for (int i = 0; i < N; i++) {
		if (input[i].score <= grade2 && input[i].score >= grade1) {
			flag = 1;
			cout << input[i].name << ' ' << input[i].id<<'\n';
		}
		else if (flag == 1) break;
	}
	if (flag == 0) cout << "NONE";
	return 0;
}