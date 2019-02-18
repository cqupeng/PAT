#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
struct node {
	int e;
	double c;
};
int main() {
	vector<node> input;
	int k;
	scanf("%d", &k);
	int temp_e, max_e = 0;
	double temp_c;
	node temp_node;
	map<int, double> poly;
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &temp_e, &temp_c);
		temp_node.e = temp_e;
		temp_node.c = temp_c;
		input.push_back(temp_node);
	}
	scanf("%d", &k);
	int len = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &temp_e, &temp_c);
		for (auto it = input.begin(); it != input.end(); it++){
			int flag=1;
			int new_e = it->e + temp_e;
			if (poly[new_e] == 0) flag = 0;
			poly[new_e] += temp_c * it->c;
			max_e = max_e > new_e ? max_e : new_e;
			if (flag == 1 && poly[new_e] == 0.0) len--;
			else if (flag == 0 && poly[new_e] != 0.0) len++;
		}
	}
	printf("%d", len);
	if (len == 0) printf("0");
	for (int i = max_e; i >= 0; i--) {
		if (poly[i] != 0) printf(" %d %.1lf", i, poly[i]);
	}
	return 0;
}