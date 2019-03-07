#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cctype>
using namespace std;
struct danwei{
	string name;
	int sum;
	double grade = 0;
}input[100001];
bool cmp(danwei a, danwei b){
	if (a.grade != b.grade) return a.grade > b.grade;
	else if (a.sum != b.sum) return a.sum < b.sum;
	else return a.name < b.name;
}
int main(){
	int N;
	scanf("%d", &N);
	int n = 0;
	map<string, int> m;
	for (int i = 0; i < N; i++){
		string stu, school;
		double g;
		cin >> stu >> g >> school;
		if (stu[0] == 'B') g = g / 1.5;
		else if (stu[0] == 'T') g *= 1.5;
		for (int j = 0; j < school.length(); j++) school[j] = tolower(school[j]);
		if (m[school] == 0){
			n++;
			m[school] = n;
			input[n] = { school,1,g };
		}
		else{
			int p = m[school];
			input[p].sum++;
			input[p].grade += g;
		}
	}
	sort(input + 1, input + n + 1, cmp);
	printf("%d\n", n);
	int r = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || (int)input[i].grade != (int)input[i - 1].grade) {
			printf("%d", i);
			r = i;
		}
		else printf("%d", r);
		printf(" %s %d %d\n", input[i].name.c_str(), (int)input[i].grade, input[i].sum);
	}
	return 0;
}