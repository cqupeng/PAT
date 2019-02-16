#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

int main() {
	string input1, input2, input3, input4;
	cin >> input1 >> input2 >> input3 >> input4;
	char Day[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int len1 = min(input1.length(), input2.length());
	int flag = 1;
	for (int i = 0; i < len1; i++) {
		if (flag&&input1[i] == input2[i] && isupper(input1[i]) && input1[i] <= 'G') {
			printf("%s ", Day[input1[i] - 'A']);
			flag = 0;
		}
		else if (!flag && input1[i] == input2[i]) {
			if (isdigit(input1[i])) {
				printf("%02d:", input1[i] - '0');
				break;
			}
			else if (isupper(input1[i]) && input1[i] <= 'N') {
				printf("%02d:", input1[i] - 'A' + 10);
				break;
			}
		}
	}
	int len2 = min(input3.length(), input4.length());
	for (int j = 0; j < len2; j++) {
		if (input3[j] == input4[j] && isalpha(input3[j])) {
			printf("%02d", j);
			break;
		}
	}
	return 0;
}