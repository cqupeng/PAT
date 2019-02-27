#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
vector<int>ans, temp, fac;
int N, K, P, maxfacsum = -1;
void   Fac(){
	for (int i = 0; i <= N; i++){
		int sum = pow(i, P);
		if (sum <= N) fac.push_back(sum);
		else break;
	}
}
void DFS(int index, int nowk, int sum, int facsum){
	if (nowk == K && sum == N){
		if (facsum > maxfacsum){
			ans = temp;
			maxfacsum = facsum;
		}
		return;
	}
	if (nowk > K || sum > N) return;
	if (index > 0){
		temp.push_back(index);
		DFS(index, nowk + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		DFS(index - 1, nowk, sum, facsum);
	}
}
int main(){
	scanf("%d%d%d", &N, &K, &P);
	Fac();
	DFS(fac.size() - 1, 0, 0, 0);
	if (ans.size() != 0){
		printf("%d = ", N);;
		for (int i = 0; i < K; i++){
			printf("%d^%d", ans[i], P);
			if (i != K - 1) printf(" + ");
		}
	}
	else printf("Impossible");
	return 0;
}