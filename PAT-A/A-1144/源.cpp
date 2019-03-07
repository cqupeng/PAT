#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N, temp, cnt = 1;
	scanf("%d", &N);
	vector<int> input;
	bool record[100001] = { 0 };
	input.push_back(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp > 0 && temp <= N&&record[temp]==0) {
			input.push_back(temp);
			record[temp] = 1;
			cnt++;
		}
	}
	sort(input.begin(), input.end());
	int left = 0, right = cnt-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (input[mid] == mid) left = mid + 1;
		else right = mid - 1;
	}
	printf("%d", left);
	return 0;
}