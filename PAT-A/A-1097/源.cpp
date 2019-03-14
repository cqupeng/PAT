#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int value, add, next;
};
node link[111111];
int main() {
	int root, N;
	scanf("%d%d", &root, &N);
	for (int i = 0; i < N; i++) {
		int value, add, next;
		scanf("%d %d %d", &add, &value, &next);
		link[add].add = add;
		link[add].value = value;
		link[add].next = next;
	}
	int tempadd = root;
	vector<node> remove;
	unordered_map<int, int> hash;
	vector<node> ans;
	while (tempadd != -1) {
		int tempvalue = link[tempadd].value;
		if (hash[abs(tempvalue)] == 0) {
			ans.push_back(link[tempadd]);
			hash[abs(tempvalue)]++;
		}
		else remove.push_back(link[tempadd]);
		tempadd = link[tempadd].next;
	}
	if (ans.size() != 0) {
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (it == ans.begin()) printf("%05d %d ", it->add, it->value);
			else printf("%05d\n%05d %d ", it->add, it->add, it->value);
		}
		printf("-1\n");
	}
	for (auto it = remove.begin(); it != remove.end(); it++) {
		if (it == remove.begin())
			printf("%05d %d ", it->add, it->value);
		else printf("%05d\n%05d %d ", it->add, it->add, it->value);
	}
	if(remove.size()!=0) printf("-1\n");
	return 0;
}