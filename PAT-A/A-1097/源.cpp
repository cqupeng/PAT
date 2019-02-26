#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int value, pre,add, next;
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
		if (next != -1) link[next].pre = add;
	}
	link[root].pre = root;
	int tempadd = root;
	vector<node> remove;
	unordered_map<int, int> hash;
	while (tempadd != -1) {
		int tempvalue = link[tempadd].value;
		if (hash[abs(tempvalue)] == 0) {
			hash[abs(tempvalue)]++;
		}
		else {
			link[link[tempadd].pre].next = link[tempadd].next;
			if(link[tempadd].next!=-1) link[link[tempadd].next].pre = link[tempadd].pre;
			remove.push_back(link[tempadd]);
		}
		tempadd = link[tempadd].next;
	}
	printf("%05d %d ", root, link[root].value);
	root = link[root].next;
	while (root != -1) {
		printf("%05d\n%05d %d ", root,root, link[root].value);
		root = link[root].next;
	}
	printf("-1\n");
	for (auto it = remove.begin(); it != remove.end(); it++) {
		if (it == remove.begin())
			printf("%05d %d ", it->add, it->value);
		else printf("%05d\n%05d %d ", it->add, it->add, it->value);
	}
	if(remove.size()!=0) printf("-1\n");
	return 0;
}