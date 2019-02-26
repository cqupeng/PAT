#include<stdio.h>

long long gcd(long long  a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
struct num {
	long long child, mother;
};
void to_simply(num &A) {
	long long temp = gcd(A.mother, A.child);
	A.mother = A.mother / temp;
	A.child = A.child / temp;
	if (A.mother < 0) {
		A.mother *= -1;
		A.child *= -1;
	}
}
void Pri(num &A) {
	to_simply(A);
	int flag = 0;
	if (A.child < 0) {
		putchar('(');
		flag = 1;
	}
	if (A.child == 0) printf("0");
	else {
		if (A.mother == 1) printf("%lld", A.child);
		else {
			if (A.child < 0) {
				putchar('-');
				A.child *= -1;
			}
			if (A.child / A.mother!=0) printf("%lld ", A.child / A.mother);
			printf("%lld/%lld", A.child%A.mother,A.mother);
		}
	}
	if (flag) putchar(')');
}
int main() {
	num input1, input2;
	scanf("%lld/%lld %lld/%lld", &input1.child, &input1.mother, &input2.child, &input2.mother);
	Pri(input1);
	printf(" + ");
	Pri(input2);
	printf(" = ");
	long long temp = gcd(input1.mother, input2.mother);
	long long newmother = input1.mother / temp * input2.mother;
	num C;
	C.child = input1.child*newmother/input1.mother + input2.child*newmother/input2.mother;
	C.mother = newmother;
	Pri(C);
	putchar('\n');
	Pri(input1);
	printf(" - ");
	Pri(input2);
	printf(" = ");
	C.child = input1.child*newmother / input1.mother - input2.child*newmother / input2.mother;
	Pri(C);
	putchar('\n');
	Pri(input1);
	printf(" * ");
	Pri(input2);
	printf(" = ");
	C.child = input1.child*input2.child;
	C.mother = input1.mother*input2.mother;
	Pri(C);
	putchar('\n');
	Pri(input1);
	printf(" / ");
	Pri(input2);
	printf(" = ");
	if (input2.child == 0) printf("Inf");
	else {
		C.child = input1.child*input2.mother;
		C.mother = input1.mother*input2.child;
		Pri(C);
	}
	return 0;

}