#include<stdio.h>
#include<string.h>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct card {
	char level;
	char str[20];
	int site, date, testee;
	int score;
};
struct site_info {
	int site;
	int cnt = 0;
};
bool cmp_1(card a, card b) {
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.str,b.str)<0;
}
bool cmp_2(site_info a, site_info b) {
	if (a.cnt != b.cnt) return a.cnt > b.cnt;
	else return a.site < b.site;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<card> input;
	for (int i = 0; i < N; i++) {
		char str_temp[20];
		int score;
		scanf("%s %d", str_temp, &score);
		card temp;
		sscanf(str_temp, "%c%3d%6d%3d", &temp.level, &temp.site, &temp.date, &temp.testee);
		temp.score = score;
		strcpy(temp.str, str_temp);
		input.push_back(temp);
	}
	sort(input.begin(), input.end(), cmp_1);
	for (int i = 1; i <= M; i++) {
		int type;
		char term_temp[20];
		scanf("%d %s", &type,term_temp);
		printf("Case %d: %d %s\n", i, type, term_temp);
		int flag = 0;
		if (type == 1) {
			for (auto it = input.begin(); it != input.end(); it++) {
				if (it->level == term_temp[0]) {
					flag = 1;
					printf("%s %d\n", it->str, it->score);
				}
			}
		}
		else if (type == 2) {
			int num = 0, total_score = 0;
			int term;
			sscanf(term_temp, "%d", &term);
			for (auto it = input.begin(); it != input.end(); it++) {
				if (it->site == term) {
					flag = 1;
					num++;
					total_score += it->score;
				}
			}
			if (flag)
				printf("%d %d\n", num, total_score);
		}
		else {
			unordered_map<int, int> site_i;
			vector<site_info> site_num;
			int term;
			sscanf(term_temp, "%d", &term);
			for (auto it = input.begin(); it != input.end(); it++) {
				if (it->date == term) {
					flag = 1;
					if (site_i[it->site] == 0) {
						site_i[it->site] = site_num.size() + 1;
						site_info temp;
						temp.site = it->site;
						temp.cnt++;
						site_num.push_back(temp);
					}
					else {
						site_num[site_i[it->site] - 1].cnt++;
					}
				}
			}
			sort(site_num.begin(), site_num.end(), cmp_2);
			for (auto it = site_num.begin(); it != site_num.end(); it++) {
				printf("%03d %d\n", it->site, it->cnt);
			}
		}
		if (flag == 0) printf("NA\n");
	}
	return 0;
}
