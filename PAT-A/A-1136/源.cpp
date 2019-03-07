#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string  a, string b) {
	int lena = a.size();
	int lenb = b.size();
	int i = 0, j = 0, r = 0;
	string c;
	while (i < lena&&j < lenb) {
		int temp = a[i++] + b[j++] - 2 * '0';
		c.push_back((temp + r) % 10+'0');
		r = (temp + r) / 10;
	}
	if (r != 0) c.push_back(r + '0');
	return c;
}
int main() {
	string A;
	cin >> A;
	int k = 0;
	int flag = 0;
	while (k < 10) {
		string B = A;
		reverse(B.begin(), B.end());
		if (A == B) {
			cout << A << " is a palindromic number." << '\n';
			flag = 1;
			break;
		}
		else {
			string C = add(A, B);
			reverse(C.begin(), C.end());
			cout << A << " + " << B << " = " << C << '\n';
			A = C;
		}
		k++;
	}
	if (k == 10 && flag == 0) cout << "Not found in 10 iterations.";
	return 0;
}
