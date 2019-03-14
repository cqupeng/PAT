//Ê÷×´Êý×éGG
#include<string>
#include<stdio.h>
#include<set>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	stack<int> input;
	int record[100011] = { 0 };
	for (int i = 0; i < N; i++) {
		string temp;
		temp.resize(12);
		scanf("%s", &temp[0]);
		if (temp[1] == 'o') {
			if (input.empty()) printf("Invalid\n");
			else {
				printf("%d\n", input.top());
				record[input.top()]--;
				input.pop();
			}
		}
		else if (temp[1] == 'u') {
			int num;
			scanf("%d", &num);
			input.push(num);
			record[num]++;
		}
		else {
			int cnt = 0, len = input.size();
			if (len == 0) printf("Invalid\n");
			else {
				if (len % 2 == 1) len++;
				len /= 2;
				for (int j = lower_bound(record,record+100001,1)-record; j < 100001; j++) {
					if (record[j] + cnt >= len) {
						printf("%d\n", j);
						break;
					}
					else cnt += record[j];
				}
			}
		}
	}
	return 0;
}