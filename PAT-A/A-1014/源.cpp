#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct customer {
	int id, pro_time, done_time;
};
int N, M, K, Q;
vector<queue<int> > window(21);
vector<customer> people;
int checkline(int nowtime) {
	int minque = 0, minpeople = M + 1;
	for (int i = 1; i <= N; i++) {
		if (!window[i].empty() && people[window[i].front()].done_time == nowtime) {
			window[i].pop();
		}
	}
	for (int i = 1; i <= N; i++) {
		if (window[i].size() != M && window[i].size() < minpeople) {
			minpeople = window[i].size();
			minque = i;
		}
	}
	return minque;
}
int main() {
	queue<int> allline;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 0; i < K; i++) {
		customer temp;
		temp.id = i;
		scanf("%d", &temp.pro_time);
		allline.push(i);
		people.push_back(temp);
	}
	int nowtime = 0;
	while (nowtime <= 540) {
		int nowline = checkline(nowtime);
		if (nowline && !allline.empty()) {
			int tempid = allline.front();
			allline.pop();
			//进队时即确定好结束时间
			if (window[nowline].empty()) people[tempid].done_time = nowtime + people[tempid].pro_time;
			else people[tempid].done_time = people[window[nowline].front()].done_time + people[tempid].pro_time;
			window[nowline].push(tempid);
		}
		else nowtime++;
	}
	for (int i = 0; i < Q; i++) {
		int checkid;
		scanf("%d", &checkid);
		int donetime = people[checkid - 1].done_time;
		if (people[checkid-1].done_time-people[checkid-1].pro_time > 540) printf("Sorry\n");
		else printf("%02d:%02d\n", 8 + donetime / 60, donetime % 60);
	}
	return 0;
}