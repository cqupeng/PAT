#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX  100000000
using namespace std;
int sum[100010];
int main(){
	int N, pay;
	scanf("%d%d", &N, &pay);
	sum[0] = 0;
	for (int i = 1; i < N + 1; i++){
		int temp;
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;
	}
	int mininum = MAX;
	vector<int> min;
	for (int i = 0; i < N + 1; i++){
		int j = lower_bound(sum + i, sum + N, pay + sum[i]) - sum;
		int temp = sum[j] - sum[i];
		if (j != N + 1 && temp >= pay && temp <= mininum){
			if (temp < mininum){
				min.clear();
				mininum = temp;
			}
			min.push_back(i + 1);
			min.push_back(j);
		}
	}
	int len = min.size();
	for (int i = 0; i < len; i++){
		printf("%d-%d\n", min[i++], min[i]);
	}
	return 0;
}