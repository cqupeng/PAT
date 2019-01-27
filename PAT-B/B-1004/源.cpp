#include<iostream>
#include<string>
using namespace std;
struct student {
	int score=-1;
	string name;
	string stu_num;
}input[101];
int main() {
	int n, maxscore = -1,maxi;
	int minscore = 101, mini;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i].name >> input[i].stu_num >> input[i].score;
		if (input[i].score > maxscore) {
			maxscore = input[i].score;
			maxi = i;
		}
		if (input[i].score < minscore) {
			minscore = input[i].score;
			mini = i;
		}
	}
	cout << input[maxi].name << ' ' << input[maxi].stu_num << endl;
	cout << input[mini].name << ' ' << input[mini].stu_num << endl;
	return 0;
}