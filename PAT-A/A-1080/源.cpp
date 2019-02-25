#include<stdio.h>
#include<algorithm>
using namespace std;
struct applicant{
	int number;
	int GE, GI;
	int final = (GE + GI) / 2;
	int pre_school[5] = { -1,-1,-1,-1,-1 };
}app[40001];
bool cmp(applicant a, applicant b){
	if (a.final != b.final) return a.final > b.final;
	else if (a.GE != b.GE) return a.GE > b.GE;
	else return a.number < b.number;
}
int school[100][40001] = { 0 };
int num[100] = { 0 };
int grademin[100][2];
int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++){
		scanf("%d", &school[i][0]);
	}
	for (int i = 0; i < N; i++){
		app[i].number = i;
		scanf("%d %d", &app[i].GE, &app[i].GI);
		for (int j = 0; j < K; j++) scanf("%d", &app[i].pre_school[j]);
		app[i].final = (app[i].GE + app[i].GI) / 2;
	}
	sort(app, app + N, cmp);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			int p = app[i].pre_school[j];
			if (school[p][0] > 0){
				school[p][++num[p]] = app[i].number;
				grademin[p][0] = app[i].final;
				grademin[p][1] = app[i].GE;
				school[p][0]--;
				break;
			}
			else if (app[i].final == grademin[p][0] && app[i].GE == grademin[p][1]){
				school[p][++num[p]] = app[i].number;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++){
		int temp[40001];
		for (int j = 0; j < num[i]; j++) temp[j] = school[i][j + 1];
		sort(temp, temp + num[i]);
		for (int j = 0; j < num[i]; j++){
			printf("%d", temp[j]);
			if (j != num[i] - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}