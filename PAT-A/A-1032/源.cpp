#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
struct node {
	char value;
	string next;
};
unordered_map<string, node> input;
int getlen(string root) {
	int len = 0;
	while (root != "-1") {
		len++;
		root = input[root].next;
	}
	return len;
}
int main() {
	string link_1, link_2;
	int n;
	cin >> link_1 >> link_2 >> n;
	for (int i = 0; i < n; i++) {
		node temp;
		string add;
		cin >> add;
		getchar();
		cin >> temp.value >> temp.next;
		input[add] = temp;
	}
	int len1 = getlen(link_1);
	int len2 = getlen(link_2);
	if (len1 < len2) {
		swap(link_1, link_2);
		swap(len1, len2);
	}
	string newlink_1=link_1;
	for (int i = 0; i + len2 < len1; i++) {
		newlink_1 = input[newlink_1].next;
	}
	string result = newlink_1;
	while (newlink_1 != link_2&&newlink_1!="-1"&&link_2!="-1") {
		newlink_1 = input[newlink_1].next;
		link_2 = input[link_2].next;
	}
	printf("%s", newlink_1.c_str());
	return 0;
}