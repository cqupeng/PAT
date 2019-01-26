	#include<iostream>
	#include<map>
	using namespace std;

	int main() {
		map<int, double> input;
		int n1, n2,num=0;
		cin >> n1;
		int exp;
		double coe;
		for (int i = 0; i < n1; i++) {
			cin >> exp >> coe;
			exp *= -1;
			input[exp] += coe;
			if (coe != 0) num++;
		}
		cin >> n2;
		for (int i = 0; i < n2; i++) {
			cin >> exp >> coe;
			exp *= -1;
			if (input[exp] == 0.0&&coe!=0.0) num++;
			input[exp] += coe;
			if (input[exp] == 0) num--;
		}
		if (input.size() == 1 && input.begin()->second == 0) printf("0");
		else {
			cout << num;
			for (auto it = input.begin(); it != input.end(); it++) {
				if(it->second!=0) printf(" %d %.1f", it->first*-1, it->second);
			}
		}
		return 0;
	}