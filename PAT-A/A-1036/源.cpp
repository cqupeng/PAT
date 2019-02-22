#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct student {
	string name, gender, ID;
	int grade;
};
bool cmp(student A, student B) {
	if (A.gender != B.gender) return A.gender > B.gender;
	else return A.grade < B.grade;
}
int main() {
	vector<student> input;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		student temp;
		cin >> temp.name >> temp.gender >> temp.ID >> temp.grade;
		input.push_back(temp);
	}
	sort(input.begin(), input.end(), cmp);
	int flag = 1;
	if (input[N - 1].gender != "F") {
		printf("Absent\n");
		flag = 0;
	}
	else printf("%s %s\n", input[N - 1].name.c_str(), input[N - 1].ID.c_str());
	if (input[0].gender != "M") {
		printf("Absent\n");
		flag = 0;
	}
	else printf("%s %s\n", input[0].name.c_str(), input[0].ID.c_str());
	if (flag == 0) printf("NA");
	else printf("%d", input[N - 1].grade - input[0].grade);
	return 0;
}