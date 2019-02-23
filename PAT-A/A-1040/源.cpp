#include<string.h>
#include<stdio.h>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	char input[1011];
	unordered_map<char, vector<int> > ch;
	int len = 0;
	char temp=getchar();
	while (temp != '\n') {
		input[len] = temp;
		ch[temp].push_back(len);
		len++;
		temp = getchar();
	}
	int maxlen = 1;
	for (int i = 0; i < len&&i+maxlen<len; i++) {
		int end = -1, charlen = ch[input[i]].size();
		for (auto j=0; j<charlen; j++) {
			if (ch[input[i]][j] > i) {
				end = ch[input[i]][j];
				char temp[1011];
				strcpy(temp, input);
				reverse(temp + i, temp + end+1);
				if (strcmp(temp, input) == 0 && end - i + 1 > maxlen)
					maxlen = end - i + 1;
			}
		}
	}
	printf("%d", maxlen);
	return 0;
}