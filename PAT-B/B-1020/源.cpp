#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct YueBing {
	double number, value;
	double num_val;
	YueBing() {}
	YueBing(double _n, double _v, double n_v) {
		number = _n;
		value = _v;
		num_val = n_v;
	}
	friend bool operator < (YueBing A, YueBing B) {
		return A.num_val > B.num_val;
	}
};
int main () {
	int N,need_num;
	scanf("%d %d", &N, &need_num);
	vector<YueBing> input;
	for (int i = 0; i < N; i++) {
		YueBing temp;
		input.push_back(temp);
		scanf("%lf", &input[i].number);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lf", &input[i].value);
		input[i].num_val = input[i].value / input[i].number;
	}
	sort(input.begin(), input.end());
	double sum = 0;
	auto it = input.begin();
	while (need_num != 0&&it!=input.end()) {
		if (need_num < it->number) {
			sum += need_num * it->num_val;
			break;
		}
		else {
			sum += it->value;
			need_num -= it->number;
			it++;
		}
	}
	printf("%.02lf", sum);
	return 0;
}
