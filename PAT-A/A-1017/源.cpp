#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct customer {
	int arrive_time, pro_time;
	friend bool operator < (customer A, customer B) {
		return A.arrive_time < B.arrive_time;
	}
};
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<customer> input;
	for (int i = 0; i < N; i++) {
		int h, m, s, pro;
		scanf("%d:%d:%d %d", &h, &m, &s, &pro);
		customer temp;
		temp.arrive_time = h * 3600 + m * 60 + s;
		temp.pro_time = pro*60;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	int windows[101];
	fill(windows, windows + 101, 8 * 3600);
	int sum_time = 0, sum_customer = 0;
	for (auto it = input.begin(); it != input.end(); it++) {
		int free_windows = 0, min_free_time = 1000000;
		for (int i = 0; i < M; i++) {
			if (windows[i] < min_free_time) {
				min_free_time = windows[i];
				free_windows = i;
			}
		}
		if (it->arrive_time >= 17 * 3600) break;
		sum_customer++;
		int temp_pro = it->pro_time > 3600 ? 3600 : it->pro_time;
		if (windows[free_windows] < it->arrive_time) {
			windows[free_windows] = it->arrive_time + it->pro_time;
		}
		else {
			int temp_arrive = it->arrive_time < 8 * 3600 ? 8 * 3600 : it->arrive_time;
			sum_time += windows[free_windows] - it->arrive_time;
			windows[free_windows] += temp_pro;
		}
	}
	if (sum_customer == 0) printf("0.0");
	else printf("%.1lf", (double)sum_time / 60 / sum_customer);
	return 0;
}