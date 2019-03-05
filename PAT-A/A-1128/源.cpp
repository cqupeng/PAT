#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		vector<int> v(n);
		bool result = true;
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[j]);
			for (int t = 0; t < j; t++) {
				if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t)) {
					result = false;
					break;
				}
			}
		}
		if (result) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}