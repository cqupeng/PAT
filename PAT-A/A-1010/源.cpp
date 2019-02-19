#include<iostream>
#include<cctype>
#include<string>
using namespace std;
long long to_10(string A, long long radix) {
	long long sum = 0, temp = 1;
	for (int i = A.length() - 1; i >= 0; i--) {
		if(isdigit(A[i])) sum += (A[i] - '0')*temp;
		else sum += (A[i] - 'a' + 10)*temp;
		temp *= radix;
	}
	return sum;
}
int main() {
	string N1, N2;
	int tag,given_radix;
	cin >> N1 >> N2 >> tag>>given_radix;
	if (tag == 2) {
		string temp = N1;
		N1 = N2;
		N2 = temp;
	}
	long long sumN1 = to_10(N1, given_radix);
	int flag = 1;
	int maxdigit = 0;
	for (auto it = N2.begin(); it != N2.end(); it++){
		int tempdigit;
		if (isdigit(*it)) tempdigit = *it - '0';
		else tempdigit = *it - 'a' + 10;
		maxdigit = maxdigit > tempdigit ? maxdigit : tempdigit;
	}
	long long low = maxdigit + 1, high = low > sumN1 ? low : sumN1;
	long long result_radix;
	while (low <= high&&flag) {
		long long mid = (low + high) / 2;
		int tempN2 = to_10(N2, mid);
		if (tempN2 == sumN1) {
			result_radix = mid;
			flag = 0;
		}
		else if (tempN2 > sumN1) high = mid - 1;
		else low = mid + 1;
	}
	if (flag == 1) cout << "Impossible";
	else cout << result_radix;
	return 0;
}