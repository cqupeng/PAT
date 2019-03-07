#include<stdio.h>
bool isprime(int test) {
	if (test < 2) return false;
	for (int i = 2; i*i <= test; i++) {
		if (test%i == 0) return false;
	}
	return true;
}
int hashTable[10011] = { 0 };
int main() {
	int Msize, N, M;
	scanf("%d %d %d", &Msize, &N, &M);
	while (isprime(Msize) == false) Msize++;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < Msize; j++) {
			if (hashTable[(temp+j*j)%Msize] == 0) {
				hashTable[(temp+j*j)%Msize] = temp;
				break;
			}
			else if (j == Msize - 1) printf("%d cannot be inserted.\n", temp);
		}
	}
	int sum = 0;
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j <= Msize; j++) {
			sum++;
			if (hashTable[(temp + j * j) % Msize] == temp||hashTable[(temp + j * j) % Msize] == 0) 
				break;
		}
	}
	printf("%.1f", (double)sum / M);
	return 0;
}