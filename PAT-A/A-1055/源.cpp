#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct people {
	string name;
	int age, value;
}input[100011];
bool cmp(people a, people b) {
	if (a.value != b.value) return a.value > b.value;
	else if (a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		string name;
		name.resize(10);
		int age, w;
		scanf("%s %d %d", &name[0], &age, &w);
		input[i] = people{ name,age,w };
	}
	sort(input, input + N, cmp);
	for (int i = 1; i <= K; i++) {
		printf("Case #%d:\n",i);
		int M, minage, maxage;
		scanf("%d %d %d", &M, &minage, &maxage);
		int cnt = 0;
		for (int j = 0; j < N&&cnt<M; j++) {
			if (input[j].age >= minage && input[j].age <= maxage) {
				printf("%s %d %d\n", input[j].name.c_str(), input[j].age, input[j].value);
				cnt++;
			}
		}
		if (cnt == 0) printf("None\n");
	}
	return 0;
}