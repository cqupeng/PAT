#include<stdio.h>
#include<unordered_map>
using namespace std;
bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	unordered_map<int, bool> hash;
	while (!isPrime(N)) N++;
	for (int i = 0; i < M; i++) {
		int temp, flag = 0;
		scanf("%d", &temp);
		if (i != 0) printf(" ");
		for (int j = 0; j <= N; j++) {
			if (hash[(temp + j * j)%N] == false) {
				hash[(temp + j * j) % N] = true;
				printf("%d", (temp + j * j) % N);
				flag = 1;
				break;
			}
		}
		if(flag==false) printf("-");
	}
	return 0;
}