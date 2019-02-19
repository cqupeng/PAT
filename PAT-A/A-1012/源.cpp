#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
	string id;
	int score[4];
	int bestrank = 2222, bestcourse;
};
int flag;
bool cmp(info stuA, info stuB) {
	return stuA.score[flag] > stuB.score[flag];
}
int main() {
	int N, M;
	cin >> N >> M;
	map<string, info> student;
	vector<info> scorerank;
	char course[5] = { 'A','C','M','E' };//按照优先级进行存储
	for (int i = 0; i < N; i++) {
		info temp_student;
		cin >> temp_student.id;
		int sum = 0, temp_score;
		for (int j = 1; j <= 3; j++) {
			cin >> temp_score;
			sum += temp_score;
			temp_student.score[j] = temp_score;
		}
		temp_student.score[0] = sum / 3;
		student[temp_student.id] = temp_student;
		scorerank.push_back(temp_student);
	}
	for (int i = 0; i < 4; i++) {
		flag = i;
		sort(scorerank.begin(), scorerank.end(), cmp);
		int prerank=1;
		for (int j = 0; j < N;j++) {
			int temprank;
			if (j == 0) temprank = 1;
			else if(scorerank[j].score[i]==scorerank[j-1].score[i]) temprank = prerank;
			else {
				temprank = j+1;
				prerank = temprank;
			}
			//更新最佳排名，由于数组的顺序为ACME，所以用小于号即可确保优先级。
			if (temprank < student[scorerank[j].id].bestrank) {
				student[scorerank[j].id].bestrank = temprank;
				student[scorerank[j].id].bestcourse = i;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		string checkid;
		cin >> checkid;
		if (student.find(checkid)==student.end()) cout << "N/A"<<endl;
		else cout << student[checkid].bestrank << ' ' << course[student[checkid].bestcourse] << endl;
	}
	return 0;
}