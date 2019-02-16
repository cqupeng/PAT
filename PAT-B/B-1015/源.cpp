#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct student {
	int number,Moral, Ability, sum;
	student(int _n, int _M, int _A, int _sum) {
		number = _n;
		Moral = _M;
		Ability = _A;
		sum = _sum;
	}
	friend bool operator < (student num1, student num2) {
		if (num1.sum != num2.sum) return num1.sum > num2.sum;
		else if (num1.Moral != num2.Moral) return num1.Moral > num2.Moral;
		else return num1.number < num2.number;
	}
};
int main() {
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
	vector<student> lever[4];
	int PassNum = 0;
	for (int i = 0; i < N; i++) {
		int tempnum, tempM, tempA;
		scanf("%d %d %d", &tempnum, &tempM, &tempA);
		student tempStudent(tempnum,tempM,tempA,tempM+tempA);
		if (tempM < L || tempA < L) continue;
		PassNum++;
		if (tempM >= H && tempA >= H) lever[0].push_back(tempStudent);
		else if (tempM >= H && tempA < H) lever[1].push_back(tempStudent);
		else if (tempM < H&&tempA < H&&tempM >= tempA) lever[2].push_back(tempStudent);
		else lever[3].push_back(tempStudent);
	}
	printf("%d\n", PassNum);
	for (int i = 0; i < 4; i++) {
		sort(lever[i].begin(), lever[i].end());
		for (auto it = lever[i].begin(); it != lever[i].end(); it++) {
			printf("%8d %d %d\n", it->number, it->Moral, it->Ability);
		}
	}
	return 0;
}