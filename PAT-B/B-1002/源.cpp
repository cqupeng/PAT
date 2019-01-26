#include<iostream>
#include<string>
using namespace std;
int main() {
	string name[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string input;
	getline(cin, input);
	int sum = 0;
	for (auto it = input.begin(); it != input.end(); it++) {
		sum += *it - '0';
	}
	string output = to_string(sum);
	for (auto it = output.begin(); it != output.end(); it++) {
		if (it != output.begin()) printf(" ");
		printf("%s", name[*it - '0'].c_str());
	}
	return 0;
}