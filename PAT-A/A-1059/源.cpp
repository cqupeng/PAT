#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define Maxn 10000
bool isPri[Maxn];
void FindPri() {
	fill(isPri, isPri + Maxn, true);
	for (int i = 2; i < Maxn; i++) {
		if (isPri[i] == true) {
			for (int j = 2; i*j < Maxn; j++) {
				isPri[i*j] = 0;
			}
		}
	}
}
int main() {
	int N;
	map<int, int> fac;
	scanf("%d", &N);
	printf("%d=", N);
	FindPri();
	if (N == 1) printf("1");
	for (int i = 2; i <= N; i++) {
		while (isPri[i] && N % i == 0) {
			fac[i]++;
			N /= i;
		}
	}
	for (auto it = fac.begin(); it != fac.end(); it++) {
		if (it != fac.begin()) printf("*");
		if (it->second > 1) printf("%d^%d", it->first, it->second);
		else printf("%d", it->first);
	}
	return 0;
}