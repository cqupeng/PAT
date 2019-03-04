#include<stdio.h>
#include<unordered_map>
using namespace std;
struct student {
	int rank, flag = -1;
};
bool isprime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int N;
	scanf("%d", &N);
	unordered_map<int, student> rank;
	for (int i = 1; i <= N; i++) {
		int id;
		scanf("%d", &id);
		rank[id].rank = i;
		rank[id].flag = 0;
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int id;
		scanf("%d", &id);
		printf("%04d: ", id);
		if (rank[id].flag == -1) printf("Are you kidding?\n");
		else if (rank[id].flag == 1) printf("Checked\n");
		else {
			if (rank[id].rank == 1) printf("Mystery Award\n");
			else if (isprime(rank[id].rank)) printf("Minion\n");
			else printf("Chocolate\n");
			rank[id].flag = 1;
		}
	}
	return 0;
}