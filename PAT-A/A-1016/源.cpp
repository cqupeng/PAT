#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
struct record {
	string time, state;
};
bool cmp(record A, record B) {
	return A.time < B.time;
}
int main() {
	int charge[24];
	for (int i = 0; i < 24; i++) cin >> charge[i];
	int N;
	cin >> N;
	map<string, vector<record> > customer;
	for (int i = 0; i < N; i++) {
		string name;
		record temp;
		cin >> name >> temp.time >> temp.state;
		customer[name].push_back(temp);
	}
	for (auto it = customer.begin(); it != customer.end(); it++) {
		int flag = 1;
		sort(it->second.begin(), it->second.end(), cmp);
		double sum = 0;
		record pre_record;
		for (auto it_record = it->second.begin(); it_record != it->second.end(); it_record++) {
			if (it_record == it->second.begin()) pre_record = *it_record;
			else {
				if (pre_record.state == "on-line"&&it_record->state == "off-line") {
					if (flag) {
						printf("%s %s\n", it->first.c_str(), it->second[0].time.substr(0, 2).c_str());
						flag = 0;
					}
					int temptime = 0, tempcharge=0;
					int d1, h1, m1, d2, h2, m2;
					sscanf(pre_record.time.substr(3,8).c_str(), "%d:%d:%d", &d1, &h1, &m1);
					sscanf(it_record->time.substr(3,8).c_str(), "%d:%d:%d", &d2, &h2, &m2);
					while (d1 < d2 || h1 < h2 || m1 < m2) {
						m1++;
						temptime++;
						tempcharge += charge[h1];
						if (m1 == 60) {
							h1++;
							m1 = 0;
							if (h1 == 24) {
								d1++;
								h1 = 0;
							}
						}
					}
					printf("%s %s %d $%.2lf\n", pre_record.time.substr(3, 8).c_str(), it_record->time.substr(3,8).c_str(), temptime, (double)tempcharge / 100);
					sum += tempcharge;
				}
				pre_record = *it_record;
			}
		}
		if(flag==0) printf("Total amount: $%.2lf\n", sum/100);
	}
	return 0;
}