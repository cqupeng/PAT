#include<stdio.h>
#include<set>
using namespace std;
struct node {
	int value, cnt;
	friend bool operator <(node a, node b) {
		if (a.cnt != b.cnt) return a.cnt > b.cnt;
		else return a.value < b.value;
	}
};
int num[51111] = { 0 };
int main()
{
	int N, k;
	scanf("%d%d", &N, &k);
	set<node> input;
	for (int i = 0; i < N; i++)
	{
		int now;
		scanf("%d", &now);
		if (i != 0) {
			printf("%d:", now);
			int cnt = 0;
			for (auto it = input.begin(); it != input.end() && cnt < k; it++) {
				printf(" %d", it->value);
				cnt++;
			}
			printf("\n");
		}
		node temp;
		temp.value = now;
		temp.cnt = num[now];
		auto it = input.find(temp);
		if (it != input.end())	input.erase(it);
		num[now]++;
		temp.cnt++;
		input.insert(temp);
	}
	return 0;
}
