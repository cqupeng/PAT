#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
struct node {
	double value;
	vector<int> next;
};
int N;
double p, r;
node input[100011];
double sum = 0;
void DFS(int root,int deep) {
	if (input[root].next.size() == 0) {
		sum += input[root].value*pow(r / 100 + 1, deep)*p;
		return;
	}
	for (auto it = input[root].next.begin(); it != input[root].next.end(); it++) {
		DFS(*it, deep + 1);
	}
	return;
}
int main(){
	scanf("%d %lf %lf", &N, &p, &r);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			scanf("%lf", &input[i].value);
		}
		else {
			for (int j = 0; j < num; j++) {
				int child;
				scanf("%d", &child);
				input[i].next.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f", sum);
	return 0;
}