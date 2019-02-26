#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> ori, res;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		ori.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		res.push_back(temp);
	}
	vector<int> temp_ori = ori;
	int flag = 0;
	for (int i = 1; i < N; i++) {
		sort(temp_ori.begin(), temp_ori.begin() + i);
		if (temp_ori == res) {
			printf("Insertion Sort\n");
			flag = 1;
			sort(res.begin(), res.begin() + min(i + 1,N));
			break;
		}
	}
	if (flag == 0) {
		sort(temp_ori.begin(), temp_ori.end());
		int i;
		for (i = N - 1; i >= 0; i--) {
			if (temp_ori[i] != res[i]) break;
		}
		swap(res[i], res[0]);
		int root = 0;
		while (root*2+1 < i||root*2+2<i) {
			if (root * 2 + 2 < i) {
				int temp = res[root * 2 + 1] > res[root * 2 + 2] ? (root * 2 + 1) : (root * 2 + 2);
				if (res[root] > res[temp]) break;
				else {
					swap(res[root], res[temp]);
					root = temp;
				}
			}
			else if ((root * 2 + 1 < i) && res[root] < res[root * 2 + 1]) {
				swap(res[root], res[root * 2 + 1]);
				root = root * 2 + 1;
			}
			else break;
		}
		printf("Heap Sort\n");
	}
	printf("%d", res[0]);
	for (int i = 1; i < N; i++) printf(" %d", res[i]);
	return 0;
}