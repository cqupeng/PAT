#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
struct student {
	string name;
	int Gp=-1, Gmid=-1, Gfinal=-1, G=-1;
}input[11111];
bool cmp(student a, student b) {
	if (a.G != b.G) return a.G > b.G;
	else return a.name < b.name;
}
int main() {
	ios::sync_with_stdio(false);
	int p, m, n;
	cin >> p >> m >> n;
	string name;
	int temp_G;
	unordered_map<string, int> getid;
	for (int i = 1; i <= p; i++) {
		cin >> name >> temp_G;
		input[i] = { name,temp_G };
		getid[name] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> name >> temp_G;
		int id = getid[name];
		if (id != 0) input[id].Gmid = temp_G;
	}
	for (int i = 0; i < n; i++) {
		cin >> name >> temp_G;
		int id = getid[name];
		if (id != 0) {
			input[id].Gfinal = temp_G;
			if (input[id].Gmid > temp_G) {
				input[id].G = (int)round((double)input[id].Gmid*0.4 + (double)input[id].Gfinal*0.6);
			}
			else input[id].G = temp_G;
		}
	}
	sort(input, input + p + 1,cmp);
	int i = 0;
	while (input[i].Gp >= 200&&input[i].G>=60) {
		cout << input[i].name << ' ' << input[i].Gp << ' ';
		cout<< input[i].Gmid << ' ' << input[i].Gfinal << ' ' << input[i].G << '\n';
		i++;
	}
	return 0;
}