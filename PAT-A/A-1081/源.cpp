#include<stdio.h>
struct num {
	long long child, mother;
};
long long gcd(long long  a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
void toSimply(num &A) {
	if (A.child == 0) return;
	long long temp = gcd(A.child, A.mother);
	A.child /= temp;
	A.mother /= temp;
}
num add(num A, num B) {
	num temp;
	if (A.child == 0 && B.child != 0) return B;
	else if (B.child == 0 && A.child != 0) return A;
	long long minmother = A.mother / gcd(A.mother, B.mother)*B.mother;
	temp.mother = minmother;
	temp.child = A.child*(minmother / A.mother) + B.child*(minmother / B.mother);
	toSimply(temp);
	return temp;
}
int main() {
	int N;
	scanf("%d", &N);
	num sum;
	for (int i = 0; i < N; i++) {
		num input;
		scanf("%lld/%lld", &input.child, &input.mother);
		toSimply(input);
		if (i == 0) sum = input;
		else sum = add(sum, input);
	}
	if (sum.child == 0) printf("0\n");
	else {
		if (sum.mother == 1) printf("%lld", sum.child);
		else {
			if (sum.child / sum.mother != 0) printf("%lld ", sum.child / sum.mother);
			printf("%lld/%lld", sum.child%sum.mother, sum.mother);
		}
	}
	return 0;
}