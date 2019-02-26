#include<stdio.h>
#include<string>
#include<unordered_map>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct record {
	string plate;
	int time;
	string state;
	int flag = 0;
};
bool cmp_plate(record A, record B) {
	if (A.flag != B.flag) return A.flag > B.flag;
	if (A.plate != B.plate) return A.plate < B.plate;
	else return A.time < B.time;
}
bool cmp_time(record A, record B) {
	if (A.flag != B.flag) return A.flag > B.flag;
	else return A.time < B.time;
}
int main() {
	int N, K;
	vector<record> input;
	scanf("%d %d", &N, &K);
	int maxtime=0;
	unordered_map<string, int> stay_time;
	map<int, int> cnt;
	set<string> output;
	for (int i = 0; i < N; i++) {
		record temp;
		char plate[8];
		int hh, mm, ss;
		char state[4];
		scanf("%s %d:%d:%d %s", plate, &hh, &mm, &ss, state);
		temp.plate = plate;
		temp.time = hh * 3600 + mm * 60 + ss;
		temp.state = state;
		input.push_back(temp);
	}
	sort(input.begin(), input.end(), cmp_plate);
	int pre = 0, now = 1;
	while (pre < N&&now < N) {
		if (input[pre].plate == input[now].plate&&input[pre].state=="in"&&input[now].state=="out") {
			input[pre].flag = 1;
			input[now].flag = 1;
			stay_time[input[now].plate] += input[now].time - input[pre].time;
			int dif_time = stay_time[input[now].plate];
			if (dif_time > maxtime) {
				maxtime = dif_time;
				output.clear();
				output.insert(input[now].plate);
			}
			else if (dif_time == maxtime) output.insert(input[now].plate);
			pre += 2;
			now += 2;
		}
		else {
			pre++;
			now++;
		}
	}
	sort(input.begin(), input.end(), cmp_time);
	int i = 0, tempcnt=0;
	while (input[i].flag&&i<N) {
		if (input[i].state == "in") {
			tempcnt++;
			cnt[input[i].time]=tempcnt;
		}
		else if (input[i].state == "out") {
			tempcnt--;
			cnt[input[i].time] = tempcnt;
		}
		i++;
	}
	auto it = cnt.begin();
	for (int j = 0; j < K; j++) {
		int hh, mm, ss, time;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = hh * 3600 + mm * 60 + ss;
		while (it->first <= time&&it!=cnt.end()) it++;
		if (it == cnt.begin()) printf("0\n");
		else {
			it--;
			printf("%d\n", it->second);
		}
	}
	for (auto it_1 = output.begin(); it_1 != output.end(); it_1++)
		printf("%s ", (*it_1).c_str());
	printf("%02d:%02d:%02d", maxtime / 3600,  maxtime % 3600 / 60, maxtime % 60);
	return 0;
}