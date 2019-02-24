#include<stdio.h>
#include<algorithm>
using namespace std;
struct user {
	int id, score[6] = { 0 };
	int submit[6] = { 0 };//submit[0]代表AC的个数
	bool flag = 0;
	int rank;
}input[100011];
bool cmp(user A, user B) {
	if (A.flag != B.flag) return A.flag > B.flag;
	else if (A.score[0] != B.score[0]) return A.score[0] > B.score[0];
	else if (A.submit[0] != B.submit[0]) return A.submit[0] > B.submit[0];
	else return A.id < B.id;
}
int main() {
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	int pro_score[6];
	for (int i = 1; i <= K; i++) scanf("%d", &pro_score[i]);
	for (int i = 0; i < M; i++) {
		int id, pro_num, score;
		scanf("%d %d %d", &id, &pro_num, &score);
		input[id].id = id;
		input[id].submit[pro_num] = 1;
		if (score >= 0) {
			input[id].flag = 1;
			int pri_score = input[id].score[pro_num];
			if (score >= pri_score) {
				input[id].score[pro_num] = score;
				input[id].score[0] += score - pri_score;
				if (pri_score != pro_score[pro_num] && score == pro_score[pro_num]) {
					input[id].submit[0]++;
				}
			}
		}
	}
	sort(input, input + N+1, cmp);
	input[0].rank = 1;
	for (int i = 0; i < N; i++) {
		if (input[i].flag == 0) break;
		if (i == 0) printf("1");
		else if (input[i].score[0] == input[i - 1].score[0]) {
			printf("%d", input[i - 1].rank);
			input[i].rank = input[i - 1].rank;
		}
		else {
			printf("%d", i + 1);
			input[i].rank = i + 1;
		}
		printf(" %05d %d", input[i].id,input[i].score[0]);
		for (int j = 1; j <= K; j++) {
			if (input[i].submit[j] == 0) printf(" -");
			else printf(" %d", input[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}