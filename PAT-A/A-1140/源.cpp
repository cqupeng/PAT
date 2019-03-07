#include<stdio.h>
#include<string>
using namespace std;
int main() {
	int d, N;
	scanf("%d %d", &d, &N);
	string ans = to_string(d);
	while (--N) {
		string temp;
		char pre, cnt;
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (it == ans.begin()) {
				pre = *it;
				cnt = '1';
			}
			else if (*it != pre) {
				temp.push_back(pre);
				temp.push_back(cnt);
				pre = *it;
				cnt = '1';
			}
			else cnt++;
		}
		temp.push_back(pre);
		temp.push_back(cnt);
		ans = temp;
	}
	printf("%s", ans.c_str());
	return 0;
}