#include<iostream>
#include<string>
using namespace std;
int main()
{
	int A, B;
	char C[10];
	cin >> A >> B;
	A = A + B;
	if (A == 0) putchar('0');
	else if (A < 0) {
		putchar('-');
		A *= -1;
	}
	string output;
	int j = 0;
	while (A != 0) {
		output.insert(output.begin(), A % 10 + '0');
		if (j != 0 && j % 3 == 0) output.insert(++output.begin(), ',');
		j++;
		A /= 10;
	}
	cout << output;
	return 0;
}