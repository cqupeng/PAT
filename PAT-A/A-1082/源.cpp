#include<iostream>
#include<string>
using namespace std;
int main() {
	int input;
	cin >> input;
	char num[10][6] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	char pos[10][6] = { "Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi" };
	if (input == 0) printf("ling"); 
	else {
		if (input < 0) {
			printf("Fu ");
			input *= -1;
		}
		string str = to_string(input);
		while (str.size() < 9) str.insert(str.begin(), '0');
		int flag = 0;
		for (int i = 0; i < 9; i++) {
			if (i > 0 && str[i] != '0' && str[i - 1] == '0' &&flag) {
				 printf(" ling");
			}
			if (str[i] > '0') {
				if (flag) printf(" ");
				flag = 1;
				printf("%s", num[str[i] - '0']);
				if (i!=4 && i != 8) printf(" %s", pos[i]);
			}
			if (i==4&&flag) printf(" Wan");
		}
	}
	return 0;
}