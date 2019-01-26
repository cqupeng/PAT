#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	getchar();	
	while (n--) {
		string input;
		getline(cin, input);
		int P_pos=-1, T_pos=input.length(),flag=1;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			if (input[i] == 'P') P_pos = i;
			else if (input[i] == 'T') T_pos = i;
			else if (input[i] == 'A');
			else {
				flag = 0;
				break;
			}
		}
		int a = P_pos, b = T_pos - P_pos-1, c = len - T_pos-1;
		if (b<1||c != b * a || P_pos == -1 || T_pos == len) flag = 0;
		if (flag == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
